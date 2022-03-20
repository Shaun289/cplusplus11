#include <future>
#include <iostream>

int fn()
{
    std::cout << "async fn" << std::endl;
    return 42;
}

// 출처 : https://youtu.be/Urv11u-hqfM
// g++ -std=c++11 -pthread async.cpp
int main()
{
    std::future<int> fut = std::async(std::launch::async, fn);
    const int num = fut.get();

    std::cout << "return num" << num << std::endl;
}
