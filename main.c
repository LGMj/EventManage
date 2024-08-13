#include <stdio.h>
#include "event_manager.h"
#include "event_test.h"
#include <stdlib.h>
#include <string.h>
#include "led.h"

int main(void) {
    HandleFunc_t handleFunctions[] = {
        {HAVE_DATA_TO_HANDLE,    HANDLE_DATA_FUNC(handleData)},
        {HAVE_DATA_TO_HANDLE,    NO_DATA_FUNC(allLedOff)},
        {HAVE_COMMAND_TO_HANDLE, NO_DATA_FUNC(handleCommand)},
        {HAVE_COMMAND_TO_HANDLE, NO_DATA_FUNC(allLedOff)},
        {TEST_EVENT,             HANDLE_DATA_FUNC(handleData)},
        {LED_COLOR_ON,           HANDLE_DATA_FUNC(handleLedOn)},
        {ALL_LED_OFF,            NO_DATA_FUNC(allLedOff)}
    };

    RegisterHandleFunctions(handleFunctions);

    uint8_t buff[4] = {3, 1, 9, 2};
    ArrayData *data = malloc(sizeof(ArrayData) + NUM_OF_ARRAY(buff));
    data->data_size = NUM_OF_ARRAY(buff);
    memcpy(data->data, buff, NUM_OF_ARRAY(buff));
    
    PostEvent(HAVE_DATA_TO_HANDLE, data);
    PostEvent(HAVE_COMMAND_TO_HANDLE);
    PostEvent(TEST_EVENT);
    free(data);

    LED_COLOR led_color = {RED};
    PostEvent(LED_COLOR_ON, &led_color);
    PostEvent(ALL_LED_OFF, NULL);
    
    return 0;
}

