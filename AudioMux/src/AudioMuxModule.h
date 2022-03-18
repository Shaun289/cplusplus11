#ifndef __AUDIO_MUX_MODULE_H
#define __AUDIO_MUX_MODULE_H

#include <thread>


class AudioMuxModule
{
protected:
    bool _running;
    std::thread _thread;

public:
    AudioMuxModule() : _running(false) {};
    ~AudioMuxModule() {};

    virtual void run();
    virtual void stop();
    bool isRunning() { return _running; };

    virtual void mainLoop() = 0;
};

#endif //  __AUDIO_MUX_MODULE_H

