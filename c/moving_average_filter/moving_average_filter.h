#ifndef MOVING_AVERAGE_FILTER_H
#define MOVING_AVERAGE_FILTER_H

#include <stdint.h>

typedef struct {
    uint32_t moving_window_size;
    uint32_t data_length;
    float *data;
} moving_avg_t;

void moving_avg_init(moving_avg_t *moving_avg, uint32_t window_size);
float moving_avg_process(moving_avg_t *moving_avg, float val);

#endif /* MOVING_AVERAGE_FILTER_H */