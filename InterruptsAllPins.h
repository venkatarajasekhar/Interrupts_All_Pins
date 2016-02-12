/*
  InterruptsAllPins.h - Library for using an interrupt on any pin
  Created by V. Kalchev, 12.02.2016
  
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  version 3 as published by the Free Software Foundation.
*/

#ifndef InterruptsAllPins_h
#define InterruptsAllPins_h

class InterruptsAllPins {
	public:
	  InterruptsAllPins();
	  void attachInterrupt(byte pin);
	  void printAllPins(byte start, byte end);
	  bool debounce(unsigned int debounceTime);
};

#endif