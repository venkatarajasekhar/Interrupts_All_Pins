#include <InterruptsAllPins.h>

InterruptsAllPins interrupt;
unsigned int debounceTime = 250; //The time we wait before we take new state change


void setup() {
  Serial.begin(9600);

  interrupt.attachInterrupt(6);  //Method for attaching interrupt to a pin
  interrupt.attachInterrupt(A5);


}

void loop() {

}


ISR (PCINT2_vect) { //Interrupt vector catching interrupts from D0-D7
  if (interrupt.debounce(debounceTime) == 1) {  //Returns "1" only if the input hasn't changed for the specified amount of time
    //Code to execute after attached pin (D0-D7) has changed state

  }
}

ISR (PCINT0_vect) { //Interrupt vector catching interrupts from D8-D13
  if (interrupt.debounce(debounceTime) == 1) {
    //Code to execute after attached pin (D8-D13) has changed state

  }
}

ISR (PCINT1_vect) { //Interrupt vector catching interrupts from A0-A5
  if (interrupt.debounce(debounceTime) == 1) {
    //Code to execute after attached pin (A0-A5) has changed state

  }
}

