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

int main()
{
    testCopyElision();
    testRvalueReference();

    return 0;
}
