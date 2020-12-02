#include <iostream>

class TestMutable
{
    private:
    int _data;
    mutable int _data2;

    public:
    void constTest(int data) const { 
        // mutable.cpp:10:15: error: assignment of member ‘TestMutable::_data’ in read-only object
        //_data = data; 
    };
    void mutableTest(int data) const { 
        _data2 = data; 
    };
};



int main(int argc, char* argv[])
{
    TestMutable tm;

    tm.constTest(1);

    tm.mutableTest(1);

    return 0;
}