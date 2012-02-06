#include <MP3Trigger.h>
MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over Serial)
  trigger.setup(&Serial);
  Serial.begin( MP3Trigger::serialRate() );

  // Enable quietMode and set callback function 
  trigger.quietMode(1, quietModeTriggered);
}

void loop() {
  // process signals from the trigger
  trigger.update();
}

void quietModeTriggered(int i) {
  // Function to be called every time an input becomes active.
  trigger.trigger(i);
}

