#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Predicate는 참,거짓을 Return하는 함수형 인터페이스이다

int main()
{
    const auto odd([](int i) { return i % 2 != 0; });
    vector<int> v { 1, 2, 3, 2, 5, 2, 6, 2, 4, 8 };

    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;

    const auto new_end(remove(begin(v), end(v), 2));
    v.shrink_to_fit();

    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;

    v.erase(remove_if(begin(v), end(v), odd), end(v));

    v.shrink_to_fit();

    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
