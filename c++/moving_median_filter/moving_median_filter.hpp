#pragma once

#include <stdint.h>
#include <vector>

class MedianFilter1d {
    public:
    MedianFilter1d(uint32_t size);
    float process(float val);
    
    private:
    uint32_t moving_window_size;

    // TODO: use circular buffer for avoiding reallocating memory
    std::vector<float> data;
};