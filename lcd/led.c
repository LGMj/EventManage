#include "led.h"
#include <stdio.h>

void redLedOn(void) {
    printf("Red led ON!\n");
    return;
}

void greenLedOn(void) {
    printf("Green led ON!\n");
    return;
}

void BlueLedOn(void) {
    printf("Blue led ON!\n");
    return;
}

void allLedOff(void) {
    printf("All Led Off!\n");
    return;
}

void ledOn(COLOR color) {
    if(color >= MAX_COLOR)
        return;
    switch(color) {
        case RED: redLedOn(); break;
        case GREEN: greenLedOn(); break;
        case BLUE: BlueLedOn(); break;
        default: break;
    }
}

void handleLedOn(DataType data) {
    if(data == NULL) {
        printf("Data is NULL!\n");
        return;
    }

    ledOn(((LED_COLOR *) data)->color);
}
