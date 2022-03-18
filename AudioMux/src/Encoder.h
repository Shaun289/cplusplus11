#ifndef __ENCODER_H
#define __ENCODER_H

#include <condition_variable>

#include "AudioMuxModule.h"

class Encoder : public AudioMuxModule
{
private:
    std::condition_variable _cv;

public:
    Encoder() : AudioMuxModule() {};
    ~Encoder() {};

    virtual void mainLoop();

    void signal();
};

#endif // __ENCODER_H
