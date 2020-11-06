#include <iostream>

using namespace std;

class A {
    int data_;

    public:
    A(int data) : data_(data) { cout << "일반 생성자 호출!" << endl;};
    A(const A& a) : data_(a.data_) { cout << "복사 생성자 호출!" << endl;};
    A(A&& a) : data_(a.data_) { cout << "이동 생성자 호출!" << endl; };
    A operator+(const A& a) { data_ += a.data_; return *this;};
    int data() { return data_;};
};

void testCopyElision()
{
    cout << "a" << endl;
    A a(1);
    cout << "b" << endl;
    A b(a);
    cout << "c" << endl;
    A c(A(2));

    cout << "d" << endl;
    A d = a + b;
    cout << "d=" << d.data() << endl;

}

string getName()
{
    return "alex";
}

void printReference(const string& str)
{
    cout << __func__ << " : lvalue " << str << endl;
}

void printReference(string&& str)
{
    cout << __func__ << " : rvalue " << str << endl;
}

void testRvalueReference()
{
    string str = "alex";
    printReference(str);
    printReference(getName());
}

class ArrayWrapper
{
    public:
    ArrayWrapper(int n) 
        : _p_vals( new int[n])
        , _size(n)
    {
        cout << "constructor!" << endl;
    }
    // copy constructor
    // 메모리 할당하고 copy 하고 일이 많음. 특히 n 사이즈가 커질수록 부하가 커짐.
    ArrayWrapper(const ArrayWrapper& other)
        : _p_vals( new int[other._size])
        , _size(other._size)
    {
        cout << "copy constructor" << endl;
        for (int i = 0; i < _size; ++i) {
            _p_vals[i] = other._p_vals[i];
        }
    }
    // move constructor
    ArrayWrapper(ArrayWrapper&& other)
        : _p_vals( other._p_vals)
        , _size(other._size)
    {
        cout << "move constructor" << endl;
        other._p_vals = nullptr;
        other._size = 0;
    }
    ~ArrayWrapper()
    {
        delete[] _p_vals;
    }
    int size() { return _size;};
    private:
    int* _p_vals;
    int _size;
};

ArrayWrapper getArrayWrapper()
{
    return ArrayWrapper(128);
}

void testMoveConstructor()
{
    ArrayWrapper a(128);
    cout << "copy!" << endl;
    ArrayWrapper b(a);
    cout << "move!" << endl;
    ArrayWrapper&& c(getArrayWrapper());
    cout << "moved size=" << c.size() << endl;
}

int main()
{
    testCopyElision();
    testRvalueReference();
    testMoveConstructor();

    return 0;
}
