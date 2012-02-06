/*
Flags.h
@author David Wicks
@url	sansumbrella.com

Flags to affect compilation behavior
To use SoftwareSerial in your project,
define the appropriate flag before including
the MP3Trigger header
e.g.:

#define TRIGGER_SOFT_SERIAL
#include <MP3Trigger.h>

*/

#ifndef MP3_TRIGGER_FLAGS_H
#define MP3_TRIGGER_FLAGS_H

// workaround for serial devices not having
// a useful (for us) base type
#ifdef TRIGGER_SOFT_SERIAL
#define SERIAL_DEVICE SoftwareSerial
#else
#define SERIAL_DEVICE HardwareSerial
#endif

#endif
