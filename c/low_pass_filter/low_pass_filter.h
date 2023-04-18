#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

typedef struct {
    float alpha;
    float value;
} low_pass_filter_t;

void init_low_pass_filter(low_pass_filter_t* low_pass_filter, float alpha, float initial_val);

float process_low_pass_filter(low_pass_filter_t* low_pass_filter, float val);

#endif /* LOW_PASS_FILTER_H */