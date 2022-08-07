#include <string>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/62048
// 맞게 한것 같은데...
/*
테스트 12 〉	실패 (283.83ms, 4.09MB)
테스트 13 〉	실패 (398.14ms, 3.71MB)
테스트 14 〉	실패 (139.75ms, 4.09MB)
테스트 15 〉	실패 (238.13ms, 3.66MB)
테스트 16 〉	실패 (243.03ms, 4.09MB)
테스트 17 〉	실패 (114.03ms, 4.16MB)
*/


long long solution(int w,int h) {
    long long answer = w*h;

    // make always height > width
    if (w > h) {
        int tmp = w;
        w = h;
        h = tmp;
    }

    double unit_x = (double)w/h; // y당 이동하는 x
    double left = 0;

    for (double y = 0; y < h; y++) {
        double left = (double)(w*y)/h;
        double right = (double)(w*(y+1))/h;

        for (long long x = (long long)left; x < w; x++) {
            if (x >= right) {
                break;
            }
            printf("%s %4d %s : y:%.f %.2f ~ %lld ~ %.2f\n", __FILE__, __LINE__, __func__, y, left, x, right);
            answer--;
        }
    }

    return (long long)answer;
}
    

TEST(ProgrammersTest, Test1)
{
    EXPECT_EQ(solution(8,12), 80);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
