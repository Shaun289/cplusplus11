#include <iostream>

#include "Producer.h"
#include "Encoder.h"

int main(int argc, char* argv[])
{
    Producer producer;
    Encoder encoder;

    producer.run();
    encoder.run();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    producer.stop();
    encoder.stop();

    return 0;
}
