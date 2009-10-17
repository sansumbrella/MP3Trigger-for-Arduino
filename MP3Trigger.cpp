/*
MP3Trigger.cpp
@author David Wicks
@url	sansumbrella.com
*/

#include "MP3Trigger.h"

MP3Trigger::MP3Trigger()
{
	doLoop = false;
}

void MP3Trigger::setup(HardwareSerial* serial)
{	//since Serial.begin demands to be called in the setup() function
	//make sure to call this before trying to use the trigger
	s = serial;
	s->begin(38400);
}

MP3Trigger::~MP3Trigger()
{
	s->flush();
	s = NULL;
}

void MP3Trigger::play()
{
	s->write('O');
}

void MP3Trigger::forward()
{
	s->write('F');
}

void MP3Trigger::reverse()
{
	s->write('R');
}

void MP3Trigger::trigger(byte track)
{
	s->write('t');
	s->write(track);
}

void MP3Trigger::play(byte track)
{
	s->write('p');
	s->write(track);
}

void MP3Trigger::setVolume(byte level)
{
	level = level ^ B11111111;	//flip it around, so the higher number > higher volume
	s->write('v');
	s->write(level);
}

void MP3Trigger::statusRequest()
{
	s->println("MP3Trigger::statusRequest is not yet implemented");
	s->flush();
	s->write('S');
	s->write('1');
	delay(5);
	s->read();
	//will need to work on this one to make it useful
	// if (Serial.available() > 0)
	// {
	// 	// read the incoming byte:
	// 	int incomingByte = Serial.read();
	// 
	// 	// say what you got:
	// 	Serial.print("I received: ");
	// 	Serial.println(incomingByte, DEC);
	// }
}