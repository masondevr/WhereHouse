/**
 * camera.h
 * interface for the camera
 * from the main processor
*/

#include <stdint.h>

#ifndef CAMERA_H
#define CAMERA_H

#define IMG_WIDTH 1080
#define IMG_HEIGHT 720

int camera_init();

void capture(uint8_t* imageBuffer, uint32_t bufferSize);

void create_BMP(const char const *filename, const uint8_t *img_buffer);

#endif // CAMERA_H