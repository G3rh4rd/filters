#include "moving_average_filter.h"

void moving_avg_init(moving_avg_t *moving_avg, uint32_t window_size) {
    moving_avg->data_length = 0;
    moving_avg->moving_window_size = window_size;
    moving_avg->data = (float *)malloc(window_size * sizeof(float));
}

float moving_avg_process(moving_avg_t *moving_avg, float val) {
    if(moving_avg->data_length == moving_avg->moving_window_size) {
        // move all data to the front (pop the first element)
        for(uint32_t i = 0; i < (moving_avg->data_length - 1); i++) {
            moving_avg->data[i] = moving_avg->data[i + 1];
        }

        // add the current element
        moving_avg->data[moving_avg->data_length - 1] = val;
    } else {
        moving_avg->data[moving_avg->data_length] = val;
        moving_avg->data_length++;
    }

    float sum = 0.f;
    for(uint32_t i = 0; i < moving_avg->data_length; i++) {
        sum += moving_avg->data[i];
    }

    return (sum / (float)moving_avg->data_length);
}