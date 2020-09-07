#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;

// number to string using boost
static void boost_lexical_cast()
{
    try
    {
        int Number = 123;
        string Text;
        Text = boost::lexical_cast<string>(Number);
        cout << Text << endl;
        
        Text = "456";
        Number = boost::lexical_cast<int>(Text);
        cout << Number << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main()
{
    boost_lexical_cast();

    return 0;
}