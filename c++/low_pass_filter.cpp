#include "low_pass_filter.hpp"

LowPassFilter::LowPassFilter(float alpha, float initial_val) {
    // clamp alpha to make sure it's between 0 and 1
    if(alpha > 1.f) alpha = 1.f;
    else if(alpha < 0.f) alpha = 0.f;

    this->alpha = alpha;
    this->val = initial_val;
}

float LowPassFilter::process(float val) {
    float filtered_val = (this->alpha * this->val) + ((1.f - this->alpha) * val);
    this->val = filtered_val;

    return filtered_val;
}