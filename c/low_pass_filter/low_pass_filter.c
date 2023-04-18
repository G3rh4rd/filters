#include "low_pass_filter.h"

void init_low_pass_filter(low_pass_filter_t* low_pass_filter, float alpha, float initial_val) {
    // clamp alpha to make sure it's between 0 and 1
    if(alpha > 1.f) alpha = 1.f;
    else if(alpha < 0.f) alpha = 0.f;

    // initialize object with it's initial values
    low_pass_filter->alpha = alpha;
    low_pass_filter->value = initial_val;
}

float process_low_pass_filter(low_pass_filter_t* low_pass_filter, float val) {
    float filtered_val = (low_pass_filter->alpha * low_pass_filter->value) + ((1.f - low_pass_filter->alpha) * val);
    low_pass_filter->value = filtered_val;

    return filtered_val;
}