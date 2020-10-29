#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Refs. : https://modoocode.com/196

int main()
{
    int my_mod = 8;
    vector<int> in = { 264,226,264525,26,26,25};
    vector<int> out;

    //[my_mod]() {my_mod -= 4; }(); // Compile error

    out.resize(in.size());

    transform(in.begin(), in.end(), out.begin(),
        [my_mod](int v) -> int { return v % my_mod; });

    for (auto& x: out) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
