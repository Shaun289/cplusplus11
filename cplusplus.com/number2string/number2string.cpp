#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void ss_num2string()
{
    int Number = 123;
    string Result;
    ostringstream convert;

    convert << Number;

    Result = convert.str();

    cout << Result << endl;
}

void ss_num2string_short()
{
    int Number = 123;

    string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();

    cout << String << endl;
}

int main()
{
    ss_num2string();
    ss_num2string_short();

    return 0;
}