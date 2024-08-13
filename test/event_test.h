#ifndef __EVENT_TEST_H__
#define __EVENT_TEST_H__
#include <stdint.h>
#include "event_manager.h"

typedef struct ArrayData_ {
    uint8_t data_size;
    uint8_t data[0];
} ArrayData;

void handleData(DataType data);
void handleCommand(void);

#endif

