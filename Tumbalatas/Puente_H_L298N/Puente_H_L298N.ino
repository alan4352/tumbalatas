// Definición de pines para el L298N
const int IN1 = 2; // Pin IN1 del L298N
const int IN2 = 3; // Pin IN2 del L298N

void setup() {
  // Configurar los pines como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Inicializar el motor apagado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  // Girar el motor en una dirección
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000); // Girar en una dirección durante 2 segundos

  // Detener el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Detener durante 1 segundo

  // Girar el motor en la dirección opuesta
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000); // Girar en la dirección opuesta durante 2 segundos

  // Detener el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Detener durante 1 segundo
}
