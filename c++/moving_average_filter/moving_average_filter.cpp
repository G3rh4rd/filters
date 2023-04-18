#include "moving_average_filter.hpp"

MovingAvgFilter::MovingAvgFilter(uint32_t window_size) {
    this->moving_window_size = window_size;
    this->data.resize(window_size);
}

MovingAvgFilter::~MovingAvgFilter() {
    this->data.clear();
}

float MovingAvgFilter::process(float val) {
    if(this->data.size() == moving_window_size) {
        this->data.erase(this->data.begin());
    }
    
    this->data.push_back(val);

    float sum = 0.f;
    for(uint32_t i = 0; i < this->data.size(); i++) {
        sum += val;
    }

    return (sum / (float)this->data.size());
}