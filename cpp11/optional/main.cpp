#include <iostream>
#include <map>
#include <string>
#include <utility>

std::optional<std::string> getValueForMap(const std::map<int, std::string>& m, int key)
{
    auto iter = m.find(key);
    if (iter != m.end()) {
        return iter->second;
    }
    return std::nullopt;
}

int main()
{
    std::map<int, std::string> data = { { 1, "hi" }, { 2, "hello" }, { 3, "aloha" } };

    std::cout << "2:" << getValueForMap(data, 2).value() << std::endl;
    auto opt_val = getValueForMap(data, 4);
    std::cout << "4: isExist? " << std::boolalpha << opt_val.has_value() << std::endl;

    return 0;
}
