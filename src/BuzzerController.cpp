#include "BuzzerController.h"

BuzzerController::BuzzerController(uint8_t pin, uint16_t frequency)
    : _pin(pin), _frequency(frequency), _isOn(false) {}

void BuzzerController::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void BuzzerController::on() {
    tone(_pin, _frequency);
    _isOn = true;
}

void BuzzerController::off() {
    noTone(_pin);
    _isOn = false;
}

void BuzzerController::beep(uint16_t duration) {
    on();
    delay(duration);
    off();
}

void BuzzerController::beepMultiple(uint8_t times, uint16_t duration, uint16_t interval) {
    for (uint8_t i = 0; i < times; ++i) {
        beep(duration);
        delay(interval);
    }
}

void BuzzerController::setFrequency(uint16_t frequency) {
    _frequency = frequency;
    if (_isOn) {
        tone(_pin, _frequency); // met à jour le son courant
    }
}

bool BuzzerController::isActive() const {
    return _isOn;
}
