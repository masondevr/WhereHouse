/**
 * distance.h
 * interface for the distance sensor
 * from the main processor
*/

#ifndef DISTANCE_H
#define DISTANCE_H

#include <stdint.h>

#define DOOR_OPEN 1
#define DOOR_CLOSED 0

uint8_t getDoorStatus();

#endif // DISTANCE_H