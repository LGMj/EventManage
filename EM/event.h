#ifndef __EVENT_H__
#define __EVENT_H__

#define EVENT_LIST                \
    EVENT(evHaveDataToHandle)    \
    EVENT(evHaveCommandToHandle) \
    EVENT(evTestEvent)             \
    EVENT(evLedColorOn)           \
    EVENT(evAllLedOff)            \

typedef enum {

#define EVENT(event) event,
    EVENT_LIST
#undef EVENT

    MAX_EVENT
}Event;

#endif
