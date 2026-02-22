#pragma once

#include <vector>



class AudioBuffer{
public:
    AudioBuffer(std::size_t numChannels, std::size_t numSamples);

    float* getWritePointer(std::size_t channel);
    const float* getReadPointer(std::size_t channel) const;

    std::size_t getNumChannels() const;
    std::size_t getNumSamples() const;

    void clear();

private:
    std::size_t mNumChannels;
    std::size_t mNumSamples;

    std::vector<std::vector<float>> mData;
    //mData[channel][sample]
    //mData[0/1][100] -> sample 100 din canalul stang/drept
};
