#include <SoftwareSerial.h>
#include <MP3TriggerSoftwareSerial.h>

SoftwareSerial trigSerial = SoftwareSerial(2, 3);
MP3TriggerSS trigger;

void setup() {
  // Start serial communication with the trigger (over SoftwareSerial)
  trigger.setup(&trigSerial);
  
  // Start looping TRACK001.MP3
  trigger.setLooping(true,1);
}

void loop() {
  // Necessary to receive signals from trigger
  trigger.update();
}
