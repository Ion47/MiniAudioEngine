#pragma once
#include <cstddef>

class Limiter{
public:
    void setThreshold(float threshold);
    void process(float* data, std::size_t numSamples);

private:
    float mThreshold = 0.95f;
};
