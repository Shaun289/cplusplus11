#include <iostream>
#include <chrono>
#include <thread>

/**
# 성능 측정을 위한 간단히 ms 단위 측정 코드
- C++11 코드로 작성
- 명확하게 하기 위해 일부러 namespace는 사용하지 않음
- chrono_literals 의 ms 등 편리한 operator는 C++14부터 사용 가능

```
$ g++ -std=c++11 duration.cpp
$ ./a.out
Duration=1000ms
$
```

## Reference :
- https://en.cppreference.com/w/cpp/thread/sleep_for
- https://en.cppreference.com/w/cpp/chrono/system_clock/now
- https://en.cppreference.com/w/cpp/chrono/duration/duration_cast
 */

int main(int argc, char* argv[])
{
    auto in_t = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto diff_t = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - in_t);
    std::cout << "Duration=" << diff_t.count() << "ms" << std::endl;
    return 0;
}
