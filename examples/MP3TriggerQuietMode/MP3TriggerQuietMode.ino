#include <MP3Trigger.h>

MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over Serial)
  trigger.setup();
  // Enable quietMode and set callback function 
  trigger.quietMode(1, quietModeTriggered);
}

void loop() {
  // Necessary to receive signals from trigger
  trigger.update();
}


void quietModeTriggered(int i) {
  // Function to be called every time an input becomes active.
  trigger.trigger(i);
}

