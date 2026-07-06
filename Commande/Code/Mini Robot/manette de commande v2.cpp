#include <RH_ASK.h>
#include <SPI.h> 

// Define pins for the two transmitters
#define TX_PIN1 3
#define TX_PIN2 4
// Define pins for the two buttons (Button1 = bouton d'éjection, Button2 = bouton de retour)
#define BUTTON1_PIN 2
#define BUTTON2_PIN 5

#define joystick_X A0
#define joystick_Y A1

RH_ASK driver1(2000, TX_PIN1, -1, -1);  
RH_ASK driver2(2000, TX_PIN2, -1, -1);  

void setup() {

    Serial.begin(9600);    
    if (!driver1.init())
        Serial.println("Transmitter 1 init failed");
    if (!driver2.init())
        Serial.println("Transmitter 2 init failed");

    pinMode(BUTTON1_PIN, INPUT);    
    pinMode(BUTTON2_PIN, INPUT);   
}

void loop() {

    int xValue = analogRead(joystick_X);
    int yValue = analogRead(joystick_Y);
    int etat1 = digitalRead(BUTTON1_PIN);
    int etat2 = digitalRead(BUTTON2_PIN);

    const char *msg;

    //Serial.print("X: ");
    //Serial.println(xValue);
    //Serial.print("Y: ");
    //Serial.println(yValue);
    //Serial.println(etat1);
    //Serial.println(etat2);

    if (etat1 == HIGH){
        msg="5";
        envoie_driver2();
    } else if (etat2==HIGH){
        msg="6";
        envoie_driver2();
    }


    if (xValue < 300) {
        msg = "3";
        envoie_driver1();
    } else if (xValue > 700) {
        msg = "1";
        envoie_driver1();
    } else if (yValue < 300) {
        msg = "4";
        envoie_driver1();
    } else if (yValue > 700) {
        msg = "2";
        envoie_driver1();
    } else {
        msg = "0";
        envoie_driver1();        
    }

    driver1.send((uint8_t *)msg, strlen(msg));
    driver1.waitPacketSent();
    delay(2);
}

void envoie_driver2(){
    driver2.send((uint8_t *)msg, strlen(msg));
    driver2.waitPacketSent();
    delay(2);  
}
void envoie_driver1(){
    driver1.send((uint8_t *)msg, strlen(msg));
    driver1.waitPacketSent();
    delay(2);  
}