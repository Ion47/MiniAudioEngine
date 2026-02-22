#pragma once
#include "AudioBuffer.h"
#include "AudioSource.h"
#include <vector>
#include <memory>
#include <algorithm>

class AudioEngine{
public:
    AudioEngine(std::size_t numChannels, std::size_t bufferSize, double sampleRate);

    void addSource(std::shared_ptr<AudioSource> source);
    void removeSource(std::shared_ptr<AudioSource> source);

    void processBlock();

    AudioBuffer& getBuffer() { return mBuffer; }

private:
    AudioBuffer mBuffer;
    double mSampleRate;
    std::vector<std::shared_ptr<AudioSource>> mSources;

};
