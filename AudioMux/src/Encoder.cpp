#include <iostream>
#include <chrono>

#include "Encoder.h"

void Encoder::mainLoop()
{
    while (_running) {
        std::cout << "Encoding.." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
}
