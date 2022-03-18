#ifndef __ENCODER_H
#define __ENCODER_H

#include <condition_variable>
#include <queue>
#include <mutex>

#include "AudioData.h"
#include "AudioMuxModule.h"

class Encoder : public AudioMuxModule
{
private:
    std::mutex _mutex;
    std::condition_variable _cv;
    std::queue<AudioData> _dataQueue;

public:
    Encoder();
    ~Encoder() {};

    virtual void stop();
    virtual void mainLoop();

    void signal();
    void push(AudioData data);
};

#endif // __ENCODER_H
