#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_GPIO 22
#define LED_GPIO 12
#define PWM_FREQUENCY 50 // 50Hz -> Período de 20ms

void pwm_setup(uint gpio, uint16_t duty_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint wrap_value = 25000; // Definição manual para 50Hz (20ms de período)
    uint16_t level = (duty_us * wrap_value) / 20000; // Convertendo para escala de 20ms
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), level);
}

void led_brightness(uint16_t duty_us) {
    uint slice_num = pwm_gpio_to_slice_num(LED_GPIO);
    uint wrap_value = 25000;
    uint16_t level = (duty_us * wrap_value) / 2400; // Normalizando brilho baseado no servo
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(LED_GPIO), level);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_GPIO, GPIO_FUNC_PWM);
    gpio_set_function(LED_GPIO, GPIO_FUNC_PWM);
    
    uint slice_num_servo = pwm_gpio_to_slice_num(SERVO_GPIO);
    pwm_set_wrap(slice_num_servo, 25000); // Ajustando para 50Hz (1 ciclo = 20ms)
    pwm_set_clkdiv(slice_num_servo, 100.0f);
    pwm_set_enabled(slice_num_servo, true);
    
    uint slice_num_led = pwm_gpio_to_slice_num(LED_GPIO);
    pwm_set_wrap(slice_num_led, 25000);
    pwm_set_clkdiv(slice_num_led, 100.0f);
    pwm_set_enabled(slice_num_led, true);

    while (true) {
        // Posição 180 graus
        pwm_setup(SERVO_GPIO, 2400);
        led_brightness(2400);
        sleep_ms(5000);
        
        // Posição 90 graus
        pwm_setup(SERVO_GPIO, 1470);
        led_brightness(1470);
        sleep_ms(5000);
        
        // Posição 0 graus
        pwm_setup(SERVO_GPIO, 500);
        led_brightness(500);
        sleep_ms(5000);
        
        // Movimento suave entre 0 e 180 graus
        for (uint16_t duty = 500; duty <= 2400; duty += 5) {
            pwm_setup(SERVO_GPIO, duty);
            led_brightness(duty);
            sleep_ms(10);
        }
        for (uint16_t duty = 2400; duty >= 500; duty -= 5) {
            pwm_setup(SERVO_GPIO, duty);
            led_brightness(duty);
            sleep_ms(10);
        }
    }
}
