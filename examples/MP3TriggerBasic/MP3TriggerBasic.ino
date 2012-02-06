#include <MP3Trigger.h>
MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over Serial)
  trigger.setup(&Serial);
  Serial.begin( MP3Trigger::serialRate() );
  // Start looping TRACK001.MP3
  trigger.setLooping(true,1);
}

void loop() {
  // process signals from the trigger
  trigger.update();
}
