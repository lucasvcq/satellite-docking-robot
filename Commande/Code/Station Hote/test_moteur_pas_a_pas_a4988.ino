const int stepPin = 2;
const int dirPin = 3;
const int nbre_steps=100;

void setup() {
  pinMode(stepPin, OUTPUT) ;
  pinMode(dirPin, OUTPUT);
}

void loop() {
  digitalWrite(dirPin, HIGH); // oriente le moteur dans le sens horaire
 
  for (int i = 0; i < nbre_steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
 
  digitalWrite(dirPin, LOW); // oriente le moteur dans le sens antihoraire
 
  for (int i = 0; i < nbre_steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
