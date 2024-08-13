#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include <stdbool.h>
#include "event.h"

// #define EM_LOG_LEVEL_EVENT
#define EM_LOG_LEVEL_INFO
// #define EM_LOG_LEVEL_ERROR
// #define EM_LOG_LEVEL_NONE  // 不输出任何日志

#ifdef EM_LOG_LEVEL_EVENT
#define EM_LOG_EVENT(event) printf("\033[0m\033[36mEM_EVENT:\033[0m\033[34;1m%s\033[0m\n", eventString[event])
#define EM_LOG_INFO(fmt, ...) ((void)0)
#define EM_LOG_ERROR(fmt, ...) ((void)0)
#elif defined(EM_LOG_LEVEL_INFO)
#define EM_LOG_EVENT(event) printf("\033[0m\033[36mEM_EVENT:\033[0m\033[34;1m%s\033[0m\n", eventString[event])
#define EM_LOG_INFO(fmt, ...) printf("\033[0m\033[32mEM_INFO:\033[0m\033[30m" fmt "\033[0m", ##__VA_ARGS__)
#define EM_LOG_ERROR(fmt, ...) printf("\033[0m\033[31;1mEM_ERROR:" fmt "\033[0m", ##__VA_ARGS__)
#elif defined(EM_LOG_LEVEL_ERROR)
#define EM_LOG_EVENT(event) printf("\033[0m\033[36mEM_EVENT:\033[0m\033[34;1m%s\033[0m\n", eventString[event])
#define EM_LOG_INFO(fmt, ...) ((void)0)  // INFO级别被禁用
#define EM_LOG_ERROR(fmt, ...) printf("\033[0m\033[31;1mEM_ERROR:" fmt "\033[0m", ##__VA_ARGS__)
#else
#define EM_LOG_EVENT(event) ((void)0)  // 禁用所有日志
#define EM_LOG_INFO(fmt, ...) ((void)0)
#define EM_LOG_ERROR(fmt, ...) ((void)0)
#endif

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

