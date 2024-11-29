#include <iostream>

class C
{
    private:
        int _data;

    public:
        C(int data) {
            _data = data;
            std::cout << "constructor" << std::endl;
        }
        C(const C& rhs) { 
            _data = rhs.data();
            std::cout << "copy constructor" << std::endl;
        }

        int data() const { return _data; }
        void setData(int data) { _data = data; }
};

C returnC1()
{
    C c1(0);
    c1.setData(1);
    return c1;
}

int main(int argc, char* argv[])
{
    /* constructor
       c1=1
    */
    C c1 = returnC1();
    std::cout << "c1=" << c1.data() << std::endl;

    return 0;
}
