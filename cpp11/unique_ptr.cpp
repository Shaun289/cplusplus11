#include <iostream>
#include <memory>

// reference : https://modoocode.com/229

using namespace std;

class A
{
public:
    A() {
        std::cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << std::endl;
    }
    void do_some() {
        std::cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << std::endl;
    }
    ~A() {
        std::cout << __FILE__ << " " << __LINE__ << " " << __func__ << " : " << std::endl;
    }
};


/* A's destroyer is not called

unique_ptr.cpp 10 A :
unique_ptr.cpp 13 do_some :

 */
void doA()
{
    A* a = new A;
    a->do_some();
    // if delete a, destroyer is called.
    //delete a;
}

/* Even not delete a, A's destroyer is called.

unique_ptr.cpp 10 A :
unique_ptr.cpp 13 do_some :
unique_ptr.cpp 16 ~A :

 */
void doUniqueA()
{
    unique_ptr<A> a(new A());
    a->do_some();
}

int main(int argc, char* argv[])
{
    doA();
    doUniqueA();
    return 0;
}
