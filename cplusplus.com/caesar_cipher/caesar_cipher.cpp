
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

template <typename InputIterator, typename OutputIterator>
OutputIterator caesar_cipher(InputIterator src_begin, InputIterator src_end, OutputIterator dest_begin, int shift)
{
    const std::string ab("abcdefghijklmnopqrstuvwxyz"); // Alphabet
    std::string rot_ab(ab); // Rotated Alphabet

    shift %= static_cast<int>(ab.length());

    if (shift < 0) {
        std::rotate(rot_ab.rbegin(), rot_ab.rbegin() - shift, rot_ab.rend());
    }
    else {
        std::rotate(rot_ab.begin(), rot_ab.begin() + shift, rot_ab.end());
    }
    
    return std::transform(src_begin, src_end, dest_begin, [ab, rot_ab](unsigned char c) -> char {
        if (std::isalpha(c)) {
            if (std::isupper(c)) {
                return std::toupper(rot_ab.at(ab.find(std::tolower(c))));
            }
            return rot_ab.at(ab.find(c));
        }
        return c;
    });
}

int main()
{
    std::string s("Hello, World!");

    caesar_cipher(s.begin(), s.end(), s.begin(), 4);
    std::cout << s << std::endl;
    assert(s == "Lipps, Asvph!");

    caesar_cipher(s.begin(), s.end(), s.begin(), -4);
    std::cout << s << std::endl;
    assert(s == "Hello, World!");

    return 0;
}
