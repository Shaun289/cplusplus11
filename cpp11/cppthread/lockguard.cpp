#include <thread>
#include <mutex>
#include <iostream>

/**
# C++11 thread lock_guard
- RAII(Resource Acquisition Is Initialization) 매커니즘을 사용한 안전한 mutex wrapper

- lock_guard를 하지 않았을 경우 

```
$ g++ -std=c++11 -pthread ./lockguard.cpp
$ ./a.out
sum:1281187
```

- lock_guard를 할 경우

```
$ !g
$ g++ -std=c++11 -pthread ./lockguard.cpp
$ ./a.out
sum:3000000
```

# Reference
- https://en.cppreference.com/w/cpp/thread/lock_guard
 */

int32_t g_sum = 0;
std::mutex g_mutex;

void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_mutex);

    for (int32_t i = 0; i < 1000000; i++) {
        ++g_sum;
    }
}

int main(int argc, char* argv[])
{
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
    std::thread t3(safe_increment);
    t1.join();
    t2.join();
    t3.join();

    std::cout << "sum:" << g_sum << std::endl;

    return 0;
}
