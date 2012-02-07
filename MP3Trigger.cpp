/*
MP3Trigger.cpp
@author David Wicks
@url	sansumbrella.com
*/

#include "MP3Trigger.h"

MP3Trigger::MP3Trigger()
{
	mDoLoop = false;
	mPlaying = false;
}

MP3Trigger::~MP3Trigger()
{
	s->flush();
	s = NULL;
}

void MP3Trigger::setup(Stream *serial)
{
	s = serial;
}

// 
// Looping functions
// 
void MP3Trigger::setLooping(bool doLoop, byte track)
{
	mDoLoop = doLoop;
	mLoopTrack = track;
	
	if(!mPlaying && mDoLoop)
	{
		loop();
	}
}

void MP3Trigger::setLoopingTrack(byte track)
{
	mLoopTrack = track;
}

void MP3Trigger::update()
{
	if( s->available() )
	{
		int data = s->read();
		switch(char(data))
		{
			case 'X':
				handleTrackEnd();
				break;
			case 'x':
				if(!mPlaying) {
					handleTrackEnd();
				}
				break;
			case 'E':
				mPlaying = false;
				break;
			case 'M':
				handleTriggerInput();
				break;
			default:
				break;
		}
	}
}

void MP3Trigger::handleTrackEnd()
{
	if(mDoLoop)
	{
		loop();
	} else
	{
		mPlaying = false;
	}
}

void MP3Trigger::handleTriggerInput()
{
	byte data;
	byte reads = 0;
	byte retries = 0;
	byte i;
	while(reads < 3 && retries < 1000) {
		if(s->available()) {
			data = (byte) s->read();
			if(data) {
				for(i = 0; i < 8; i++) {
					if( (data >> i) & B00000001 ) {
						quickModeCallback(i + 8*(2-reads) + 1);
					}
				}
			}
			reads++;
		}
		else {
			retries++;
		}
	}
}

void MP3Trigger::loop()
{
	trigger(mLoopTrack);
}

void MP3Trigger::stop()
{
	mDoLoop = false;
	
	if(mPlaying)
	{
		play();
	}
}

// 
// Single-byte built-in functions
// 

void MP3Trigger::play()
{
	s->write('O');
	mPlaying = !mPlaying;
}

void MP3Trigger::forward()
{
	s->write('F');
}

void MP3Trigger::reverse()
{
	s->write('R');
}

//
// Built-in two-byte functions
// 

void MP3Trigger::trigger(byte track)
{
	s->write('t');
	s->write(track);
	mPlaying = true;
}

void MP3Trigger::play(byte track)
{
	s->write('p');
	s->write(track);
	mPlaying = true;
}

void MP3Trigger::setVolume(byte level)
{
	// level = level ^ B11111111;	//flip it around, so the higher number > higher volume
	s->write('v');
	s->write(level);
}

// 1 for on, 0 for off, callback function
void MP3Trigger::quietMode(boolean onoff, void (*callback)(int))
{
	s->write('Q');
	s->write( '0' + onoff );
	quickModeCallback = callback;
}

// 
// Response functions
// 

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
