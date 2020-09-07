#include <string>
#include <iostream>

using namespace std;

// cpp11 to_string
static void cpp11_to_string()
{
    int number = 123;
    string text = to_string(number);
    cout << text << endl;

    text = "456";
    number = stoi(text);
    cout << number << endl;
}

int main()
{
    cpp11_to_string();

    return 0;
}