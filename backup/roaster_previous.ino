

//#include <TFT_HX8357.h>  // Hardware-specific library
//#include <TFT_eSPI.h>  // Graphics and font library for ST7735 driver chip
//#include <SPI.h>

#include <max6675.h>;
#include "IOConfig.h";
#include "AppConfig.h";

//TFT_HX8357 tft = TFT_HX8357();  // Invoke custom library
//TFT_eSPI tft = TFT_eSPI();  // nodemcu oled

int tx = 5, ty = 0;
int hx = 5, hy = 30;
int mx = 5, my = 60;
int ex = 5, ey = 90;
int16_t sh;
int16_t sw;

// ROASTER //////////////////////////////////////////
MAX6675 thermoHeater(PIN_THERMO1_CLK, PIN_THERMO1_CS, PIN_THERMO1_DO);

void scanHeaterState() {
  if (millis() > btnHeaterTargetScanTime) {
    HEATER_BTN_STATE = digitalRead(PIN_HEATER_BTN);

    // if was previously on and then released, consider a "click"
    if (HEATER_BTN_LST_STATE == ON && HEATER_BTN_STATE == OFF) {
      if (HEATER_STATE == OFF)
        enableHeater();
      else
        disableHeater();
    }
    HEATER_BTN_LST_STATE = HEATER_BTN_STATE;
    
    btnHeaterTargetScanTime = millis() + BTN_SCAN_POLL_TIME_MS;
  }
}

void scanTemps() {
  // scan every TEMP_SCAN_POLL_TIME_MS
  if (millis() > thermo1TargetScanTime) {
    if (HEATER_STATE == ON) {
      //Serial.print("C = ");
      //Serial.println(thermoHeater.readCelsius());
      Serial.print("F = ");
      Serial.println(thermoHeater.readFahrenheit());
    }

    thermo1TargetScanTime = millis() + TEMP_SCAN_POLL_TIME_MS;
  }
}

void scanEncoder() {
	// CLK STATE ///////////
	BTN_ENCODER_CLK_STATE = digitalRead(PIN_HEATER_BTN_CLK);
  int dtState = digitalRead(PIN_HEATER_BTN_DT);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (BTN_ENCODER_CLK_STATE != BTN_ENCODER_CLK_LAST_STATE && BTN_ENCODER_CLK_STATE == HIGH) {
		if (dtState != BTN_ENCODER_CLK_STATE) {
   		// Encoder is rotating CW so increment
			encCounter++;
			encDir = "CW";
		} else {
  		// the encoder is rotating CCW so decrement
			encCounter--;
			encDir = "CCW";
		}

    //if (encCounter < 0) encCounter = 0;
    //if (encCounter > MAX_ENCODER_VALUE) encCounter = MAX_ENCODER_VALUE;

		Serial.print("Direction: ");
		Serial.print(encDir);
		Serial.print(" | Counter: ");
		Serial.println(encCounter);
	}

	// Remember last CLK state
	BTN_ENCODER_CLK_LAST_STATE = BTN_ENCODER_CLK_STATE;

  // BUTTON STATE //////////
  BTN_ENCODER_STATE = digitalRead(PIN_HEATER_BTN_SW);

  if (BTN_ENCODER_LAST_STATE == LOW && BTN_ENCODER_STATE == HIGH) {
    Serial.println("Button pressed!");
    // if (MOTOR_STATE == OFF)
    //   enableMotor();
    // else
    //   disableMotor();
  }

  BTN_ENCODER_LAST_STATE = BTN_ENCODER_STATE;
}

void scanButtons() {
  scanHeaterState();
  scanEncoder();
  delay(1);
}

void enableHeater() {
  digitalWrite(LED_BUILTIN, ON);
  digitalWrite(PIN_HEATER, ON);
  Serial.println("ON");
  // digitalWrite(PIN_HEATER, ON);
  // tft.drawString("HEATER ON   ", hx, hy, 4);
  HEATER_STATE = ON;
}

void disableHeater() {
  Serial.println("OFF");
  digitalWrite(LED_BUILTIN, OFF);
  digitalWrite(PIN_HEATER, OFF);
  //Serial.println("Button pressed (off)!");
  // digitalWrite(PIN_HEATER, OFF);
  // tft.drawString("HEATER OFF ", hx, hy, 4);
  HEATER_STATE = OFF;
}


//TFT_HX8357 tft = TFT_HX8357();  // Invoke custom library
// void initScreen() {
//   tft.init();
//   tft.setRotation(1);

//   sh = tft.height();
//   sw = tft.width();

//   tft.fillScreen(HX8357_BLACK);
//   tft.setTextColor(HX8357_WHITE, HX8357_BLACK);

//   // tft.drawString("           ", hx, hy, 4);
//   // tft.drawString("           ", mx, my, 4);
//   // tft.drawString("           ", ex, ey, 4);
// }


void initEncoders() { 
	BTN_ENCODER_CLK_STATE = digitalRead(PIN_HEATER_BTN_CLK);
}


App app;

void setup() {
  app = new App();

  //initScreen();
  //initRoasterIO();
  initEncoders();

  // Setup Serial Monitor
  Serial.begin(9600);
  Serial.println("Roaster running.");

  Serial.print("HIGH = ");
  Serial.println(HIGH);

  pinMode(LED_BUILTIN, OUTPUT);

  // pinMode(PIN_THERMO1_DO, INPUT);
  // pinMode(PIN_THERMO1_CS, INPUT);
  // pinMode(PIN_THERMO1_CLK, INPUT);

  pinMode(PIN_HEATER_BTN, INPUT);
  pinMode(PIN_HEATER, OUTPUT);

  // encoder
  pinMode(PIN_HEATER_BTN_SW, INPUT_PULLUP);
  pinMode(PIN_HEATER_BTN_DT, INPUT);
  pinMode(PIN_HEATER_BTN_CLK, INPUT);

  delay(500);
  //tft.drawString("TEST STRING", 50, 50, 4);
}

