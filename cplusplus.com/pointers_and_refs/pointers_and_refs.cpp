#include <iostream>

using namespace std;

void some_function(int& i)
{
    cout << "\nvalue is " << i << endl;
}

int main()
{
    char* fp = reinterpret_cast<char*>(&some_function);
    int ii = 5;

    reinterpret_cast<void(*)(int&)>(fp)(ii);

    reinterpret_cast<void(*)(int*)>(fp)(&ii);

    return 0;
}