/*
MP3Trigger.h
@author David Wicks
@url	sansumbrella.com

Doesn't handle messages from the trigger at this point
*/

#ifndef MP3_TRIGGER_H
#define MP3_TRIGGER_H

#include <WProgram.h>

class MP3Trigger{
  public:
	MP3Trigger();
  	MP3Trigger(HardwareSerial* serial);
	~MP3Trigger();
  	void play();
	void trigger(byte track);	//1–255
	void play(byte track);		//0—255
	void forward();
	void reverse();
	void setVolume(byte level);	//0-255
	void statusRequest();
	
private:
	bool doLoop;
	HardwareSerial* s;
};

#endif