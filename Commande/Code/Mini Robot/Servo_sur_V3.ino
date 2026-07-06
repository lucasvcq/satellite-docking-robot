#include <Servo.h>
#include <RH_ASK.h>

#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Nécessaire pour la compilation
#endif

RH_ASK driver(2000, 13, 12, 14); // Fréquence, RX, TX, PTT – TX et PTT ne sont pas utilisés ici

Servo servo1;
int eje1 = 90;

void setup()
{
    Serial.begin(115200); // Pour le débogage uniquement
    if (!driver.init())
        Serial.println("init failed");

    servo1.attach(7);
    servo1.write(90);
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

        // Contrôler le servo en fonction de la valeur reçue
        if (b == 1)
        {
          eje1 += 5;
          if (eje1 > 180) eje1 = 180; // Limiter à l'angle maximum
          servo1.write(eje1);
          delay(50);
        }
        else if (b == 3)
        {
          eje1 -= 5;
          if (eje1 < 0) eje1 = 0; // Limiter à l'angle minimum
          servo1.write(eje1);
          delay(50);
        }
    }   
}