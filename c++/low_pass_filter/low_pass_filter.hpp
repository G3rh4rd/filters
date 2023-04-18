#pragma once

class LowPassFilter {
    public:
        LowPassFilter(float alpha, float initial_val);

        float process(float val);

    private:
        float alpha;
        float val;
};