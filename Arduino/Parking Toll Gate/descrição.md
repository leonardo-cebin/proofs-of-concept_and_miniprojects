# Abridor Automático de Portão

## Funcionamento
Neste projeto, implementei um sistema automático de cancela de pedágio/estacionamento. Detectando o carro usando um sensor ultrassônico, o Arduino envia instruções para o servo motor levantar a cancela. Este projeto foi elaborado para a disciplina de Técnicas e Desenvolvimento de Algoritmos, ministrada pelo professor José Luis Pagotto.

## Componentes utilizados:
1. Arduino
2. Sensor Ultrassônico
3. Servo Motor
4. Breadboard

## Conexões do Circuito:

Sensor Ultrassônico  ----  Arduino

   - pino trigger  --- pino digital 6
   
   - pino echo     --- pino digital 7
   
   - Vcc           --- 5v 
   
   - Gnd           --- Gnd

Servo Motor 

   - sinal de controle do servo motor (LARANJA)  -----   Pino digital número 9 do Arduino 
   
   - Vcc do servo motor (VERMELHO)                  -----   5v do Arduino 
   
   - GND do servo motor (PRETO)                     -----   GND do Arduino

## Diagrama do Circuito:

![Screenshot (261)](https://github.com/neosandeep24/ArduinoExperiments/assets/103883917/c73c964d-4498-49f8-93dd-5aa18014e5b6)

Projeto Arduino
