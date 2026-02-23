#pragma once
#include <vector>
#include <cmath>

class LowPassFilter{
public:
    LowPassFilter() = default;

    void prepare(double sampleRate, std::size_t numChannels){
        mSampleRate = sampleRate;
        mZ1.assign(numChannels, 0.0f);
    }

    void setCutoff(float cutoff){
        float x =2.0f * M_PI * cutoff;
        mAlpha = x/(x+mSampleRate);
    }

    void process(float* samples, std::size_t numSamples, std::size_t channel){
        float z1 = mZ1[channel];

        for(std::size_t i=0;i<numSamples;++i){
            z1 = z1+mAlpha*(samples[i] - z1);
            samples[i] = z1;
        }
        mZ1[channel] = z1;
    }

private:
    double mSampleRate = 48000.0;
    float mAlpha = 0.0f;
    std::vector<float> mZ1;

};
