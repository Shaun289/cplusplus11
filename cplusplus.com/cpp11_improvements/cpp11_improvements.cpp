#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <array>

using namespace std;

static void cpp11_auto()
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
}

static void cpp11_for()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // the C++03 way
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) ;

    // the C++11 way
    // item은 순서대로 v에 저장된 모든 것들이 됩니다.
    for (int &item: v) {
        cout << item << " ";
    }
    cout << endl;
    // const형, v 멤버를 빠르게 레퍼런스합니다.
    for (const int &item: v) {
        cout << item << " ";
    }
    cout << endl;

    // 값을 가져오며 item을 바꾸지는 못합니다.
    for (int item: v);
}

static void cpp11_initializer()
{
    // C arrays
    char arr1[] = {'A', 'B'};
    double arr2[] = {32.0, 6.3, -0.1};

    // C++03 vector
    std::vector<char> cpp03vector1;
    cpp03vector1.push_back('A');
    cpp03vector1.push_back('B');

    std::vector<double> cpp03vector2(3);
    cpp03vector2[0] = 32.0;
    cpp03vector2[1] = 6.3;
    cpp03vector2[2] = -0.1;

    // C++11 vector
    std::vector<char> cpp11vector1 = {'A', 'B'};
    std::vector<double> cpp11vector2 = {32.0, 6.3, -0.1};
    // or... 이게 가능하군요?
    std::vector<char> cpp11vector3{'A', 'B'};
    std::vector<double> cpp11vector4{32.0, 6.3, -0.1};
    // NOTE: vector 뿐만아니라 모든 컨테이너에 가능함

}

static void cpp11_initializer_complex()
{
    map<string, vector<pair<string, int>>> name_languages_year {
        {"Dennis Ritchie",
            {
                {"B", 1969}, 
                {"C", 1973}
            }
        },
        {"Niklaus Wirth",
            {
                {"Pascal", 1970}, 
                {"Modula-2", 1973},
                {"Oberon", 1986}
            }
        }
    };
    // "Pascal"
    cout << name_languages_year["Niklaus Wirth"].at(0).first << endl;

    // adds a new entry to the map
    name_languages_year["John McCarthy"] = {
        {"Lisp", 1958}
    };
    // 방금 넣은 entry 출력
    cout << name_languages_year["John McCarthy"].at(0).first << ":"
         << name_languages_year["John McCarthy"].at(0).second << endl;
}

static void cpp11_array()
{

}

int main()
{
    cpp11_auto();
    cpp11_for();
    cpp11_initializer();
    cpp11_initializer_complex();
    cpp11_array();

    return 0;
}