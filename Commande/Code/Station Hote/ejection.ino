// Définition des broches
const int ENA = 10;  // Broche PWM pour le moteur A
const int IN1 = 9;  // IN1 pour le moteur A
const int IN2 = 8;  // IN2 pour le moteur A
const int ENB = 5; // Broche PWM pour le moteur B
const int IN3 = 7;  // IN3 pour le moteur B
const int IN4 = 6;  // IN4 pour le moteur B

// Variable de contrôle pour vérifier si loop() a déjà été exécuté
bool loopExecuted = false;

void setup() {
  // Initialisation des broches
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Démarrage des moteurs
  motorForward();
}

void loop() {
  if (!loopExecuted) {
    // Réglage des vitesses différentes pour les deux moteurs
    setMotorSpeeds(240, 255);  // Vitesse pour moteur A et moteur B respectivement
    delay(1000);               // Maintient la vitesse pendant 5 secondes

    // Arrête les moteurs après l'exécution
    motorStop();
    //delay(2000);

    //setMotorSpeeds(240, 255);  // Vitesse pour moteur A et moteur B respectivement
    //delay(40);

    //motorStop();
    //delay(2000);
    // Marquer que la boucle a été exécutée
    loopExecuted = true;
  }
}

void setMotorSpeeds(int speedA, int speedB) {
  // Limite les vitesses entre 0 et 255
  speedA = constrain(speedA, 0, 255);
  speedB = constrain(speedB, 0, 255);
  
  // Définit les vitesses pour les deux moteurs
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void motorForward() {
  // Définit les moteurs pour tourner en avant
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motorBackward() {
  // Définit les moteurs pour tourner en arrière
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motorStop() {
  // Arrête les moteurs
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