void loop() {
  scanButtons();
  scanTemps();

  delay(BTN_SCAN_DELAY);
}




































/*
code	color
0x0000	Black
0xFFFF	White
0xBDF7	Light Gray
0x7BEF	Dark Gray
0xF800	Red
0xFFE0	Yellow
0xFBE0	Orange
0x79E0	Brown
0x7E0	Green
0x7FF	Cyan
0x1F	Blue
0xF81F	Pink
*/




// Motor pins and state:
int PIN_MOTOR_BTN = 0;
int PIN_MOTOR = 12;
int MOTOR_STATE = OFF;
int MOTOR_BTN_STATE = OFF;
int MOTOR_BTN_LST_STATE = OFF;

// Heater pins and state:
// int PIN_HEATER_BTN = 35;
// int PIN_HEATER = 27;
// int HEATER_STATE = OFF;
// int HEATER_BTN_STATE = OFF;
// int HEATER_BTN_LST_STATE = OFF;

// Eject pins and state:
int PIN_EJECT_BTN = 26;
int PIN_EJECT = 13;
int EJECT_STATE = OFF;
int EJECT_BTN_STATE = OFF;


uint32_t targetTime = 0;  // for next 1 second timeout

byte omm = 99;
bool initial = 1;
byte xcolon = 0;
unsigned int colour = 0;

static uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}

uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6);  // Get H, M, S from compile time
///////////////



















///////////////////////
// Scan button states:

void scanMotorState() {
  MOTOR_BTN_STATE = digitalRead(PIN_MOTOR_BTN);
  if (MOTOR_BTN_LST_STATE == ON && MOTOR_BTN_STATE == OFF) {
    if (MOTOR_STATE == OFF)
      enableMotor();
    else
      disableMotor();
  }
  MOTOR_BTN_LST_STATE = MOTOR_BTN_STATE;
}

void scanEjectState() {
  EJECT_BTN_STATE = digitalRead(PIN_EJECT_BTN);
  if (EJECT_STATE == OFF && EJECT_BTN_STATE == ON)
    enableEject();
  else if (EJECT_STATE == ON && EJECT_BTN_STATE == OFF)
    disableEject();
}

void scanButtonStates_old() {
  scanHeaterState();
  scanMotorState();
  scanEjectState();
  delay(100);
}

//////////////////////
// Control methods:

void enableMotor() {
  digitalWrite(PIN_MOTOR, ON);
  //tft.drawString("MOTOR ON   ", mx, my, 4);
  MOTOR_STATE = ON;
}

void disableMotor() {
  digitalWrite(PIN_MOTOR, OFF);
  //tft.drawString("MOTOR OFF  ", mx, my, 4);
  MOTOR_STATE = OFF;
}

void enableEject() {
  digitalWrite(PIN_EJECT, ON);
  //tft.drawString("EJECT ON   ", ex, ey, 4);
  EJECT_STATE = ON;
}

void disableEject() {
  digitalWrite(PIN_EJECT, OFF);
  //tft.drawString("EJECT OFF  ", ex, ey, 4);
  EJECT_STATE = OFF;
}

//////////////////////
// Utility methods:

void initRoasterIO() {
  pinMode(PIN_HEATER_BTN, INPUT);
  pinMode(PIN_HEATER, OUTPUT);
  disableHeater();

  pinMode(PIN_MOTOR_BTN, INPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  disableMotor();

  pinMode(PIN_EJECT_BTN, INPUT);
  pinMode(PIN_EJECT, OUTPUT);
  disableEject();
}

// void loop() {
//   scanButtonStates();

//   if (targetTime < millis()) {
//     targetTime = millis() + 1000;
//     ss++;  // Advance second

//     if (ss == 60) {
//       ss = 0;
//       omm = mm;
//       mm++;  // Advance minute
//       if (mm > 59) {
//         mm = 0;
//         hh++;  // Advance hour
//         if (hh > 23) {
//           hh = 0;
//         }
//       }
//     }

//     int bs = digitalRead(PIN_EJECT_BTN);
//     tft.setTextColor(TFT_YELLOW, TFT_BLACK);

//     char s[32];
//     snprintf(s, sizeof(s), "ES = %d", bs);
//     tft.drawString(s, 10, 5, 2);

//     if (ss == 0 || initial) {
//       initial = 0;
//       //tft.setTextColor(TFT_GREEN, TFT_BLACK);
//       // tft.setCursor(tx, ty);
//       // tft.print(__DATE__);
//       //tft.print(__DATE__);  // This uses the standard ADAFruit small font
//       //tft.drawCentreString("It is windy", 120, 48, 2);  // Next size up font 2
//       //tft.setTextColor(0xF81F, TFT_BLACK); // Pink
//       //tft.drawCentreString("12.34",80,100,6); // Large font 6 only contains characters [space] 0 1 2 3 4 5 6 7 8 9 . : a p m
//     }
//   }
// }


// /*
//  Test the tft.print() viz the libraries embedded write() function

//  This sketch used font 2, 4, 7

//  Make sure all the required fonts are loaded by editting the
//  User_Setup.h file in the TFT_ILI9341 library folder.