#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

// https://programmers.co.kr/skill_checks/402145
// string 반복자 : https://www.techiedelight.com/ko/iterate-over-characters-string-cpp/

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<string> vs = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (vector<string>::iterator iter = vs.begin(); iter < vs.end(); iter++) {
        cout << *iter << endl;
    }

    int size = s.size();
    for (int i = 0; i < size; i++) {
        cout << "s[" << i << "] = " << s[i] << endl;
        // decimal
        if (s[i] >= '0' && s[i] <= '9') {
            answer = answer*10 + s[i] - '0';
            continue;
        }
        for (int j = 0; j < vs.size(); j++) {
            int vs_size = vs[j].size();
            cout << "vs[" << j << "] = " << vs[j] << " size = "<< vs_size << endl;
            if (s.compare(i, vs_size, vs[j]) == 0) {
                answer = answer*10 + j;
                i += (vs_size-1); // 1 will be added in for statement
                break;
            }
        }
    }
    cout << s << " answer = " << answer << endl;

    return answer;
}

TEST(ProgrammersLevelTest, Test1)
{
    string s;
    int answer = 0;

    s = "123";
    answer = 123;
    EXPECT_EQ(answer, solution(s));

    s = "123zero";
    answer = 1230;
    EXPECT_EQ(answer, solution(s));

    s = "123zero123nine";
    answer = 12301239;
    EXPECT_EQ(answer, solution(s));
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
