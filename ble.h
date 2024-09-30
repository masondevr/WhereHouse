/**
 * ble.h
 * interface for bluetooth from any controller
*/

#ifndef BLE_H
#define BLE_H

#include <stdint.h>

int ble_init(void);

void sendPacket(const uint8_t* data, const uint32_t size);

void receivePacket(uint8_t* buffer, uint32_t &bufferSize);

int ble_isConnected(void);

#endif // BLE_H