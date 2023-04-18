#pragma once

#include <stdint.h>
#include <vector>

class MovingAvgFilter {
    public:
    MovingAvgFilter(uint32_t window_size);
    float process(float val);

    private:
    uint32_t moving_window_size;

    // TODO: use circular buffer for avoiding reallocating memory
    std::vector<float> data;
};