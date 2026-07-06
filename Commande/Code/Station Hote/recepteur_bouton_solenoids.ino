#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Pas utilisé mais nécessaire pour la compilation
#endif

// Paramétrer le driver pour utiliser le GPIO 13 pour RX
RH_ASK driver(2000, 13, 12, 14); // fréquence, RX, TX, PTT – TX et PTT ne sont pas utilisés ici, 13 correspond au pin du récepteur

const int moteurPin = 8; // Définir le pin sur lequel le moteur solénoïde est connecté

void setup()
{
    Serial.begin(115200);    // Debugging only
    pinMode(moteurPin, OUTPUT); // Définir le pin du moteur solénoïde en sortie
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      String rcv;
      for (int i =0; i<buflen; i++){
        rcv += (char)buf[i];
      }
      Serial.println(rcv);

      if (rcv == "0") {
        // Activer le moteur solénoïde
        digitalWrite(moteurPin, HIGH);
        delay(100);
      }
    }
}
