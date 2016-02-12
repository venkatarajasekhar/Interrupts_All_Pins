# InterruptsAllPins
Simple library for catching interrupts from all pins on the Arduino

## Methods
```c++
void attachInterrupt(byte pin);
```
Attaches an interrupt to a pin.

```c++
void printAllPins(byte start, byte end);
```
Prints the state of all pins in the specified range.

```c++
bool debounce(unsigned int debounceTime);
```
Returns "1" when the first pulse is registered. Then returns "0" for the next pulses until the specified amount of time has passed.
