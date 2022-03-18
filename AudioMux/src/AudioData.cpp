#include <iostream>

#include "AudioData.h"

AudioData::AudioData()
    : _id(0)
    , _data('a')
    , _tick(std::chrono::system_clock::now())
{
}

AudioData::AudioData(uint32_t id, char data)
    : _id(id)
    , _data(data)
    , _tick(std::chrono::system_clock::now())
{
}

void AudioData::print() {
    std::cout << "AudioData id:" << _id << " tick:" << std::chrono::system_clock::to_time_t(_tick) << "s" << std::endl;
}
