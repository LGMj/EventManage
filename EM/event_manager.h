#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <stdbool.h>
#include "event.h"

#define HANDLE_DATA  true
#define NO_DATA      false

#define DataType void *

#define HANDLE_DATA_FUNC(func) HANDLE_DATA, {.handleEventWithDataFunc = func}
#define NO_DATA_FUNC(func)     NO_DATA,     {.handleEventFunc = func}

#define NUM_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define RegisterHandleFunctions(handleFuncs) registerHandleFunctions(handleFuncs, NUM_OF_ARRAY(handleFuncs))
#define PostEvent(event, ...) PostEventDispatcher(event, ##__VA_ARGS__, NULL)

#define PostEventDispatcher(event, data, ...) \
    _Generic((data), default: PostEventWithData(event, data))

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
void PostEventWithData(Event event, DataType data);

#endif

