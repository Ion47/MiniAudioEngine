#pragma once
#include "AudioBuffer.h"

class AudioSource{
public:
    virtual ~AudioSource() = default;

    virtual void prepare(double sampleRate, std::size_t blockSize) = 0; //setam samplerate,alloc memori,resetare
    virtual void process(AudioBuffer& buffer) = 0; //se executa in bucla si genereaza sunet
    virtual void reset()=0;
};
