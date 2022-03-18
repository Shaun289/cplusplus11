#ifndef __PRODUCER_H
#define __PRODUCER_H

#include "AudioMuxModule.h"
#include "Encoder.h"

class Generator : public AudioMuxModule
{
    private:
        uint32_t _count;
        Encoder* _encoder;

        void produce();

    public:
        Generator();
        ~Generator() {};

        void setEncoder(Encoder* encoder) { _encoder = encoder; };

        virtual void mainLoop();
};

#endif // __PRODUCER_H
