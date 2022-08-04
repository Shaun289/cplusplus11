#include <string>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <sstream>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/42888

void printVector(vector<int>& v)
{
    cout << "printVector : ";
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> id_nick_map;

    string cmd, id, nick;

    // make id:nick map
    for (auto iter = record.begin(); iter != record.end(); iter++) {
        istringstream iss(*iter);
        getline(iss, cmd, ' '); // command
        if (cmd.compare("Leave") == 0) {
            continue;
        }
        getline(iss, id, ' '); // id
        getline(iss, nick, ' '); // nick

        id_nick_map[id] = nick;
    }

    // print
    for (auto iter = record.begin(); iter != record.end(); iter++) {
        istringstream iss(*iter);
        getline(iss, cmd, ' '); // command
        getline(iss, id, ' '); // id
        string s;
        if (cmd.compare("Enter") == 0) {
            s = id_nick_map[id];
            s.append("님이 들어왔습니다.");
            answer.push_back(s);
            cout << s << endl;
        }
        else if (cmd.compare("Leave") == 0) {
            s = id_nick_map[id];
            s.append("님이 나갔습니다.");
            answer.push_back(s);
            cout << s << endl;
        }
    }

    return answer;
}

int main(int argc, char* argv[])
{
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(record);
    return 0;
}
