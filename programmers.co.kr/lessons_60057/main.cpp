#include <string>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/60057

int stringCompress(string s, int unit)
{
    int ssize = s.size();
    string scomp;
    int p = 0, q = 0;
    int count = 0;

    while (p < ssize) {
        count = 0;
        q = p;
        while (q < ssize) {
            q += unit;
            bool same = true;
            for (int i = 0; i < unit; i++) {
                if (q+i >= ssize) {
                    same = false;
                    break;
                }
                if (s[p+i] != s[q+i]) {
                    same = false;
                    break;
                }
            }
            if (same == true) {
                count++;
            }
            else {
                break;
            }
        }
        if (count != 0) {
            scomp.append(::to_string(count+1));
        }
        scomp.append(s.substr(p, unit));
        p += (unit*(count+1));
    }
    //cout << s << " unit:" << unit << " to " << scomp << " size: " << scomp.size() << endl;
    return scomp.size();
}

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i < s.size()/2 + 1; i++) {
        int comp_size = stringCompress(s, i);
        if (answer > comp_size) {
            answer = comp_size;
        }
    }

    return answer;
}

void printVector(vector<int>& v)
{
    cout << "printVector : ";
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}


TEST(LESSONS_60057, Test1)
{
    string s = "aabbaccc";
    EXPECT_EQ(solution(s), 7);
}
TEST(LESSONS_60057, Test2)
{
    string s = "ababcdcdababcdcd";
    EXPECT_EQ(solution(s), 9);
}
TEST(LESSONS_60057, Test3)
{
    string s = "abcabcdede";
    EXPECT_EQ(solution(s), 8);
}

TEST(LESSONS_60057, Test4)
{
    string s = "abcabcabcabcdededededede";
    EXPECT_EQ(solution(s), 14);
}
TEST(LESSONS_60057, Test5)
{
    string s = "xababcdcdababcdcd";
    EXPECT_EQ(solution(s), 17);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
