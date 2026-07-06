#include <Servo.h> 

Servo moteur;   

int Axe_X = A2;
int servoVal;
 
void setup ()
{
  pinMode (Axe_X, INPUT);
 
  moteur.attach(6);   
}
 
void loop ()
{
    servoVal = analogRead (Axe_X);
    servoVal = map(servoVal, 0, 1023, 900, 2100);
    moteur.writeMicroseconds(servoVal);
    delay (30);
}

