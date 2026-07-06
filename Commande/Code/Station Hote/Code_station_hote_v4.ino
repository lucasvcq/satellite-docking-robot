const int stepPin = 13;
const int dirPin = 12;
const int nbre_steps=200;
#define borneENA        10      // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneIN1        9       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino
#define borneIN2        8       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino
#define borneIN3        7       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino
#define borneIN4        6       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino
#define borneENB        5       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino
#define borneENC        4
#define borneIN5        3
#define borneIN6        2

bool loopExecuted = false;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);
  pinMode(borneIN5, OUTPUT);
  pinMode(borneIN6, OUTPUT);
  pinMode(borneENC, OUTPUT);

  // Démarrage des moteurs
}

void loop() {
  if (!loopExecuted){ 
    ////On fait 2 pas pour eviter qu'il fasse n'importe quoi////
    digitalWrite(dirPin, HIGH); // oriente le moteur dans le sens horaire
 
    for (int i = 0; i < 2; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(100);
    //on active le pas à pas pour désengrener
    digitalWrite(dirPin, HIGH); // oriente le moteur dans le sens antihoraire
 
    for (int i = 0; i < 100; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(5000);

    /////On active les moteur du verrouaillage/////
    // Réglage des vitesses différentes pour les deux moteurs
    motorForward();
    setMotorSpeeds(240, 255);  // Vitesse pour moteur A et moteur B respectivement
    delay(210);               // Maintient la vitesse pendant 5 secondes

    // Arrête les moteurs après l'exécution
    motorStop();
    delay(2000);

    motorForward();
    setMotorSpeeds(240, 255);  // Vitesse pour moteur A et moteur B respectivement
    delay(40);

    motorStop();
    delay(5000);
    
    /////FIN PARTIE 1//////


    ////On fait le trucs pour etre sur que le crabaut engrene bien////
    for (int i = 0; i < 30; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }

    digitalWrite(borneIN5, LOW);
    digitalWrite(borneIN6, HIGH);
    lancerRotationMoteurPontC();
 
    for (int i = 0; i < 70; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(1000);
    }
    delay(5000);

    ////On fait tourner le pololu pour ramener le mini-robot////
    digitalWrite(borneIN5, LOW);
    digitalWrite(borneIN6, HIGH);
    lancerRotationMoteurPontC_2();
    delay(5000);

    ////On fait tourner le pololu dans l'autre sens pour donner du mou////
    digitalWrite(borneIN5, HIGH);
    digitalWrite(borneIN6, LOW);
    lancerRotationMoteurPontC_3();
    delay(5000);
    loopExecuted = true;
  }
}

void setMotorSpeeds(int speedA, int speedB) {
  // Limite les vitesses entre 0 et 255
  speedA = constrain(speedA, 0, 255);
  speedB = constrain(speedB, 0, 255);
  
  // Définit les vitesses pour les deux moteurs
  analogWrite(borneENA, speedA);
  analogWrite(borneENB, speedB);
}

void motorForward() {
  // Définit les moteurs pour tourner en avant
  digitalWrite(borneIN1, HIGH);
  digitalWrite(borneIN2, LOW);
  digitalWrite(borneIN3, HIGH);
  digitalWrite(borneIN4, LOW);
}

void motorBackward() {
  // Définit les moteurs pour tourner en arrière
  digitalWrite(borneIN1, LOW);
  digitalWrite(borneIN2, HIGH);
  digitalWrite(borneIN3, LOW);
  digitalWrite(borneIN4, HIGH);
}

void motorStop() {
  // Arrête les moteurs
  digitalWrite(borneIN1, LOW);
  digitalWrite(borneIN2, LOW);
  digitalWrite(borneIN3, LOW);
  digitalWrite(borneIN4, LOW);
}

void lancerRotationMoteurPontC() {
  digitalWrite(borneENC, HIGH);       
  delay(100);                        
  
  digitalWrite(borneENC, LOW);        
  delay(100);                        
}

void lancerRotationMoteurPontC_2() {
  digitalWrite(borneENC, HIGH);       
  delay(10000);                        
  
  digitalWrite(borneENC, LOW);        
  delay(1000);                        
}

void lancerRotationMoteurPontC_3() {
  digitalWrite(borneENC, HIGH);       
  delay(1000);                        
  
  digitalWrite(borneENC, LOW);        
  delay(1000);                        
}
