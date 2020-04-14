/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// 
/* NOTE: The SEGGER headers do not have the common __cplusplus directives
*  Rather than modifying the SEGGER_RTT files (that will likely be updated)
*  you can wrap your header include in the extern pattern.

    #ifdef __cplusplus
    extern "C" {
    #endif

    // all of your legacy C code here

    #ifdef __cplusplus
    }
    #endif
*/
extern "C" {
#include <SEGGER_RTT.h>
}

// the setup function runs once when you press reset or power the board
void setup() {
    delay(5000);
    Serial.begin(9600);
    Serial.println(F("Blink test"));
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.print("LED pin = ");
    Serial.println(LED_BUILTIN);
    pinMode(11, OUTPUT);
    pinMode(19, OUTPUT);
    Serial.println("Pins opened.");
    pinMode(7,INPUT_PULLUP);
}

int loopCount = 0;

// the loop function runs over and over again forever
void loop() {
    for (int i = 0; i < 10; i++)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(50);                      
      digitalWrite(LED_BUILTIN, LOW);
      delay(50);
    }
    delay(2000);      
	loopCount += 1;
    SEGGER_RTT_printf(0, "%sloopCount=%s%d%s,\n", RTT_CTRL_TEXT_WHITE, RTT_CTRL_TEXT_BRIGHT_GREEN, loopCount, RTT_CTRL_TEXT_WHITE);
    SEGGER_RTT_printf(0, "@millis()=%s%u%s.\n", RTT_CTRL_TEXT_CYAN, millis(), RTT_CTRL_TEXT_WHITE);
}
