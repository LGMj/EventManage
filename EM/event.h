#ifndef __EVENT_H__
#define __EVENT_H__

#define EVENT_LIST                \
    EVENT(HAVE_DATA_TO_HANDLE)    \
    EVENT(HAVE_COMMAND_TO_HANDLE) \
    EVENT(TEST_EVENT)             \
    EVENT(LED_COLOR_ON)           \
    EVENT(ALL_LED_OFF)            \

typedef enum {

#define EVENT(event) event,
    EVENT_LIST
#undef EVENT

    MAX_EVENT
}Event;

#endif
