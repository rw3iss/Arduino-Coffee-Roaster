Board


# Elegoo (Arduino) Mega:
https://www.elegoo.com/products/elegoo-mega-2560-r3-board
https://www.amazon.com/dp/B01H4ZLZLQ?psc=1&ref=ppx_yo2ov_dt_b_product_details

"Arduino mega2560 R3"
Chip: Atmega2560-16au and Atmega16u2
Operating Voltage: 5V
Input: Voltage (recommended): 7-9V
Flash Memory: 256 KB of which 8 KB used by bootloader
SRAM: 8 KB EEPROM: 4 KB
Clock Speed: 16 MHz
LED_BUILTIN: 13
Length: 101.5 mm Width: 53.3 mm Weight: 34 g


## Working with platformio:
https://maker.pro/arduino/tutorial/how-to-use-platformio-in-visual-studio-code-to-program-arduino
https://docs.platformio.org/en/latest/platforms/atmelmegaavr.html

## Mega2560 Board docs:
https://docs.platformio.org/en/latest/boards/atmelavr/megaatmega2560.html#board-atmelavr-megaatmega2560

## PlatformIO atmel-avr examples:
https://github.com/platformio/platform-atmelavr/tree/master/examples




--------------------------------------------------------------------------------

# TFT screen:
HiLetgo 3.5" TFT LCD Display ILI9486/ILI9488 480x320 36 Pins
https://www.amazon.com/gp/product/B073R7Q8FF/ref=ox_sc_saved_title_7?smid=A30QSGOJR8LMXA&psc=1

** I'd make this 5 stars if they just included a card with the right lib info. After hours of fussing and failures, I figured this out:
- Get the correct library from Github. I can't put in links, but search for TFT_HX8357 by Bodmer: https://github.com/Bodmer/TFT_HX8357
--Download it by clicking "Code" button and choosing download as zip.
- Unzip the files, and then navigate into the unzipped folder.
- Edit the User_Setup.h file and set the driver to ILI9486 by uncommenting that line and commenting the other options.
- Zip the files back up (effectively re-rooting the zip so the files are at the top level)
- Open a blank Arduino sketch
- Open menu Sketch -> Include Library -> Add ZIP library
- Add your re-made zip.
Once these steps are done the lib is ready and the working examples are in the File -> Examples -> TFT_HX8357 menu.

** Those using the UTFT library from RinkyDink Electronics may have two issues. First, just a blank screen. If you get past that, a mirrored display. To fix those two issues:
1. Change the Arduino sketch line to: UTFT myGLCD(ILI9486,38,39,40,41);
2. Open the \UTFT\tft_drivers\ili9486\initlcd.h file. Go to the section for Memory Access Control (lines 85-86 in my version). Change the write data line to: LCD_Write_DATA(0x08);
Bit 0 of this value controls vertical flip. Bit 1 is for horizontal flip.










--------------------------------------------------------------------------------

# OTHER BOARDS:

HiLetgo ESP32 LCD WiFi Kit ESP-32 1.14 Inch LCD Display WiFi+Bluetooth CH9102 USB Type-C Internet Development Board for Arduino ESP8266 NodeMCU
https://www.amazon.com/gp/product/B07X1W16QS/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
ESP32-S3


ARDUINO UNO WiFi REV2
$54
https://store-usa.arduino.cc/products/arduino-uno-wifi-rev2?selectedStore=us
-5v
-IO: 14 — 5 Provide PWM Output


Arduino Due
3.3V $47
https://store-usa.arduino.cc/products/arduino-due
https://store-usa.arduino.cc/products/arduino-due-without-headers?selectedStore=us
(no wifi?)
-IO: 54 (of which 12 provide PWM output)



# Other board configs / supported boards:
https://docs.platformio.org/en/latest/platforms/atmelavr.html#configuration

















































