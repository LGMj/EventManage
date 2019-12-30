#include "event_test.h"
#include <stdio.h>

void test_init(void) {
    HandleFunc_t testHandleFunctions[] = {
        {HAVE_DATA_TO_HANDLE,    HANDLE_DATA_FUNC(handleData)},
        {HAVE_DATA_TO_HANDLE,    NO_DATA_FUNC(ledOn)},
        {HAVE_COMMAND_TO_HANDLE, NO_DATA_FUNC(handleCommand)},
        {HAVE_COMMAND_TO_HANDLE, NO_DATA_FUNC(ledOff)},
        {TEST_EVENT,             HANDLE_DATA_FUNC(handleData)}
    };

    RegisterHandleFunctions(testHandleFunctions);
}

void handleData(DataType data) {
    if(data == NULL) {
        printf("Data is NULL\n");
        return;
    }

    ArrayData *tmp_data = (ArrayData*)data;
    printf("Data: ");
    for(int i=0; i<tmp_data->data_size; i++) {
        printf("%d ", tmp_data->data[i]);
    }
    printf("\n");
}

void handleCommand(void) {
    printf("Handle command\n");
    printf("Get 103 cmd\n");
}

void ledOn(void) {
    printf("LED ON\n");
}

void ledOff(void) {
    printf("LED OFF\n");
}

