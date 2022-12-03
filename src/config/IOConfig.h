#ifndef IOConfig_h
#define IOConfig_h

#include <Arduino.h>

// #define HIGH 1;
// #define LOW 0;

// When button/IO is pushed down/engaged, digitalRead will give '0' == LOW.
int ON = HIGH; // ON == HIGH == 1
int OFF = LOW; // OFF == LOW == 0

// push button logic:
int UP = ON; // == 1 (not pressed)
int DOWN = OFF; // == 0 (pressed)


// Power button pins and state:
int PIN_POWER_BTN = 2;
int POWER_STATE = OFF;
int POWER_BTN_STATE = UP;
int POWER_BTN_LST_STATE = UP;
uint32_t btnPowerTargetScanTime = 0;

// heater thermo (long one) ////////////
int PIN_THERMO1_DO = 5;
int PIN_THERMO1_CS = 6;
int PIN_THERMO1_CLK = 7;

//MAX6675 thermoHeater(PIN_THERMO1_CLK, PIN_THERMO1_CS, PIN_THERMO1_DO);
float thermo1Temp = 0;
uint32_t thermo1TargetScanTime = 0;

// Heater pins and state (pushbutton)
int PIN_HEATER_BTN = 3;
int PIN_HEATER = 4;
int HEATER_STATE = OFF;
int HEATER_BTN_STATE = UP;
int HEATER_BTN_LST_STATE = UP;
uint32_t btnHeaterTargetScanTime = 0;



// Heater pins and state (encoder)
// int PIN_HEATER_BTN = 10;  //2;  // SW of encoder
// int PIN_HEATER = 11;
int PIN_HEATER_BTN_SW = 2;
int PIN_HEATER_BTN_DT = 3;   // DT of encoder
int PIN_HEATER_BTN_CLK = 4;  // CLK of encoder

// temp down and up
int PIN_TEMP_DOWN_BTN = 5;
int TEMP_DOWN_BTN_STATE = UP;
int TEMP_DOWN_BTN_LST_STATE = UP;
int PIN_TEMP_UP_BTN = 6;
int TEMP_UP_BTN_STATE = UP;
int TEMP_UP_BTN_LST_STATE = UP;
uint32_t btnTempTargetScanTime = 0;
uint32_t btnTempUpTargetHoldTime = 0;
uint32_t btnTempUpTargetHoldNextIncTime = 0;
uint32_t btnTempDownTargetHoldTime = 0;
uint32_t btnTempDownTargetHoldNextIncTime = 0;

// Motor:
int PIN_MOTOR_BTN = 9;
int PIN_MOTOR = 10;
int MOTOR_STATE = OFF;
int MOTOR_BTN_STATE = UP;
int MOTOR_BTN_LST_STATE = UP;
uint32_t btnMotorTargetScanTime = 0;

// Eject:
int PIN_EJECT_BTN = 11;
int PIN_EJECT = 13; //12;
int EJECT_STATE = OFF;
int EJECT_BTN_STATE = UP;
int EJECT_BTN_LST_STATE = UP;
uint32_t btnEjectTargetScanTime = 0;

int MAX_ENCODER_VALUE = 500;  // max temp of 500
int BTN_ENCODER_CLK_LAST_STATE = OFF;
int BTN_ENCODER_CLK_STATE = OFF;
int BTN_ENCODER_LAST_STATE = OFF;
int BTN_ENCODER_STATE = OFF;
int encCounter = 0;
String encDir = "";

#endif