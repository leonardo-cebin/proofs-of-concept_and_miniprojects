/* O propósito deste código é verificar se o componente de hardware, o sensor ultrasônico, está operante e devidamente conectado,
fazemos uma medida e calibração dele neste código

Nós tivemos a necessidade de executar este código antes de entregar o projeto, pois haviam suspeitas de que o sensor pudesse estar danificado. Através deste código,
verificamos que de fato o sensor estava operante e configurado. */

int triggerPin = 6;  // Trigger pin
int echoPin = 7;     // Echo pin
long duration;
int distance;

// Favor verificar os fios conectados!!!

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Envia um pulso para o sensor
  digitalWrite(triggerPin, LOW); // Ensure trigger is low
  delayMicroseconds(2);          // Wait for a short time
  digitalWrite(triggerPin, HIGH); // Send trigger pulse
  delayMicroseconds(10);         // Pulse length
  digitalWrite(triggerPin, LOW);  // End the pulse

  // Mede o pulso gerado
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros (som = 343 m/s)
  distance = duration * 0.034 / 2; 
  // 34 cm por nanosegundo

  // Imprime o valor como saída do terminal
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Delay de meio segundo entre medições, altere o valor para aumentar ou diminuir o intervalo
}
