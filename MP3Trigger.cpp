/*
MP3Trigger.cpp
@author David Wicks
@url	sansumbrella.com
*/

#include "MP3Trigger.h"
MP3Trigger::MP3Trigger()
{
	Serial.begin(38400);
}

void MP3Trigger::play()
{
	Serial.write('O');
}

void MP3Trigger::forward()
{
	Serial.write('F');
}

void MP3Trigger::reverse()
{
	Serial.write('R');
}

void MP3Trigger::trigger(byte track)
{
	Serial.write('t'+track);
}

void MP3Trigger::play(byte track)
{
	Serial.write('p'+track);
}

void MP3Trigger::setVolume(byte level)
{
	level = level ^ B11111111;	//flip it around, so the higher number > higher volume
	Serial.write('v'+level);
}

void MP3Trigger::statusRequest()
{
	Serial.println("MP3 yet implemented");
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