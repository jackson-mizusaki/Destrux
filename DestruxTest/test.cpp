#include "pch.h"
#include "../Destrux/include/Tensor.h"
#include <iostream>


class TensorTest : public ::testing::Test {
protected:
    void SetUp() override {
        F << 21, 21, 20,
            40, 31, 36,
            30, 28, 28;
        R << -0.458289, 0.575185, 0.677593,
            0.71667, -0.21177, 0.664483,
            0.525695, 0.790136, -0.315166;
        U << 34.813579, 27.31216, 31.353798,
            27.31216, 27.637821, 26.003784,
            31.353798, 26.003784, 28.648605;
        V << 16.006691, 23.892548, 21.329135,
            23.892548, 46.023298, 34.176047,
            21.329135, 34.176047, 29.070016;
    }

    Destrux::Tensor F;
    Destrux::Tensor R;
    Destrux::Tensor U;
    Destrux::Tensor V;
};

TEST_F(TensorTest, RUDecomposition) {
    Destrux::Tensor testR;
    Destrux::Tensor testR2;
    Destrux::Tensor testU;
    Destrux::Tensor testV;
    F.PolarDecomposition(testR, testU, Destrux::Handedness::Right);
    std::cout << "testR" << std::endl;
    std::cout << testR << std::endl;
    EXPECT_EQ(testR, R);
    std::cout << "testU" << std::endl;
    std::cout << testU << std::endl;
    EXPECT_EQ(testU, U);
    F.PolarDecomposition(testR2, testV, Destrux::Handedness::Left);
    std::cout << "testR2" << std::endl;
    std::cout << testR2 << std::endl;
    EXPECT_EQ(testR, testR2);    
    std::cout << "testV" << std::endl;
    std::cout << testV << std::endl;
    EXPECT_EQ(testV, V);
}

TEST_F(TensorTest, TheoreticalDecomp) {
    Destrux::Tensor testR;
    Destrux::Tensor testR2;
    Destrux::Tensor testU;
    Destrux::Tensor testV;
    F.TheoreticalDecomposition(testR, testU, Destrux::Handedness::Right);
    std::cout << "testR" << std::endl;
    std::cout << testR << std::endl;
    EXPECT_EQ(testR, R);
    std::cout << "testU" << std::endl;
    std::cout << testU << std::endl;
    EXPECT_EQ(testU, U);
    F.TheoreticalDecomposition(testR2, testV, Destrux::Handedness::Left);
    std::cout << "testR2" << std::endl;
    std::cout << testR2 << std::endl;
    EXPECT_EQ(testR, testR2);
    std::cout << "testV" << std::endl;
    std::cout << testV << std::endl;
    EXPECT_EQ(testV, V);
}

TEST_F(TensorTest, CompareDecompRights) {
    Destrux::Tensor Ra;
    Destrux::Tensor Rb;
    Destrux::Tensor Ua;
    Destrux::Tensor Ub;
    F.TheoreticalDecomposition(Ra, Ua, Destrux::Handedness::Right);
    F.PolarDecomposition(Rb, Ub, Destrux::Handedness::Right);
    std::cout << "Theoretical results" << std::endl;
    std::cout << Ra << std::endl;
    std::cout << Ua << std::endl;

    std::cout << "Iterative results" << std::endl;
    std::cout << Rb << std::endl;
    std::cout << Ub << std::endl;
    EXPECT_EQ(Ra, Rb);
    EXPECT_EQ(Ua, Ub);
}
TEST_F(TensorTest, CompareDecompLefts) {
    Destrux::Tensor Ra;
    Destrux::Tensor Rb;
    Destrux::Tensor Ua;
    Destrux::Tensor Ub;
    F.TheoreticalDecomposition(Ra, Ua, Destrux::Handedness::Left);
    F.PolarDecomposition(Rb, Ub, Destrux::Handedness::Left);
    std::cout << "Theoretical results" << std::endl;
    std::cout << Ra << std::endl;
    std::cout << Ua << std::endl;

    std::cout << "Iterative results" << std::endl;
    std::cout << Rb << std::endl;
    std::cout << Ub << std::endl;
    EXPECT_EQ(Ra, Rb);
    EXPECT_EQ(Ua, Ub);
}
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}