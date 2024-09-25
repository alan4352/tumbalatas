int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int ENA = 6;
int ENB = 7;
int ECHO = 8;
int TRIG = 9;
int LINE_TRACKING_PIN = 10;
int intervalMoveLeft = 1000;
int previousMillis = 0;
bool movingLeft = false;

void setup() {
  //Inicia el Serial Port
  Serial.begin (9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}
 
void loop() {
	// send pulse.
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.0344 / 2; // Convertir a cm
	bool isWhite = digitalRead(LINE_TRACKING_PIN);

	if (distance <= 120) {
    forward();
		movingLeft = false;
    if (!isWhite) {
        stop();
        reverse();
        delay(500); 
        movingLeft = true;
        previousMillis = millis();
    };
  } else {
		if (!movingLeft) {
      moveLeft();
      movingLeft = true;
      previousMillis = millis();
		}
  }

  if (movingLeft) {
    if (millis() - previousMillis >= intervalMoveLeft) {
        movingLeft = false;
        stop();
    }
  }
}

void forward() {
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
}

void stop () {
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void reverse() {
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}

void moveLeft() {
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
}

void moveRight() {
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}
