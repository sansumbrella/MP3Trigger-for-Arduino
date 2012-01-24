/*
MP3Trigger.h
@author David Wicks, additions by Carl Jensen
@url	sansumbrella.com

Supports Quiet Mode
Doesn't handle status report from the trigger at this point
*/

#ifndef MP3_TRIGGER_H
#define MP3_TRIGGER_H

#include <Arduino.h>
//#include <SoftwareSerial.h>

class MP3Trigger{
public:
	MP3Trigger();
	~MP3Trigger();
	void setup(HardwareSerial* serial);
	//void setup(SoftwareSerial* serial);
	void setup();
	void play();
	void stop();
	void trigger(byte track);	//1-255
	void play(byte track);		//0-255
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
	HardwareSerial* s;
	//SoftwareSerial* s;
	void (*quickModeCallback)(int);
};

#endif