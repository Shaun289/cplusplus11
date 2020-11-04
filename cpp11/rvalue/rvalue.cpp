#include <iostream>

using namespace std;

class A {
    int data_;

    public:
    A(int data) : data_(data) { cout << "일반 생성자 호출!" << endl;};
    A(const A& a) : data_(a.data_) { cout << "복사 생성자 호출!" << endl;};
};

void testCopyElision()
{
    A a(1);
    A b(a);
    A c(A(2));
}

int main()
{
    testCopyElision();
}
