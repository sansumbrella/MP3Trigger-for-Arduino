#include <SoftwareSerial.h>
#include <MP3Trigger.h>

SoftwareSerial trigSerial = SoftwareSerial(2, 3);
MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over SoftwareSerial)
  trigger.setup(&trigSerial);

  // Enable quietMode and set callback function 
  trigger.quietMode(1, quietModeTriggered);
}

void loop() {
  // Necessary to receive signals from trigger
  trigger.update();
}

// Function to be called every time an input becomes active.
void quietModeTriggered(int i) {
  // Do stuff before trigger...
  trigger.trigger(i);
}

