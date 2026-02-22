#include "AudioBuffer.h"
#include <algorithm>

AudioBuffer::AudioBuffer(std::size_t numChannels, std::size_t numSamples)
    : mNumChannels(numChannels),
    mNumSamples(numSamples),
    mData(numChannels, std::vector<float>(numSamples, 0.0f))
{

}

float* AudioBuffer::getWritePointer(std::size_t channel){ //scriere/modificare
    return mData[channel].data();
}

const float* AudioBuffer::getReadPointer(std::size_t channel) const{ //citire/ascultare
    return mData[channel].data();
}

std::size_t AudioBuffer::getNumChannels() const{ //citeste cate canale are
    return mNumChannels;
}

std::size_t AudioBuffer::getNumSamples() const{ //citeste cate sample are
    return mNumSamples;
}

void AudioBuffer::clear(){ //curatare
    for(auto& channel : mData){
        std::fill(channel.begin(), channel.end(), 0.0f);
    }
}
