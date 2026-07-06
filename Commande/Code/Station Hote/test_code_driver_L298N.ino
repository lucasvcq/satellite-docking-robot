int motorPin1 = 10;
int motorPin2 = 8;
int enablePin = 9;

void setup() {
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);
}

void loop() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);

  lancerRotationMoteurPontA();

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);

  lancerRotationMoteurPontA();
}

void lancerRotationMoteurPontA() {
  digitalWrite(enablePin, HIGH);       
  delay(2000);                        
  
  digitalWrite(enablePin, LOW);        
  delay(1000);                        
}
