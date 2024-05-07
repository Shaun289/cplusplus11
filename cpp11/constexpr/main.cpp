#include <iostream>
#include <type_traits>

template <int N>
struct A {
    int operator()()
    {
        return N;
    }
};

constexpr int Factorial(int N)
{
    int total = 1;

    for (int i = 1; i <= N; i++) {
        total *= i;
    }

    return total;
}

template <typename T>
void show_value(T t)
{
    if constexpr (std::is_pointer_v<T>) {
        std::cout << "It's a pointer : " << *t << std::endl;
    } else {
        std::cout << "It's not a pointer : " << t << std::endl;
    }
}

int main()
{
    constexpr int size = 3;
    int arr[size] = {
        0,
    };

    constexpr int N = 10;
    A<N> a;
    std::cout << a() << std::endl;

    const int num = 3;

    enum B { x = num, y, z };

    std::cout << B::x << std::endl;
    std::cout << B::y << std::endl;
    std::cout << B::z << std::endl;

    /* constexpr vs const
     * const는 컴파일 타임에 알수 없음
     * constexpr은 컴파일 타임에 알 수 있음
     */

    /* constexpr function.
     * 컴파일 타임에 컴파일러가 값을 알 수 있음
     * 컴파일 시간은 더 걸리겠네
     */

    A<Factorial(10)> b;
    std::cout << b() << std::endl;

    /* if constexpr
     * 타입에 따라 형태가 달라지는 함수
     */
    int v = 3;
    int* v_p = &v;

    show_value(v);
    show_value(v_p);

    return 0;
}
