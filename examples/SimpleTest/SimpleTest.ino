#include "BuzzerController.h"

BuzzerController buzzer(25); // Pin 25

void setup() {
    buzzer.begin();
}

void loop() {
    buzzer.beepMultiple(3, 150, 100); // 3 bips, 150 ms chacun, 100 ms intervalle
    delay(2000);
}
