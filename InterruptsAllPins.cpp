/*
  InterruptsAllPins.cpp - Library for using an interrupt on any pin
  Created by V. Kalchev, 12.02.2016
  
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  version 3 as published by the Free Software Foundation.
*/

#include "Arduino.h"
#include "InterruptsAllPins.h"

InterruptsAllPins::InterruptsAllPins() {}

unsigned long firstPulse = 0;
unsigned long afterDelay = 0;

void InterruptsAllPins::attachInterrupt(byte pin) {
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);
}

void InterruptsAllPins::printAllPins(byte start, byte end) {
	for (byte i = start; i <= end; i++) {
		if ((i == A5) || (i == A4) || (i == A3) || (i == A2) || (i == A1) || (i == A0)) {
		    Serial.print("Analog Pin["); Serial.print(i-14); Serial.print("]: ");
            Serial.println(digitalRead(i));
		}
        Serial.print("Digital Pin["); Serial.print(i); Serial.print("]: ");
        Serial.println(digitalRead(i));
    }
}

bool InterruptsAllPins::debounce(unsigned int debounceTime) {
    firstPulse = millis();
      if ((firstPulse - afterDelay > 250)) {
      afterDelay = firstPulse;
	  return 1;
	  }
	return 0;
}