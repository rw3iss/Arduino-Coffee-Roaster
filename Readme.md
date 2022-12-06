# Coffee Roaster Firmware

### Feature Overview:
* Load, create, and export custom Roast profiles.
* Ability to record a "live" Roast profile.
* Roast screen to see live/current and target roast values, with a graph.
* Wifi and BT connection support with web/mobile app to monitor and control the roaster remotely, and also load and export profiles (todo).

### Sensor and Hardware Control Support
These are the pieces of hardware (ie. features) this application supports:
* Heater (temperature)
* Motor speed (drum turn speed)
* Fan speed (exhaust)
* Smoke sensor (if installed)
* Eject door control
* Cooling motor speed
* Cooling fan speed

### Roast Profile Features
* Each roast profile can define target parameters for any given hardware control (ie. heater, motor speed, fan speed), at any given point in time.
* A slope can also be added between values in order to transition from the previous value to the next at ie. linear, logarithmic, or exponential speed.
* Options can be configured to set a roast profile's:
    * Stop time (time to automatically eject)
    * Smoke exit limit (eject when the smoke sensor, if configured, reaches a specified value for longer than a specified duration)


# Development

### Technical Feature Overview (code internals):
* Built on custom generic Application framework (reusable), extensible, easy to use:
    * Includes a custom ViewManager and View model which allows for React-like component heirarchies that can send state updates (to redraw UI/screen), or receive hardware control events (ie. if a View wants to handle a particular button press or anything else).
    * Includes a custom ViewRenderer that will transcribe any given "rendered" View to a configured Screen (ie. output), according to a given Style schema (global or per view). Todo: define style API. The ViewRenderer can also scale the rendered output to conform the view to any screen dimensions, or section of it (ie. minimap/thumbnail view, or just to have a responsive UI across any screen or screen ratios.
    * Framework exposes common Control elements such as Button, Screen, Thermocouple, Jogwheel, etc. More todo.

### Setup:

#### Requirements:
arduino-cli

#### Install Arduino libraries:
`arduino-cli lib install ArduinoSTL`
`arduino-cli lib install TFT_HX8357`

##### Note about ArduinoSTL (v1.3.3) (as of 11-5-22):
Using this library is throwing the error:
```
new.cpp.o (symbol from plugin): In function `operator new(unsigned int)':
(.text+0x0): multiple definition of `std::nothrow'
arduino-app/build/libraries/ArduinoSTL/new_handler.cpp.o (symbol from plugin):(.text+0x0): first defined here
```
To get around this, you must comment line ~22 in ArduinoSTL/src/new_handler.cpp:
`// const std::nothrow_t std::nothrow = { };`

This should allow arduini-cli to compile the program.


#### Build the Arduino sketch:
`./build.sh`

#### Upload to Arduino sketch:
Edit upload.sh to specify your board's correct COM port, then run:
`./upload.sh`
