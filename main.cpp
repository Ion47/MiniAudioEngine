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


    AudioEngine engine(2, 480, 48000);

    auto sine1 = std::make_shared<SineWaveSource>(440.0f, 0.5f);
    auto sine2 = std::make_shared<SineWaveSource>(880.0f, 0.25f);


    engine.addSource(sine1);
    engine.addSource(sine2);


    for(int i=0;i<5;++i){
        engine.processBlock();
        auto left = engine.getBuffer().getReadPointer(0);
        std::cout << "Block " << i << " first left sample: " << left[0] << "\n";
    }
}
