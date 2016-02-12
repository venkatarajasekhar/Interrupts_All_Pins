# InterruptsAllPins
Simple library for catching interrupts from all pins on the Arduino

## Methods
```c++
void attachInterrupt(byte pin)
```
Attaches an interrupt to a pin

```c++
void printAllPins(byte start, byte end)
```
Prints the state of all pins in the specified range

```c++
bool debounce(unsigned int debounceTime)
```
Waits the specified amount of time, then returns "1" when the input has settled
