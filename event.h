#ifndef __EVENT_H__
#define __EVENT_H__

typedef enum {
    //event_test.c
    HAVE_DATA_TO_HANDLE,
    HAVE_COMMAND_TO_HANDLE,
    TEST_EVENT,
    
    //led.c
    LED_COLOR_ON,
    ALL_LED_OFF,

    MAX_EVENT
}Event;

#endif

