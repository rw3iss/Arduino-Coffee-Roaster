Arduino

# Arduino CLI:

## Init:
arduino-cli.exe config init

## Compile:
acli compile -b arduino:avr:mega ./roaster.ino --build-path ./build --libraries "./lib/OneButton,C:\bin\arduino\libraries,./src" --library "./"

## Upload:
acli upload -p COM5 -b arduino:avr:mega -i build/roaster.ino.hex .

## Install library:
arduino-cli lib install FTDebouncer

## Board info:
acli board details -b arduino:avr:mega

## Debug:
arduino-cli daemon --debug




# Platform IO Arduino framework:
https://docs.platformio.org/en/latest/frameworks/arduino.html#framework-arduino


# Increasing IO pins:
https://www.engineersgarage.com/increasing-digital-io-of-arduino/


# Blink LED and display Serial I/O on monitor:
https://circuitstate.com/tutorials/how-to-use-vs-code-for-creating-and-uploading-arduino-sketches/


# Buttons using interrupts:
https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/


--------------------------------------------------------------------------------

# Using Analog Inputs:
https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput


# Relay:
https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/ 


# Thermocouples:
https://randomnerdtutorials.com/arduino-k-type-thermocouple-max6675/



# Push button to builtin LED:
https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

PULLUP/PULLDOWN explained:
https://www.electroniclinic.com/arduino-push-button-switch-wiring-and-code-beginners-level/



# AC Motor Control:
Methods advantes/disadvantages:
https://www.analog.com/en/analog-dialogue/articles/how-to-control-fan-speed.html


# Play sounds through a standalone .7W speaker:
https://create.arduino.cc/projecthub/Pigeon-Kicker/mega-bread-stereo-power-audio-amplifiers-c78c1f


# Read SD Card:
TFT_HX8357\examples\Draw_SDCard_Bitmap\Draw_SDCard_Bitmap.ino


# Toggle library:
https://github.com/Dlloydev/Toggle


# Controlling AC PWM module:
https://www.instructables.com/safe-and-simple-AC-PWM-Dimmer-for-arduino-Raspberr/
https://github.com/RobotDyn/AC-Light-Dimmer-Module-1-Channel-3.3V-5V-logic-AC-50-60hz-220V-110V/blob/master/RBDdimmer/examples/SimpleDimmer/SimpleDimmer.ino
https://www.amazon.com/dp/B072K9P7KH?psc=1&ref=ppx_yo2ov_dt_b_product_details

Z-C = AC zero-cross detector. This pin need to connect to IN MCU
The details: https://github.com/RobotDynOfficial/RBDDimmer

"Had the same problem. If you look at the traces on the circuit board, the to middle ones are connected together. I have those connected to neutral and the outside ones to hot. Hope that helps. I have two of these and both work well that way.
"
"It's not c-z it's Z-C which stands for Zero Cross. It's the signal that the ac line line voltage is a 0. On a 60hz system this occurs 120 times per second. It's an Input to your controller. The PWM is an output from the controller to the dimmer. Based on the dimming level that you select / program into your system after the Z-C activates the controller waits X milliseconds before it enables the PWM Line. Note: I have limited the dim setting from 30-90 any lower or higher causes the lights to flicker
"


//ZERO----2
//DIMMER----11


int i;
int ZDpin=0;
void setup(){
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(11,OUTPUT);
pinMode(13,OUTPUT);
pinMode(10,OUTPUT);
}

void light(){
delay(3);
digitalWrite(10,1);
}

void loop(){
i=digitalRead(10);
digitalWrite(13,0);
digitalWrite(10,0);
attachInterrupt(ZDpin,light,RISING);
delay(20);
if(i==1){
delay(3);
digitalWrite(13,1);
pwm();

}
}

void pwm()
{
for (int a=0; a<=255;a++)
{
analogWrite(11,a);
delay(8);
}
for (int a=255; a>=0;a--)
{
analogWrite(11,a);
delay(8);
}
delay(800);
}














# VS Code tasks to build and upload with Mega:
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Arduino Compile",
            "type": "shell",
            "command": "C:/Users/rw3iss/.bin/arduino-cli.exe compile -b arduino:avr:mega ./Roaster.ino --build-path ./build --libraries \".\\lib\\OneButton,C:\\bin\\arduino\\libraries,.\\src\" --library \".\"",
            "group": "build",
            "isBackground": false,
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared",
                "showReuseMessage": true
            },
            "problemMatcher": []
        },
        {
            "label": "Arduino Upload",
            "type": "shell",
            "command": "C:/Users/rw3iss/.bin/arduino-cli.exe upload -p COM5 -v --fqbn arduino:avr:mega -i \".\\build\\Roaster.ino.hex\" .",
            "group": "test",
            "isBackground": false,
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared",
                "showReuseMessage": true
            },
            "problemMatcher": []
        }
    ]
}


