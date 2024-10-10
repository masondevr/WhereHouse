/** 
 * app.h
 * interface for the database from main processor
*/

#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <string.h>
#include "reader.h"

struct link_t {
  char* img_filename;
  rfid_t* tag;
};

void itemRemoved(const link_t link);

void itemFound(const rfid_t* item);

#endif // APP_H