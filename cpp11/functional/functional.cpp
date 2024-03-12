#include <iostream>
#include <vector>
#include <numeric>
#include <gtest/gtest.h>

TEST(test_copy_if, TestOdd)
{
    std::vector<int> v1(10);
    std::vector<int> v2(5);
    std::iota(v1.begin(), v1.end(), 0);

    std::copy_if(v1.begin(), v1.end(), v2.begin(), [] (int x) {
            return x % 2 != 0;
    });

    std::vector<int> result{1,3,5,7,9};

    EXPECT_EQ(v2, result);
}

TEST(test_transform, TestOdd)
