#include "gtest/gtest.h"
#include "Sidel.h"


TEST(AllTestSuite, simpleMatrix){
    Sidel* s = new Sidel();

    std::vector<std::vector<int>> m = {{0, 1, 1, 1},
                                       {1, 0, 1, 0},
                                       {1, 1, 0, 0},
                                       {1, 0, 0, 0}};
    std::vector<std::vector<int>> d = s->sidelRun(m, m.size());
    std::vector<std::vector<int>> m2 = {{0, 1, 1, 1},
                                        {1, 0, 1, 2},
                                        {1, 1, 0, 2},
                                        {1, 2, 2, 0}};
    EXPECT_EQ(d, m2);
//    EXPECT_EQ(0, 0);
}

TEST(AllTestSuite, BigMatrix){
    Sidel* s = new Sidel();

    std::vector<std::vector<int>> m = {{0, 1, 0, 1, 0, 0, 0, 0},
                                       {1, 0, 1, 0, 0, 0, 0, 0},
                                       {0, 1, 0, 0, 0, 0, 0, 0},
                                       {1, 0, 0, 0, 1, 0, 0, 1},
                                       {0, 0, 0, 1, 0, 1, 1, 1},
                                       {0, 0, 0, 0, 1, 0, 1, 0},
                                       {0, 0, 0, 0, 1, 1, 0, 1},
                                       {0, 0, 0, 1, 1, 0, 1, 0}};
    std::vector<std::vector<int>> d = s->sidelRun(m, m.size());
    std::vector<std::vector<int>> m2 = {{0, 1, 2, 1, 2, 3, 3, 2},
                                        {1, 0, 1, 2, 3, 4, 4, 3},
                                        {2, 1, 0, 3, 4, 5, 5, 4},
                                        {1, 2, 3, 0, 1, 2, 2, 1},
                                        {2, 3, 4, 1, 0, 1, 1, 1},
                                        {3, 4, 5, 2, 1, 0, 1, 2},
                                        {3, 4, 5, 2, 1, 1, 0, 1},
                                        {2, 3, 4, 1, 1, 2, 1, 0}};
    EXPECT_EQ(d, m2);
//    EXPECT_EQ(0, 0);
}

TEST(AllTestSuite, simpleMatrixMul){
    Sidel* s = new Sidel();

    std::vector<std::vector<int>> m = {{2, 4, 5},
                                       {4, 3, 2},
                                       {6, 4, 5}};
    std::vector<std::vector<int>> m2 = {{3, 8, 7},
                                       {4, 5, 4},
                                       {3, 1, 0}};
    std::vector<std::vector<int>> d = s->multiply(m, m2, 3);
    std::vector<std::vector<int>> m3 = {{37, 41, 30},
                                        {30, 49, 40},
                                        {49, 73, 58}};
    EXPECT_EQ(d, m3);
}

TEST(AllTestSuite, zeroMatrix){
    Sidel* s = new Sidel();

    std::vector<std::vector<int>> m = {{0, 0, 0},
                                       {0, 0, 0},
                                       {0, 0, 0}};
    std::vector<std::vector<int>> m2 = {{3, 8, 7},
                                        {4, 5, 4},
                                        {3, 1, 0}};
    std::vector<std::vector<int>> d = s->multiply(m, m2, 3);
    std::vector<std::vector<int>> m3 = {{0, 0, 0},
                                        {0, 0, 0},
                                        {0, 0, 0}};
    EXPECT_EQ(d, m3);
}
