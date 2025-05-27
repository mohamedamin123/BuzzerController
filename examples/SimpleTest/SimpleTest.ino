#include "BuzzerController.h"

BuzzerController buzzer(25); // GPIO 25

void setup() {
    buzzer.begin();
}

void loop() {
    buzzer.beepMultiple(3, 150, 100, 200); // 3 bips à volume moyen
    delay(2000);
}
