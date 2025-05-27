#include <Arduino.h> // Nécessaire pour ledcSetup et autres
#include "BuzzerController.h"

BuzzerController::BuzzerController(uint8_t pin, uint8_t channel, uint16_t frequency, uint8_t resolution)
    : _pin(pin), _channel(channel), _frequency(frequency), _resolution(resolution), _isOn(false) {}

void BuzzerController::begin() {
    pinMode(_pin, OUTPUT);
    ledcSetup(_channel, _frequency, _resolution);
    ledcAttachPin(_pin, _channel);
}

void BuzzerController::on(uint8_t volume) {
    ledcWrite(_channel, volume);
    _isOn = true;
}

void BuzzerController::off() {
    ledcWrite(_channel, 0);
    _isOn = false;
}

void BuzzerController::beep(uint16_t duration, uint8_t volume) {
    on(volume);
    delay(duration);
    off();
}

void BuzzerController::beepMultiple(uint8_t times, uint16_t duration, uint16_t interval, uint8_t volume) {
    for (uint8_t i = 0; i < times; i++) {
        beep(duration, volume);
        delay(interval);
    }
}

void BuzzerController::setFrequency(uint16_t frequency) {
    _frequency = frequency;
    ledcSetup(_channel, _frequency, _resolution);
}

bool BuzzerController::isActive() const {
    return _isOn;
}
