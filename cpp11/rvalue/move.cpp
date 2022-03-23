#include <iostream>
#include <string>


// https://youtu.be/6buEm6R980o
// 효율적인 l-r value move 방법

class Cat
{
    private:
        std::string _name;
    public:
        void setName(std::string name) {
            _name = std::move(name);
            std::cout << "name:" << _name << std::endl;
        }
};

int main()
{
    Cat cat;
    std::string name = "Nyangi";

    cat.setName(name); // 1 copy
    cat.setName("Navi"); // 0 copy

    return 0;
}
