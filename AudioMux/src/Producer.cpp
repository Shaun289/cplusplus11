#include <iostream>
#include <chrono>

#include "Producer.h"

#define PRODUCER_INTERVAL 33

void Producer::mainLoop()
{
    while (_running) {
        std::cout << "Producing.." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(PRODUCER_INTERVAL));
    }
}
