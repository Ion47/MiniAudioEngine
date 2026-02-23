#include <iostream>
// #include "AudioBuffer.h"
#include "SineWaveSource.h"
#include "AudioEngine.h"

using namespace std;

int main()
{
    // AudioBuffer buffer(2, 480); //stereo, 480 samples
    // SineWaveSource sine(440.0f, 0.5f);

    // sine.prepare(48000, 480);
    // sine.process(buffer);

    // std::cout<<"First 5 samples left channel: \n";
    // for(int i=0;i<5;i++){
    //     std::cout<<buffer.getReadPointer(0)[i]<<"\n";
    // }

    // std::cout<<"\n"<<buffer.getNumChannels()<<"\n";
    // std::cout<<buffer.getNumSamples();
    // return 0;


    //SineWaveSource
    AudioEngine engine(2, 480, 48000);

    auto sine = std::make_shared<SineWaveSource>(440.0f,1.0f,1);
    engine.addSource(sine);

    engine.processBlock();

    auto left = engine.getBuffer().getReadPointer(0);

    std::cout<<"First 10 samples:\n";
    for(int i=0; i < 10; i++){
        std::cout<<left[i]<<"\n";
    }

    //

    engine.processBlock();
    float lastSample = engine.getBuffer().getReadPointer(0)[479];

    engine.processBlock();
    float firstNext = engine.getBuffer().getReadPointer(0)[0];

    std::cout << "Last sample block1: " << lastSample << "\n";
    std::cout << "First sample block2: " << firstNext << "\n";

    //Ducking

    auto sineLow = std::make_shared<SineWaveSource>(440.0f,0.5f,1);
    auto sineHigh = std::make_shared<SineWaveSource>(440.0f,0.5f,5);

    engine.addSource(sineLow);
    engine.addSource(sineHigh);

    engine.processBlock();

    std::cout<<"First 10 samples:\n";
    for(int i=0; i < 10; i++){
        std::cout<<left[i]<<"\n";
    }


    //Limiter

    AudioEngine engine2(2, 480, 48000);

    auto s1 = std::make_shared<SineWaveSource>(440.0f,1.0f,1);
    auto s2 = std::make_shared<SineWaveSource>(440.0f,1.0f,1);

    engine2.addSource(s1);
    engine2.addSource(s2);

    engine2.processBlock();

    auto left2 = engine2.getBuffer().getReadPointer(0);

    float maxVal = 0.0f;
    for(int i = 0; i < 480; ++i)
        maxVal = std::max(maxVal, std::abs(left2[i]));

    std::cout << "Max val: " << maxVal << "\n";
}
