#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

#define joystick_X A0
#define joystick_Y A1

RH_ASK driver(2000, 4, 2, 5);

void setup() {
    Serial.begin(115200);    // Debugging only
    if (!driver.init())
        Serial.println("init failed");
}

void loop() {
    int xValue = analogRead(joystick_X);
    int yValue = analogRead(joystick_Y);

    Serial.print("X: ");
    Serial.println(xValue);
    Serial.print("Y: ");
    Serial.println(yValue);

    const char *msg;

    if (xValue < 300) {
        msg = "3";
    } else if (xValue > 700) {
        msg = "1";
    } else if (yValue < 300) {
        msg = "4";
    } else if (yValue > 700) {
        msg = "2";
    } else {
        msg = "0";
    }

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(2);
}
