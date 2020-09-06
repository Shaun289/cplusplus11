#include <string>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;

// number to string using stringstream
static void ss_num2string()
{
    int Number = 123;
    string Result;
    ostringstream convert;

    convert << Number;

    Result = convert.str();

    cout << Result << endl;
}

// num2string shorten
static void ss_num2string_shorten()
{
    int Number = 123;

    string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();

    cout << String << endl;
}

// Defining own nunmeric facet
// class for decimal numbers using comma instead of point
// http://cplusplus.com/reference/locale/numpunct/?kw=numpunct
class WithComma: public numpunct<char> 
{
    protected:
        char do_decimal_point() const { return ','; } // change the decimal separator
};

// from double 0.12 to string "0,120"
static void ss_custom_formatting()
{
    double Number = 0.12;
    ostringstream Convert;
    locale MyLocale( locale(), new WithComma); // create customized locale

    // http://cplusplus.com/reference/ios/ios_base/imbue/
    Convert.imbue(MyLocale);
    // fixed : http://cplusplus.com/reference/ios/fixed/?kw=fixed
    // setprecision : http://cplusplus.com/reference/iomanip/setprecision/
    Convert << fixed << setprecision(3) << Number; // Use some maniulators

    string Result = Convert.str();

    cout << Result << endl;
}

int main()
{
    ss_num2string();
    ss_num2string_shorten();
    ss_custom_formatting();

    return 0;
}