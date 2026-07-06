#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600); // Initialise la communication série avec le moniteur série
  mySerial.begin(9600); // Initialise la communication série avec le port série virtuel
}

void loop() {

  String message = mySerial.readString(); 
  Serial.print("Message reçu sur le port série virtuel : ");
  Serial.println(message);
  delay(600);
}
