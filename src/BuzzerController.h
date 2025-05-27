#ifndef BUZZERCONTROLLER_H
#define BUZZERCONTROLLER_H

#include <Arduino.h>
#include <driver/ledc.h>  // optionnel mais utile

class BuzzerController {
public:
    BuzzerController(uint8_t pin, uint8_t channel = 0, uint16_t frequency = 1000, uint8_t resolution = 8);
    
    void begin();
    void on(uint8_t volume = 255);
    void off();
    void beep(uint16_t duration = 200, uint8_t volume = 255);
    void beepMultiple(uint8_t times = 3, uint16_t duration = 100, uint16_t interval = 100, uint8_t volume = 255);
    void setFrequency(uint16_t frequency);
    bool isActive() const;

private:
    uint8_t _pin;
    uint8_t _channel;
    uint16_t _frequency;
    uint8_t _resolution;
    bool _isOn;
};

#endif
