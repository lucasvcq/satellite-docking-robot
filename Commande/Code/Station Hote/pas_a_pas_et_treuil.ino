const int stepPin = 49;
const int dirPin = 44;
const int nbre_steps=200;
int motorPin1 = 2;
int motorPin2 = 3;
int enablePin = 4;

bool loopExecuted = false;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);
}

void loop() {
  if (!loopExecuted){ 
    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < 2; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(10);
    for (int i = 0; i < 30; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    lancerRotationMoteurPontA();
 
    for (int i = 0; i < 70; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(5);
    loopExecuted = true;
  }
}

void lancerRotationMoteurPontA() {
  digitalWrite(enablePin, HIGH);       
  delay(100);                        
  
  digitalWrite(enablePin, LOW);        
  delay(100);                        
}
