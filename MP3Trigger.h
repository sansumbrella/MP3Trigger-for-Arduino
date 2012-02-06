/*
MP3Trigger.h
@author David Wicks
@url	sansumbrella.com

Doesn't handle messages from the trigger.

Accepts an iostream over which it sends/receives commands
This is generally the HardwareSerial (Serial) in Arduino,
though you could substitute in any other stream.

You should make sure that a serial device is operating
at the trigger's rate, which you can get like so:
Serial.begin( MP3Trigger::serialRate() )
*/
#ifndef MP3_TRIGGER_H
#define MP3_TRIGGER_H

#include <Arduino.h>

class MP3Trigger{
public:
	MP3Trigger();
	~MP3Trigger();
	void setup(Stream *serial);
	void setup();
	void play();
	void stop();
	void trigger(byte track);	//1–255
	void play(byte track);		//0—255
	void forward();				//move ahead one track
	void reverse();				//move back one track
	void setVolume(byte level);	//0-255
	void quietMode(boolean onoff, void (*function)(int));	//1 for on, 0 for off, callback function
	void statusRequest();
	
	void setLooping(bool doLoop, byte track);		//turn looping on/off
	void setLoopingTrack(byte track);	//select the track to loop
	void update();						//make sure to call this during your loop()
	
	static long serialRate(){ return 38400; }
private:
	void handleTrackEnd();
	void handleTriggerInput();
	void loop();
	
	bool mDoLoop;
	byte mLoopTrack;
	bool mPlaying;
	Stream *s;
	void (*quickModeCallback)(int);
};

#endif
