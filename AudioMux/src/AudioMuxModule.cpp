#include "AudioMuxModule.h"

void AudioMuxModule::run() {
    if (_running) {
        return;
    }
    _running = true;
    _thread = std::thread(&AudioMuxModule::mainLoop, this);
}

void AudioMuxModule::stop() {
    if (!_running) {
        return;
    }
    _running = false;
    _thread.join();
}
