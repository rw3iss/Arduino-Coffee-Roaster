#ifndef AppConfig_h
#define AppConfig_h

struct Config {
        String text = "This is my default text.";
        int number = 100;
};

int BTN_SCAN_DELAY = 20;  // delay after each loop to scan for new inputs
int TEMP_SCAN_POLL_TIME_MS = 500;
int BTN_SCAN_POLL_TIME_MS = 20;
int ENCODER_SCAN_POLL_TIME_MS = 1;

#endif