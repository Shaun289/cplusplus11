#include <memory>
#include <vector>
#include <iostream>

class MyClass
{
    public:
        int32_t i;
        int32_t j;
};

int32_t main()
{
    MyClass mc[10];
    std::vector<MyClass*> v;

    for (int32_t i = 0; i < 10; i++) {
        mc[i].i = i;
        mc[i].j = i*100;
        v.push_back(&(mc[i]));
    }

    for (auto a: v) {
        std::cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << a->i << " " << a->j << std::endl;
    }
    return 0;
}

/*
 * result
 0 0
 1 100
 2 200
 3 300
 4 400
 5 500
 6 600
 7 700
 8 800
 9 900
 */
