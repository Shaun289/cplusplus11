#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

// https://programmers.co.kr/skill_checks/402301

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        int val = *iter;
        if ((val%divisor) == 0) {
            answer.push_back(val);
        }
    }

    if (answer.size() == 0) {
        answer.push_back(-1);
    }
    ::sort(answer.begin(), answer.end());

    return answer;
}

void printAnswer(vector<int> answer)
{
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<string> solution2(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;


    for (int i = 0; i < n; i++) {
        int merged = (arr1[i] | arr2[i]);

        string s;
        for (int col = n - 1; col >= 0; col--) {
            if ((merged & (1<<col))) {
                s.append("#");
            }
            else {
                s.append(" ");
            }
        }
        answer.push_back(s);

    }
    return answer;
}

void printAnswer2(vector<string> answer)
{
    for (auto iter = answer.begin(); iter < answer.end(); iter++) {
        cout << *iter << endl;
    }
}

int main(int argc, char* argv[])
{
    //::testing::InitGoogleTest(&argc, argv);

    //return RUN_ALL_TESTS();

    vector<int> vi = {5, 9, 7, 10};
    vector<int> answer = solution(vi, 5);
    printAnswer(answer);

    vector<int> vi2 = {2, 36, 1, 3};
    answer = solution(vi2, 1);
    printAnswer(answer);

    vector<int> vi3 = {3, 2, 6};
    answer = solution(vi3, 10);
    printAnswer(answer);

    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    auto answer2 = solution2(5, arr1, arr2);
    printAnswer2(answer2);

    return 0;
}
