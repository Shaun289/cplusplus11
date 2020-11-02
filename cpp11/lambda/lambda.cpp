#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Refs. : https://modoocode.com/196

void testCapture()
{
    int total = 0;
    vector<int> v = {1,2,3,4};

    // call by reference
    for_each (v.begin(), v.end(), [&total](int i) { ++total;});
    cout << "total = " << total << endl;

    // call by value. compile error. total is read-only
    // for_each (v.begin(), v.end(), [total](int i) { ++total;});
    // cout << "total = " << total << endl;

    int val = 42;
    auto func = [=]() {
        cout << "inner=" << val << endl;
        // inner=42
    };
    val = 8;
    func();
    cout <<"outer="<< val << endl;
    // outer=8;
}

template <typename T>
void fill(vector<int>& v, T done)
{
    int i = 0;
    while (!done(i)) {
        v.push_back(i++);
    }
}

void testCloser()
{
    vector<int> v;

    // Test #1
    fill(v, [&](int i) -> bool { return v.size() >= 8;});

    cout << "Test #1" << endl;
    for_each(v.begin(), v.end(), [](int i) { cout << i << " ";});
    cout << endl;

    // Test #2
    int sum = 0;
    v.clear();
    fill(v, [&sum](int i) -> bool { sum += i; return sum > 10;});

    cout << "Test #2" << endl;
    for_each(v.begin(), v.end(), [](int i) { cout << i << " ";});
    cout << endl;

}

int main()
{
    int my_mod = 8;
    vector<int> in = { 264,226,264525,26,26,25};
    vector<int> out;

    out.resize(in.size());

    transform(in.begin(), in.end(), out.begin(),
        [my_mod](int v) -> int { return v % my_mod; });

    for (auto& x: out) {
        cout << x << " ";
    }
    cout << endl;

    testCapture();
    testCloser();

    return 0;
}
