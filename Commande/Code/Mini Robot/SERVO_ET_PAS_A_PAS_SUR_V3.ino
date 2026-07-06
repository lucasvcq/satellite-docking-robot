#include <Servo.h>
#include <RH_ASK.h>

#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Nécessaire pour la compilation
#endif

RH_ASK driver(2000, 9, 4, 14); // Fréquence, RX, TX, PTT – TX et PTT ne sont pas utilisés ici

const int stepPin = 2;
const int dirPin = 5;
int eje1 = 90; // Variable pour la position du servo
int b = 0;     // Variable pour déterminer la position équivalente du joystick
bool clockwise = true; // Variable pour déterminer la direction du moteur

Servo servo1;

void setup()
{
    Serial.begin(115200); // Pour le débogage uniquement
    if (!driver.init())
        Serial.println("init failed");

    servo1.attach(12);
    servo1.write(90);

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);






  if (driver.recv(buf, &buflen)) // Non bloquant
  {
    String rcv;
    for (int i = 0; i < buflen; i++)
    {
      rcv += (char)buf[i];
    }
    Serial.println(rcv);
    int b = rcv.toInt();
    digitalWrite(stepPin, LOW);
        if (b == 1)
        {
        digitalWrite(stepPin, LOW);
        eje1 += 5;
        if (eje1 > 180) eje1 = 180; // Limiter à l'angle maximum
        servo1.write(eje1);
        delay(50);
        }
        else if (b == 3)
        {
        digitalWrite(stepPin, LOW);
        eje1 -= 5;
        if (eje1 < 0) eje1 = 0; // Limiter à l'angle minimum
        servo1.write(eje1);
        delay(50);
        }
        else if (b == 4) 
        {
        digitalWrite(dirPin, HIGH); // Sens horaire

        for (int t=0; t<10; t++){
        // Générer les impulsions pour faire tourner le moteur
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
        }

        digitalWrite(stepPin, HIGH);  
        //digitalWrite(stepPin, LOW);
        }
        else if (b == 2) 
        {
        digitalWrite(dirPin, LOW); // Sens antihoraire
        for (int t=0; t<10; t++){
        // Générer les impulsions pour faire tourner le moteur
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
      
        digitalWrite(stepPin, HIGH); 
        //digitalWrite(stepPin, LOW);
        }
        else
        {
        //digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
        }
         
  }
}
