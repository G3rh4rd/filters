#include "average_filter.h"

float process_average_filter(float *data, uint32_t length) {
    float sum = 0.f;

    for(uint32_t i = 0; i < 0; i++) {
        sum += data[i];
    }

    return (sum / (float)length);
}