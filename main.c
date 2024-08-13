#include <stdio.h>
#include "event_manager.h"
#include "event_test.h"
#include <stdlib.h>
#include <string.h>
#include "led.h"

int main(void) {
    HandleFunc_t handleFunctions[] = {
        {evHaveDataToHandle,    HANDLE_DATA_FUNC(handleData)},
        {evHaveDataToHandle,    NO_DATA_FUNC(allLedOff)},
        {evHaveCommandToHandle, NO_DATA_FUNC(handleCommand)},
        {evHaveCommandToHandle, NO_DATA_FUNC(allLedOff)},
        {evTestEvent,             HANDLE_DATA_FUNC(handleData)},
        {evLedColorOn,           HANDLE_DATA_FUNC(handleLedOn)},
        {evAllLedOff,            NO_DATA_FUNC(allLedOff)}
    };

    RegisterHandleFunctions(handleFunctions);

    uint8_t buff[4] = {3, 1, 9, 2};
    ArrayData *data = malloc(sizeof(ArrayData) + NUM_OF_ARRAY(buff));
    data->data_size = NUM_OF_ARRAY(buff);
    memcpy(data->data, buff, NUM_OF_ARRAY(buff));
    
    PostEvent(evHaveDataToHandle, data);
    PostEvent(evHaveCommandToHandle);
    PostEvent(evTestEvent);
    free(data);

    LED_COLOR led_color = {RED};
    PostEvent(evLedColorOn, &led_color);
    PostEvent(evAllLedOff, NULL);
    
    return 0;
}

