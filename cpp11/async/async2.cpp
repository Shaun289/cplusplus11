#include <future>
#include <iostream>
#include <thread>

// https://youtu.be/7tBBiC61oJ0
// g++ -std=c++11 -pthread async2.cpp
int add1(int n)
{
    std::cout << __func__ << std::endl;
    return n + 1;
}

int main()
{
    int num = 42;

    // async or deferred 어떤 식으로 실행할지 알 수 없으므로
    // 반드시 async policy를 async로 줘야 thread로 실행함
    std::future<int> fut = std::async(std::launch::async, add1, num);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << __func__ << std::endl;
    const int ret = fut.get();
    std::cout << "ret: " << ret << std::endl;

    return 0;
}
