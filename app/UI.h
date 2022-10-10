#ifndef UI_h
#define UI_h

//#include "./Button.h"
#include "./IOConfig.h"
#include <max6675.h>

class UI {

   public:
      UI();
      void setup();
      void loop();

   private:
        void initIO();

        // Button powerBtn;
        // Button heaterBtn;
        // Button motorBtn;
        // Button ejectBtn;
        // Button tempUpBtn;
        // Button tempDownBtn;

        //MAX6675 thermoHeater(PIN_THERMO1_CLK, PIN_THERMO1_CS, PIN_THERMO1_DO);

      //Screen screen;
      //profiles;

};

#endif