#include "event_test.h"
#include <stdio.h>

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
