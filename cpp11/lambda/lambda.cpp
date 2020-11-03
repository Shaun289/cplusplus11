#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

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

class gorp {
    vector<int> values;
    int m_;

    public:
    gorp(int mod) : m_(mod) {};
    gorp& put(int v) {
        values.push_back(v);
        return *this;
    }
    int extras() {
        int count = 0;
        for_each(values.begin(), values.end(), [=, &count](int v) { count += (v%m_); });
        return count;
    }
};

void testCaptureMember()
{
    gorp g(4);
    g.put(3).put(7).put(8);
    cout << "extras:" << g.extras() << endl;
}

void testStdFunction()
{
    std::function<int(std::string const &)> f;

    f = [](std::string const &s) -> int { return s.size();};
    cout << __func__ << " size = " << f(__func__) << endl;

    std::function<int(int)> fact;
    fact = [&fact](int n) -> int {
        if (n == 0) {
            return 1;
        }
        else {
            return (n * fact(n-1));
        }
    };
    cout << "factorial(4) = " << fact(4) << endl;
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
    testCaptureMember();
    testStdFunction();

    return 0;
}
