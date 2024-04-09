#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
void print_vec(const std::vector<T>& vec)
{
    std::cout << "vec[";
    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename K, typename V>
void print_map(const std::map<K, V>& m)
{
    for (const auto& kv : m) {
        std::cout << kv.first << ":" << kv.second << std::endl;
    }
}

using namespace std::literals;

int32_t main(int, char**)
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    print_vec(vec);

    std::map<std::string, int32_t> m = { { "a", 1 }, { "b", 2 }, { "c", 3 }, { "d", 4 }, { "e", 5 } };

    print_map(m);

    auto strs = { "a"s, "b"s, "c"s };

    for (const auto& str : strs) {
        std::cout << str << std::endl;
    }

    return 0;
}
