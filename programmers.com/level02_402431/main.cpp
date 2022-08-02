#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool makeArray(vector<char>& v)
{
    static const vector<char> array = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    static int i = 0, j = 0;

    // end
    if (i >= array.size() - 1) {
        return false;
    }


    v = array;

    // swap
    char tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;

    // next
    j++;
    if (j >= array.size()) {
        i++;
        j = i+1;
    }

    return true;
}

void printArray(vector<char>& v)
{
    cout << "printArray : ";
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
}

bool checkValid(int n, vector<string> &data, vector<char> &v)
{
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        // find first and second
        char start = (*iter)[0];
        char end = (*iter)[2];
        int startIdx = -1;
        int endIdx = -1;

        char operand = (*iter)[3];
        int count = (*iter)[4] - '0';

        //cout << *iter << endl;

        for (int i = 0; i < v.size(); i++) {
            if (start == v[i]) {
                startIdx = i;
            }
            else if (end == v[i]) {
                endIdx = i;
            }
        }
        if (startIdx == -1 || endIdx == -1) {
            cout << "what the fuck?" << endl;
            cout << *iter << endl;
            return false;
        }

        bool b = false;
        int diff = (endIdx < startIdx ? 0 : endIdx - startIdx);
        switch (operand) {
            case '>' : b = (diff > count); break;
            case '=' : b = (diff == count); break;
            case '<' : b = (diff < count); break;
            default : cout << "what the fuck again?" << endl;
                      return false;
        }
        if (b == false) {
            return false;
        }
    }
    //cout << "true!" << endl;

    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    // 일단 모든 경우의 수 만들기
    // 포인터 두개
    vector<char> v;

    while (makeArray(v)) {
        printArray(v);
        if (checkValid(n, data, v)) {
            answer++;
        }
    }

    return answer;
}

int main(int argc,char* argv[])
{
    vector<string> data = {"N~F=0", "R~T>2"}; // 3648
    int answer = solution(2, data);
    cout << " 3648 == " << answer << endl;

    return 0;
}
