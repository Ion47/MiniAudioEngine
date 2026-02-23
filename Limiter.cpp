#include "Limiter.h"

void Limiter::setThreshold(float threshold){
    mThreshold = threshold;
}

void Limiter::process(float* data, std::size_t numSamples){
    for(std::size_t i = 0; i<numSamples; ++i){
        if(data[i]>mThreshold)
            data[i]=mThreshold;
        else if(data[i]<-mThreshold)
            data[i]=-mThreshold;
    }
}
