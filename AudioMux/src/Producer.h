#ifndef __PRODUCER_H
#define __PRODUCER_H

#include "AudioMuxModule.h"

class Producer : public AudioMuxModule
{
    virtual void mainLoop();
};

#endif // __PRODUCER_H
