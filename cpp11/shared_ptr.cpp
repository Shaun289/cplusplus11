#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/** 
 * refs : https://modoocode.com/252
 */

class A {
    int *data;
    public:
    A() {
        data = new int[100];
        cout << "Set resources" << endl;
    }
    ~A() {
        delete[] data;
        cout << "Reset resources" << endl;
    }
};

int main()
{
    shared_ptr<int> ptr01(new int(5));
    cout << "count=" << ptr01.use_count() << endl;

    auto ptr02 = ptr01;
    cout << "count=" << ptr01.use_count() << endl;

    ptr02.reset();
    cout << "count=" << ptr01.use_count() << endl;


    vector<shared_ptr<A>> vec;

    vec.push_back(make_shared<A>());
    vec.push_back(shared_ptr<A>(vec[0]));
    vec.push_back(shared_ptr<A>(vec[1]));

    cout << "count=" << vec[0].use_count() << endl;
    cout << "first!" << endl;
    vec.erase(vec.begin());
    cout << "count=" << vec[0].use_count() << endl;
    cout << "second!" << endl;
    vec.erase(vec.begin());
    cout << "count=" << vec[0].use_count() << endl;
    cout << "third!" << endl;
    vec.erase(vec.begin());
    cout << "done!" << endl;

    return 0;
}
