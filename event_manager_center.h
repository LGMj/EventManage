#ifndef __EVENT_MANAGER_CENTER_H__
#define __EVENT_MANAGER_CENTER_H__

#include <stdbool.h>

#define HANDLE_DATA  true
#define NO_DATA      false

#define DataType void *

#define HANDLE_DATA_FUNC(func) HANDLE_DATA, {.handleEventWithDataFunc = func}
#define NO_DATA_FUNC(func)     NO_DATA,     {.handleEventFunc = func}

#define NUM_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define RegisterHandleFunctions(handleFuncs) registerHandleFunctions(handleFuncs, NUM_OF_ARRAY(handleFuncs))

typedef enum {
    HAVE_DATA_TO_HANDLE,
    HAVE_COMMAND_TO_HANDLE,
    TEST_EVENT,
    MAX_EVENT
}Event;

typedef void (*HandleEVENT)(void);
typedef void (*HandleEventWithData_t)(DataType data);

typedef struct HandleFunc_ {
    Event event;
    bool handle_data;
    union {
        HandleEVENT handleEventFunc;
        HandleEventWithData_t handleEventWithDataFunc;
    };
} HandleFunc_t;

void registerHandleFunctions(HandleFunc_t *handleFuncs, int funNum);
void PostEvent(Event event);
void PostEventWithData(Event event, DataType data);

#endif

