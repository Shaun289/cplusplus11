#include <vector>
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

using namespace std;

// https://www.acmicpc.net/problem/2292
unsigned int solution(unsigned int n) {
    unsigned int sum = 1;

    if ( n <= 1 ) {
        return n;
    }
    unsigned int depth = 2;
    while (1) {
        sum += (6 * (depth - 1));
        if (sum >= n) {
            return depth;
        }
        depth++;
    }
}

//  g++ -std=c++11 baekjoon_2292.cpp  -lgtest -lpthread
/*
int main(int argc, char* argv[])
{
    unsigned int n = 0;
    scanf("%u", &n);
    unsigned int r = solution(n);
    printf("%u\n", r);
    return 0;
}
*/

TEST(baekjoon_2292, test1)
{
    EXPECT_EQ(solution(13), 3);
    EXPECT_EQ(solution(58), 5);
}

