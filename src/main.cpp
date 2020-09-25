/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Wire.h> 
#include "SPI.h"
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_I2CDevice.h"

Adafruit_7segment matrix[4];

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 13
long randnum;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(12, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

  for(uint8_t i=0; i<4; i++) {
    matrix[i] = Adafruit_7segment();
    matrix[i].begin(0x70 + i);
  }
  Serial.write("Initializing ...");
  Serial.write(10);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);

  randnum = random(10,50);
  // wait for a second
  delay(randnum);

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

  randnum = random(100,500);
   // wait for a second
  delay(randnum);
  
  for(uint8_t i=0; i<4; i++) {
    matrix[i].writeDisplay();
  }
  
  
  char buf[500];
  sprintf(buf, "%lu ", randnum);

  Serial.write(buf);
}
