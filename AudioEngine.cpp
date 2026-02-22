#include "AudioEngine.h"

AudioEngine::AudioEngine(std::size_t numChannels, std::size_t bufferSize, double sampleRate)
    : mBuffer(numChannels, bufferSize), mSampleRate(sampleRate){

}

void AudioEngine::addSource(std::shared_ptr<AudioSource> source){
    source->prepare(mSampleRate, mBuffer.getNumSamples());
    mSources.push_back(source);
}

void AudioEngine::removeSource(std::shared_ptr<AudioSource> source){
    auto it = std::find(mSources.begin(), mSources.end(), source);
    if(it != mSources.end())
        mSources.erase(it);
}

void AudioEngine::processBlock(){
    mBuffer.clear();

    for(auto& src : mSources){
        src->process(mBuffer);
    }
}

