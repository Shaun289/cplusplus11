#include <iostream>
#include <chrono>

#include "Generator.h"

#define PRODUCER_INTERVAL 33

Generator::Generator()
    : AudioMuxModule()
    , _count(0)
{
}

void Generator::produce()
{
    ++_count;
    _encoder->push(AudioData(_count, 'a' + (_count%26)));
}

void Generator::mainLoop()
{
    while (_running) {
        produce();
        std::this_thread::sleep_for(std::chrono::milliseconds(PRODUCER_INTERVAL));
    }
}
