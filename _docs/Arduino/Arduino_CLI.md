# produce profile:
https://blog.arduino.cc/2022/06/06/arduino-cli-0-23-makes-your-projects-future-proof-with-build-profiles/

arduino-cli compile -b arduino:avr:mega --dump-profile \
--library "./src/app" \
--library "./src/lib" \
--library "./src/lib/app" \
--library "./src/lib/controls" \
--library "./src/lib/utils" \
--library "./lib/OneButton" \
--library "./lib/MAX6675" \
--library "/Users/rw3iss/Documents/Arduino/libraries/StandardCplusplus-master" \
--library "/Users/rw3iss/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino" \
--library "/Users/rw3iss/Documents/Arduino/libraries/ArduinoSTL-master/src"