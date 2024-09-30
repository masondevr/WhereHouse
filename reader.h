/**
 * reader.h
 * interface for the reader to be controlled
 * from the Arduino Nano via RFID module
*/

#ifndef READER_H
#define READER_H

#include <stdint.h>

#define MAX_TAGS 100
#define TAG_BYTE_LEN 20

typedef struct {
  uint8_t id[TAG_BYTE_LEN];
} rfid_t;

// private prev_ids array, updated after each difference check
static rfid_t prev_ids[MAX_TAGS];
static uint32_t num_prev_ids;

int reader_init(void);

// returns all tags detected
rfid_t* readTags(uint32_t &num_ids);

// compares curr_ids argument to static prev_ids, updates prev_ids 
// modifies removed_ids and num_removed_ids to reflect removed tags
// modifies new_ids and num_new_ids to reflect added tags
void getTagsDiff(
  const uint32_t* current_ids,
  const uint32_t current_ids_num,
  uint32_t* removed_ids,
  uint32_t &num_removed_ids,
  uint32_t* new_ids,
  uint32_t &num_new_ids);

// sends difference in tags over bluetooth to main processor
void sendTagsDiff(
  const uint32_t* removed_ids, 
  const uint32_t num_removed_ids,
  const uint32_t* added_ids,
  const uint32_t num_added_ids);

// monitors for tag request from main processor
uint8_t checkBLE_request();

#endif // READER_H