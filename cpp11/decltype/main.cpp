#include <iostream>

template <typename T>
auto plus(T a, T b) -> decltype(a + b)
{
    return a + b;
}

int32_t main(int32_t, char**)
{
    int32_t a = 1;
    int32_t b = 2;

    std::cout << "decltype test a+b=" << plus<int32_t>(a, b) << std::endl;

    return 0;
}
