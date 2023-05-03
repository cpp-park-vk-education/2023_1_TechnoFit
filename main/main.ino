#include "sensors.h"
#include "network.h"
#include "HAR_sensor.h"
#include "interface.h"

#define LED_1_PIN 9

LedInterface led1(LED_1_PIN);

void setup() { }
void loop() {
    led1.on();
    delay(500);
    led1.off();
    delay(500);
}
