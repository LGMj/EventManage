#include "led.h"
#include <stdio.h>

static void redLedOn(void) {
    printf("Red led ON!\n");
    return;
}

static void greenLedOn(void) {
    printf("Green led ON!\n");
    return;
}

static void BlueLedOn(void) {
    printf("Blue led ON!\n");
    return;
}

static void allLedOff(void) {
    printf("All Led Off!\n");
    return;
}

static void ledOn(COLOR color) {
    if(color >= MAX_COLOR)
        return;
    switch(color) {
        case RED: redLedOn(); break;
        case GREEN: greenLedOn(); break;
        case BLUE: BlueLedOn(); break;
        default: break;
    }
}

static void handleLedOn(DataType data) {
    if(data == NULL) {
        printf("Data is NULL!\n");
        return;
    }

    ledOn(((LED_COLOR *) data)->color);
}

void ledInit(void) {
    HandleFunc_t ledHandleFunctions[] = {
        {LED_COLOR_ON, HANDLE_DATA_FUNC(handleLedOn)},
        {ALL_LED_OFF,  NO_DATA_FUNC(allLedOff)}
    };    

    RegisterHandleFunctions(ledHandleFunctions);
}

