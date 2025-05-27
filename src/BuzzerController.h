#ifndef BUZZERCONTROLLER_H
#define BUZZERCONTROLLER_H

#include <Arduino.h>

class BuzzerController {
public:
    BuzzerController(uint8_t pin, uint16_t frequency = 1000);

    void begin();
    void on();
    void off();
    void beep(uint16_t duration = 200);
    void beepMultiple(uint8_t times = 3, uint16_t duration = 100, uint16_t interval = 100);
    void setFrequency(uint16_t frequency);
    bool isActive() const;

private:
    uint8_t _pin;
    uint16_t _frequency;
    bool _isOn;
};

#endif
