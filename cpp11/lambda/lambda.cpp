#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Refs. : https://modoocode.com/196

int testCapture()
{
    int total = 0;
    vector<int> v = {1,2,3,4};

    // call by reference
    for_each (v.begin(), v.end(), [&total](int i) { ++total;});
    cout << "total = " << total << endl;

    // call by value. compile error. total is read-only
    // for_each (v.begin(), v.end(), [total](int i) { ++total;});
    // cout << "total = " << total << endl;

}

template <typename T>
void fill(vector<int>& v, T done)
{
    int i = 0;
    while (!done()) {
        v.push_back(i++);
    }
}

void testCloser()
{
    vector<int> v;

    fill(v, [&]() -> bool { return v.size() >= 8;});

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
