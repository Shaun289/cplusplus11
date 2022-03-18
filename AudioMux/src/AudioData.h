#ifndef __AUDIO_DATA_H
#define __AUDIO_DATA_H

#include <chrono>

class AudioData {
private:
    uint32_t _id;
    char _data;
    std::chrono::system_clock::time_point _tick;

public:
    AudioData(uint32_t id, char data);

    void print();
    uint32_t id() { return _id; };
};

#endif // __AUDIO_DATA_H
