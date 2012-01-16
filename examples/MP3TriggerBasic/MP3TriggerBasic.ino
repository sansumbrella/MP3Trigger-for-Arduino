#include <MP3Trigger.h>

MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over Serial)
  trigger.setup();
  
  // Start looping TRACK001.MP3
  trigger.setLooping(true,1);
}

void loop() {
  // Necessary to receive signals from trigger
  trigger.update();
}
