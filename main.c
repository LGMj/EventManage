#include <stdio.h>
#include "event_manager_center.h"
#include "event_test.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
    uint8_t buff[4] = {3, 1, 9, 2};
    ArrayData *data = malloc(sizeof(ArrayData) + NUM_OF_ARRAY(buff));
    data->data_size = NUM_OF_ARRAY(buff);
    memcpy(data->data, buff, NUM_OF_ARRAY(buff));

    test_init();
    PostEventWithData(HAVE_DATA_TO_HANDLE, data);
    PostEvent(HAVE_COMMAND_TO_HANDLE);
    PostEvent(TEST_EVENT);
    free(data);
    return 0;
}

