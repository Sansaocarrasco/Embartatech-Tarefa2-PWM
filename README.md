## 📌 Introdução

Este projeto implementa um sistema de controle PWM utilizando a placa BitDogLab e um servomotor, permitindo o ajuste preciso de sua posição através da modulação por largura de pulso (PWM). Além disso, um experimento com um LED RGB é realizado para análise do comportamento da iluminação.

## 🛠 Componentes Utilizados

A tarefa requer os seguintes componentes conectados à placa BitDogLab:

| Componente  | Conexão à GPIO |
|-------------|--------------|
| Servomotor  | GPIO 22      |
| LED RGB     | GPIO 12      |

## 💻 Simulação no Wokwi
A configuração sugerida para a simulação no Wokwi pode ser acessada no repositório abaixo:

https://wokwi.com/projects/422425391454372865

## 📌 Requisitos da Atividade

- Definir a frequência do sinal PWM na GPIO 22 para aproximadamente 50Hz (período de 20ms).
- Ajustar o Duty Cycle para 2.400µs (0,12%), posicionando o servomotor em 180 graus e manter por 5 segundos.
- Ajustar o Duty Cycle para 1.470µs (0,0735%), posicionando o servomotor em 90 graus e manter por 5 segundos.
- Ajustar o Duty Cycle para 500µs (0,025%), posicionando o servomotor em 0 graus e manter por 5 segundos.
- Implementar uma rotina de movimentação periódica do servomotor entre 0 e 180 graus com transições suaves, incrementando o ciclo ativo em ±5µs a cada 10ms.
- Realizar um experimento utilizando o LED RGB (GPIO 12) para observar seu comportamento durante a execução do código.

## 🌊 Instruções de Uso

1. Clone este repositório:

```sh
git clone https://github.com/Sansaocarrasco/Embarcatech-Tarefa2-PWM.git
```

2. Abra o projeto no VS Code.
3. Conecte a placa Raspberry Pi Pico W ao computador no modo BOOTSEL (pressionando o botão BOOTSEL ao conectar via USB).
4. Compile o arquivo `pwm_control.c` e carregue o projeto para a placa.

## 🎥 Vídeo Demonstrativo

O vídeo associado a esta prática pode ser acessado no link a seguir:

https://www.youtube.com/watch?v=g81hRWS8_QE

## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo `LICENSE` para mais detalhes.
