/*
MP3Trigger.h
@author David Wicks, additions by Carl Jensen
@url	sansumbrella.com

Doesn't handle messages from the trigger at this point
*/

#ifndef MP3_TRIGGER_SS_H
#define MP3_TRIGGER_SS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class MP3TriggerSS{
public:
	MP3TriggerSS();
	~MP3TriggerSS();
	//void setup(HardwareSerial* serial);
	void setup(SoftwareSerial* serial);
	void setup(boolean soft);
	//void setup();
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
	
private:
	bool mDoLoop;
	byte mLoopTrack;
	bool mPlaying;
	void loop();
	//HardwareSerial* s;
	SoftwareSerial* s;
    void (*quickModeCallback)(int);
};

#endif