#ifndef __LED_H__
#define __LED_H__

#include "event_manager.h"

typedef enum {
    RED,
    GREEN,
    BLUE,
    MAX_COLOR
} COLOR;

typedef struct LED_COLOR_ {
    COLOR color;
} LED_COLOR;

void ledInit(void); 

#endif
