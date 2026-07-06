#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 200;
const int rolePerMinute = 15;
Stepper myStepper1(stepsPerRevolution, 3, 2); //pin 3 pour le step et 2 pour le dir
Servo myServo;

void setup() {
  myStepper1.setSpeed(rolePerMinute);
  myServo.attach(9); // Attache le servomoteur au pin 9
}

void loop() {
  int a = analogRead(A0);
  if (a > 400 && a < 520) {
    for (int i = 2; i < 6; i++) {
      digitalWrite(i, HIGH);
    }
  }
  else if (a < 200) {
    myStepper1.setSpeed(rolePerMinute);
    myStepper1.step(-30);
  }
  else if (a > 600) {
    myStepper1.setSpeed(rolePerMinute);
    myStepper1.step(30);
  }

  int b = analogRead(A1);
  if (b > 400 && b < 520) {
    myServo.write(90); // Position neutre du servomoteur
  }
  else if (b < 300) {
    myServo.write(0); // Déplacer le servomoteur vers la position minimale
  }
  else if (b > 600) {
    myServo.write(180); // Déplacer le servomoteur vers la position maximale
  }
}
