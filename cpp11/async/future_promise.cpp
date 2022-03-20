#include <future>
#include <iostream>
#include <thread>

// https://youtu.be/2mu4Wg74W0E
// g++ -std=c++11 -pthread future_promise.cpp

void fn(std::promise<int> prm)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prm.set_value(42);
}

int main()
{
    std::promise<int> prms;
    std::future<int> fut = prms.get_future();

    std::thread t(fn, std::move(prms));
    while (fut.wait_for(std::chrono::milliseconds(200)) != std::future_status::ready) {
        std::cout << "doing other work" << std::endl;
    }
    const int num = fut.get();
    std::cout << "num: " << num << std::endl;
    t.join();

    return 0;
}

