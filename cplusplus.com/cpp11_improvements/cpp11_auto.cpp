#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // the c++03 way
    for (vector<int>::const_iterator ci = v.cbegin(); ci != v.cend(); ++ci)
    {
        n += *ci;
    }
    cout << "sum of v : " << n << endl;

    // the c++11 way
    n = 0;
    for (auto ci = v.cbegin(); ci != v.cend(); ++ci)
    {
        n += *ci;
    }
    cout << "sum of v : " << n << endl;

    // Bad example
    auto x = 10.0;
    // 만약 뉴비가 10.0을 10으로 변경할 경우 
    // x는 float에서 integer가 되며 
    // floating point이 필요한 코드는 fail이 발생합니다.
    // advice 1 : auto는 모호할때 사용하세요. 명료할때 말구요.
    // 여기서는 float가 명료합니다.

    for (auto i = 0ul; i < v.size(); ++i);
    // 이건 unsigned long int 를 쓰는 영리한 방법입니다.
    // advice 2 : 타입을 선언하는데 auto를 사용하지 마세요. 이것의 목적에 어긋납니다.

    // advice 1+2=3: 상수에 auto를 쓰지 마세요.

    return 0;
}