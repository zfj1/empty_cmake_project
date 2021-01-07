#include "example.h"

#include "gtest/gtest.h"

TEST(ExampleTest, HandlesAgtB) {  // uses the GoogleTest framework
    int A = 30, B = 5, C;
    C = DoExampleCalculation(A, B);
    EXPECT_EQ(C, 2 * A - B);
}

TEST(ExampleTest, HandlesAeqB) {
    int A = 5, B = 5, C;
    C = DoExampleCalculation(A, B);
    EXPECT_EQ(C, 0);
}

TEST(ExampleTest, HandlesAltB) {
    int A = 3, B = 7, C;
    C = DoExampleCalculation(A, B);
    EXPECT_EQ(C, 597);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}