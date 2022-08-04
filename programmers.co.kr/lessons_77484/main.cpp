#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/77484

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int win = 0;
    int unknown = 0;

    for (auto l = lottos.begin(); l != lottos.end(); l++) {
        if (*l == 0) {
            unknown++;
            continue;
        }
        for (auto w = win_nums.begin(); w != win_nums.end(); w++) {
            if (*l == *w) {
                win++;
                break;
            }
        }
    }
    if (win+unknown < 2) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - (win+unknown));
    }
    if (win < 2) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - win);
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


int main(int argc, char* argv[])
{
    vector<int> lottos = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};

    auto s = solution(lottos, win_nums);

    printVector(lottos);
    printVector(win_nums);
    printVector(s);

    return 0;
}
