#include <iostream>
#include <chrono>

#include "Encoder.h"

Encoder::Encoder()
    : AudioMuxModule()
{
}

void Encoder::stop()
{
    if (!_running) {
        return;
    }
    _running = false;
    _cv.notify_all();
    _thread.join();
}

void Encoder::mainLoop()
{
    while (_running) {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _cv.wait(lock, [&]() {
                return !_dataQueue.empty() || !_running;
            });
        }
        while (!_dataQueue.empty()) {
            AudioData audio_data = _dataQueue.front(); 
            _dataQueue.pop(); 
            std::cout << "Encoding AudioData id:" << audio_data.id() << std::endl;
        }
        if (!_running) { // after clear queue
            break;
        }
    };
}

void Encoder::push(AudioData data)
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _dataQueue.push(data);
    }
    _cv.notify_one();
}
