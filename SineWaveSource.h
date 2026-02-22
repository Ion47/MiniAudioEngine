#pragma once
#include "AudioSource.h"
#include <cmath>



class SineWaveSource : public AudioSource{
public:
    SineWaveSource(float frecquency, float amplitude) : mFrecquency(frecquency), mAplitude(amplitude) {}

    void prepare(double sampleRate, std::size_t blockSize) override{ //viteza
        mSampleRate = sampleRate;
        mPhase = 0.0;
        mPhaseIncrement = 2.0 * M_PI * mFrecquency / mSampleRate; //phaseIncrement=2πf/sampleRate
    }

    void process(AudioBuffer& buffer) override{ //genereaza sunetul
        std::size_t numSamples = buffer.getNumSamples();
        float* left = buffer.getWritePointer(0); //acces canale stanga dreapta
        float* right = buffer.getWritePointer(1);

        for(std::size_t i=0;i<numSamples;++i){
            float sample = mAplitude * std::sin(mPhase); //calculeaza unda la momentul precis
            left[i] += sample; //aduni "sunetul" peste ce exista in buffer
            right[i] += sample;

            mPhase += mPhaseIncrement;  //avans la urmatoarea pozitie
            if(mPhase > 2.0 * M_PI)
                mPhase -= 2.0 * M_PI;
        }
    }

    void reset() override{
        mPhase = 0.0;
    }

private:
    float mFrecquency; // nota pe care o auzi 440hz
    float mAplitude;//volumul

    double mSampleRate;
    double mPhase;//pozitia pe valul sinusoidei
    double mPhaseIncrement;
};
