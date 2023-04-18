#include "moving_median_filter.hpp"

#include <algorithm>

// TODO: make sure size is uneven
MedianFilter1d::MedianFilter1d(uint32_t size) {
    this->moving_window_size = size;
}

MedianFilter1d::~MedianFilter1d() {
    this->data.clear();
}

float MedianFilter1d::process(float val) {
    float retVal = val;
    if(this->data.size() < this->moving_window_size) {
        this->data.push_back(val);
    } else {
        this->data.erase(this->data.begin());

        this->data.push_back(val);

        std::vector<float> sortedVector;
        sortedVector.resize(this->data.size());

        for(uint32_t i = 0; i < sortedVector.size(); i++) {
            sortedVector[i] = this->data[i];
        }

        std::sort(sortedVector.begin(), sortedVector.end());

        retVal = sortedVector[this->moving_window_size / 2 + 1];
    }

    return retVal;
}