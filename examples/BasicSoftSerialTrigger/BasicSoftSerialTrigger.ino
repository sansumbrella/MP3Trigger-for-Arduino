#include <SoftwareSerial.h>
#include <MP3Trigger.h>

SoftwareSerial trigSerial = SoftwareSerial(2, 3);
MP3Trigger trigger;

void setup() {
  // Start serial communication with the trigger (over SoftwareSerial)
  trigger.setup(&trigSerial);
  trigSerial.begin( MP3Trigger::serialRate() );
  
  // Start looping TRACK001.MP3
  trigger.setLooping(true,1);
}

void loop() {
  // process signals from the trigger
  trigger.update();
}
