// Definición de pines para el L298N
const int IN1 = 2; // Pin IN1 del L298N
const int IN2 = 3; // Pin IN2 del L298N
const int IN3 = 4; // Pin IN3 del L298N
const int IN4 = 5; // Pin IN4 del L298N
const int ENA = 6; // Pin ENA para el motor izquierdo
const int ENB = 7; // Pin ENB para el motor derecho

// Definición de pines para el sensor ultrasónico
const int TRIG = 8; // Pin TRIG del HC-SR04
const int ECHO = 9; // Pin ECHO del HC-SR04

// Definición de pines para los sensores de línea
const int LINE_SENSOR_LEFT = 10;
const int LINE_SENSOR_RIGHT = 11;

// Variables para la medición de distancia
long duration;
int distance;

void setup() {
  // Configuración de pines para el L298N
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Configuración de pines para el sensor ultrasónico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Configuración de pines para los sensores de línea
  pinMode(LINE_SENSOR_LEFT, INPUT);
  pinMode(LINE_SENSOR_RIGHT, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Medir la distancia con el sensor ultrasónico
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.0344 / 2; // Convertir a cm
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Leer los sensores de línea
  bool lineLeft = digitalRead(LINE_SENSOR_LEFT);
  bool lineRight = digitalRead(LINE_SENSOR_RIGHT);

  // Comportamiento basado en la distancia y los sensores de línea
  if (distance < 15) { // Si un objeto está demasiado cerca
    stopMotors();
    delay(1000); // Esperar un segundo
    reverse(); // Moverse hacia atrás
    delay(1000); // Esperar un segundo
    stopMotors();
  } else if (lineLeft && lineRight) { // Si ambos sensores detectan línea
    stopMotors();
    delay(500);
    rotateRight(); // Girar a la derecha
  } else if (lineLeft) { // Si solo el sensor izquierdo detecta línea
    turnRight(); // Girar a la derecha
  } else if (lineRight) { // Si solo el sensor derecho detecta línea
    turnLeft(); // Girar a la izquierda
  } else { // Si no se detecta línea
    moveForward(); // Avanzar
  }
}

// Funciones para controlar los motores

void moveForward() {//Ir hacia delante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Velocidad máxima
  analogWrite(ENB, 255); // Velocidad máxima
}

void reverse() {//Ir hacia atras
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);//Velocidad máxima
  analogWrite(ENB, 255);//Velocidad máxima
}

void turnLeft() {//Girar a la izquierda
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);//Velocidad máxima
  analogWrite(ENB, 255);//Velocidad máxima
}

void turnRight() {//Girar a la derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);//Velocidad máxima
  analogWrite(ENB, 255);//Velocidad máxima
}

void rotateRight() {//Rotar a la derecha
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);//Velocidad máxima
  analogWrite(ENB, 255);//Velocidad máxima
}

void stopMotors() {//Detener motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
