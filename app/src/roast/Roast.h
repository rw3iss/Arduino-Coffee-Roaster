#pragma once

#include <Arduino.h>

class Roast {
    public:
        Roast(){};

    private:
        char32_t _profileName;  // todo: reference a profile ID

        uint32_t _startTime;
        uint32_t _elapsedTime;
        uint32_t _ejectTime;

        bool _heaterEnabled;
        int _currentTemp;
        int _targetTemp;

        bool _motorEnabled;
        int _motorSpeed;

        bool _exhaustEnabled;
        int _exhaustSpeed;

        bool _isEjected;
        bool _coolingMotorSpeed;
        bool _coolingExhaustSpeed;
};
