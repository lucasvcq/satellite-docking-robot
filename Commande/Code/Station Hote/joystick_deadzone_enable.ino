#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 200; // Nombre de pas par révolution du moteur pas à pas
const int rolePerMinute = 15; // Vitesse du moteur pas à pas en tr/min
const int joystickDeadzone = 20; // Zone morte du joystick
const int stepperEnablePin = 2; // Broche de contrôle de l'activation du moteur pas à pas

Stepper myStepper1(stepsPerRevolution, 4, 5); //pin 4 pour le step et 5 pour le dir
Servo myServo;

void setup() {
  myStepper1.setSpeed(rolePerMinute);
  pinMode(stepperEnablePin, OUTPUT);
  digitalWrite(stepperEnablePin, LOW); // Désactive le moteur pas à pas par défaut
  myServo.attach(9); // Attache le servomoteur au pin 9
}

void loop() {
  int xAxisValue = analogRead(A0);
  int yAxisValue = analogRead(A1);

  if (abs(xAxisValue - 512) > joystickDeadzone) {
    // Activer le moteur pas à pas
    digitalWrite(stepperEnablePin, HIGH);

    // Mouvement détecté sur l'axe X
    if (xAxisValue < 512) {
      // Mouvement à gauche
      myStepper1.setSpeed(rolePerMinute);
      myStepper1.step(-30);
    } else {
      // Mouvement à droite
      myStepper1.setSpeed(rolePerMinute);
      myStepper1.step(30);
    }
  } else {
    // Désactiver le moteur pas à pas
    digitalWrite(stepperEnablePin, LOW);
  }

  if (abs(yAxisValue - 512) > joystickDeadzone) {
    // Mouvement détecté sur l'axe Y
    if (yAxisValue < 512) {
      // Mouvement vers le bas
      myServo.write(0); // Déplacer le servomoteur vers la position minimale
    } else {
      // Mouvement vers le haut
      myServo.write(180); // Déplacer le servomoteur vers la position maximale
    }
  }
}
