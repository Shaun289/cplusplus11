#include <gtest/gtest.h>

#include "../src/AudioData.h"

TEST(testAudioData, test1)
{
    AudioData audioData(1, 'a');
    audioData.print();
    EXPECT_EQ(audioData.id(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

