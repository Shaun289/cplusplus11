#include <iostream>

#include "Generator.h"
#include "Encoder.h"

int main(int argc, char* argv[])
{
    Generator producer;
    Encoder encoder;

    producer.setEncoder(&encoder);

    producer.run();
    encoder.run();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    producer.stop();
    encoder.stop();

    return 0;
}
