# Abridor Automático de Portão

## Funcionamento
Neste projeto, implementei um sistema automático de cancela de pedágio/estacionamento. Detectando o carro usando um sensor ultrassônico, o Arduino envia instruções para o servo motor levantar a cancela. Este projeto foi elaborado para a disciplina de Técnicas e Desenvolvimento de Algoritmos, ministrada pelo professor José Luis Pagotto. O projeto foi apresentado no dia 12 de Novembro de 2024.

<br/><br/>
<p align="center">
<img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/ezgif-4-01eb3a081e.gif" alt="Animated .gif" width="650"></p><br/>

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

## Galeria de imagens

   <table align="center" cellpadding="10">
        <tr>
            <td><img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/20241112_211747.jpg" alt="Imagem 1" width="400"></td>
            <td><img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/20241112_211749.jpg" alt="Imagem 2" width="400"></td>
        </tr>
         <tr>
            <td colspan="2"><img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/20241112_211910.jpg" alt="Imagem 5" width="800"></td>
        </tr>
        <tr>
            <td><img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/20241112_211753.jpg" alt="Imagem 3" width="400"></td>
            <td><img src="https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/photos/20241112_211756.jpg" alt="Imagem 4" width="400"></td>
        </tr>
    </table><br/>

## Diagrama do Circuito:

![Screenshot (261)](https://github.com/leonardo-cebin/proofs-of-concept_and_miniprojects/blob/main/Arduino/Parking%20Toll%20Gate/diagram-arduino-tollgate.png?raw=true)

Esquemática da disposição das peças para o correto funcionamento do código.


