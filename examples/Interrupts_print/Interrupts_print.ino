#include <InterruptsAllPins.h>

InterruptsAllPins interrupt;
unsigned int debounceTime = 250; //The time we wait for the input to settle


void setup() {
  Serial.begin(9600);

  interrupt.attachInterrupt(6);  //Method for attaching interrupt to a pin
  interrupt.attachInterrupt(A5);


}

void loop() {

}


ISR (PCINT2_vect) { //Interrupt vector catching interrupts from D0-D7
  if (interrupt.debounce(debounceTime) == 1) {  //Returns "1" when the input has settled
    interrupt.printAllPins(0, 7);  //Prints the state of all pins in the range specified
    
  }
}

ISR (PCINT0_vect) { //Interrupt vector catching interrupts from D8-D13
  if (interrupt.debounce(debounceTime) == 1) {
    interrupt.printAllPins(8, 13);
    
  }
}

ISR (PCINT1_vect) { //Interrupt vector catching interrupts from A0-A5
  if (interrupt.debounce(debounceTime) == 1) {
    interrupt.printAllPins(A0, A5);
    
  }
}

