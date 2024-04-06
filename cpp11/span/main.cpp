#include <array>
#include <cstdint>
#include <iostream>
#include <span>
#include <string>
#include <vector>

template <typename T>
void print(const std::span<T>& span)
{
    for (const auto& val : span) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int32_t main(int32_t, char**)
{
    std::array<int32_t, 3> arr = { 1, 2, 3 };
    std::vector<int32_t> vec = { 4, 5, 6 };
    int32_t arrN[3] = { 7, 8, 9 };
    std::string str = "Hello span!";

    print<int32_t>(arr);
    print<int32_t>(vec);
    print<int32_t>(arrN);
    print<char>(str);

    return 0;
}
