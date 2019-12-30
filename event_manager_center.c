#include "event_manager_center.h"
#include <stdio.h>
#include <stdlib.h>
#include "event_test.h"

typedef struct handleFuncNode_t {
    HandleFunc_t handleFunc;
    struct handleFuncNode_t *next;
}HandleFuncNode_t, *HandleFuncList_t;

HandleFuncList_t EventHandles[MAX_EVENT] = {NULL, };

static void createEventHandles(HandleFuncList_t *handleListArray) {
    for(int i=0; i<MAX_EVENT; i++) {
        HandleFuncNode_t *node = malloc(sizeof(HandleFuncNode_t));
        node->next = NULL;
        handleListArray[i] = node;
    }
}

static void addHandleFuncToList(HandleFuncList_t L, HandleFunc_t *handleFunc) {
    if(handleFunc == NULL) {
        printf("handleFunc is NULL\n");
        return;
    }

    HandleFuncNode_t *node = malloc(sizeof(HandleFuncNode_t));
    node->handleFunc.event = handleFunc->event;
    node->handleFunc.handle_data = handleFunc->handle_data;

    if(handleFunc->handle_data)
        node->handleFunc.handleEventWithDataFunc = handleFunc->handleEventWithDataFunc;
    else
        node->handleFunc.handleEventFunc = handleFunc->handleEventFunc;
    node->next = NULL;

    HandleFuncNode_t *lastNode = L;
    while(lastNode->next) {
        lastNode = lastNode->next;
    }
    lastNode->next = node;
}

void registerHandleFunctions(HandleFunc_t *handleFuncs, int funNum) {
    if(handleFuncs == NULL) {
        printf("handleFuncs is NULL\n");
        return;
    }
    
    static uint8_t i=0;
    if(i == 0) {
        printf("EventHandles init\n");
        createEventHandles(EventHandles);
        i = 1;
    }

    for(int i=0; i<funNum; i++) {
        addHandleFuncToList(EventHandles[handleFuncs[i].event], &handleFuncs[i]); 
    }
}

static void handleEventAndData(Event event, DataType data) {
    HandleFuncList_t funcList = EventHandles[event];
    if(funcList == NULL) {
        printf("FuncList is NULL\n");
        return;
    }

    HandleFuncNode_t *node = funcList->next;
    while(node) {
        if(node->handleFunc.handle_data)
            node->handleFunc.handleEventWithDataFunc(data);
        else
            node->handleFunc.handleEventFunc();
        node = node->next;
    }
}

void PostEventWithData(Event event, DataType data) {
    if(event >= MAX_EVENT)
        return;

    printf("EMC: event: %d\n", event);    
    handleEventAndData(event, data);
}

void PostEvent(Event event) {
    PostEventWithData(event, NULL);
}

