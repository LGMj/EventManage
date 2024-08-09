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

void redLedOn(void);
void greenLedOn(void);
void BlueLedOn(void);
void allLedOff(void);
void ledOn(COLOR color);
void handleLedOn(DataType data);

#endif
