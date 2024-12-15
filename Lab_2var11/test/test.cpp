#include <gtest/gtest.h>
#include "../include/Thirteen_Class.h"
#include <sstream>

TEST(ThirteenTest, Default_constructor) {
    Thirteen num;
    std::stringstream output;
    num.print(output);
    ASSERT_TRUE(output.str() == "");
}

TEST(ThirteenTest, 1_A_Constructor) {
    Thirteen num(1, 'A');
    std::stringstream output;
    num.print(output);
    ASSERT_TRUE(output.str() == "A");
}

TEST(ThirteenTest, 1_0_Constructor) {
    Thirteen num(7, '3');
    std::stringstream output;
    num.print(output);
    ASSERT_TRUE(output.str() == "3333333");
}

TEST(ThirteenTest, Constructor_with_stream) {
    std::stringstream ss;
    ss << "A12";
    Thirteen num(ss);
    std::stringstream output;
    num.print(output);
    ASSERT_EQ(output.str(), "A12");
}

TEST(ThirteenTest, Copy_сonstructor) {
    std::stringstream ss;
    ss << "A12";
    Thirteen original(ss);
    Thirteen copy(original);
    ASSERT_TRUE(copy == original);
}

TEST(ThirteenTest, Move_constructor) {
    std::stringstream ss;
    ss << "B3";
    Thirteen original(ss);
    Thirteen moved(std::move(original));
    std::stringstream output_original;
    original.print(output_original);
    ASSERT_EQ(output_original.str(), "");
    std::stringstream output_moved;
    moved.print(output_moved);
    ASSERT_EQ(output_moved.str(), "B3");
}

TEST(ThirteenTest, Addition) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "B3";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    num1 += num2;
    std::stringstream output;
    num1.print(output);
    ASSERT_EQ(output.str(), "AC5");
}

TEST(ThirteenTest, Subtraction) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "B3";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    num1 -= num2;
    std::stringstream output;
    num1.print(output);
    ASSERT_EQ(output.str(), "92C");
}

TEST(ThirteenTest, EqualityComparison) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "A12";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    ASSERT_TRUE(num1 == num2);
}

TEST(ThirteenTest, InequalityComparison) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "B3";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    ASSERT_TRUE(num1 != num2);
}

TEST(ThirteenTest, LessThanComparison) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "B3";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    ASSERT_TRUE(num2 < num1);
}

TEST(ThirteenTest, GreaterThanComparison) {
    std::stringstream ss1, ss2;
    ss1 << "A12";
    ss2 << "B3";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    ASSERT_TRUE(num1 > num2);
}

TEST(ThirteenTest, Addition_2) {
    std::stringstream ss1, ss2;
    ss1 << "37A";
    ss2 << "37";
    // 608+46=654=3B4
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    num1 += num2;
    std::stringstream output;
    num1.print(output);
    ASSERT_EQ(output.str(), "3B4");
}

TEST(ThirteenTest, Subtraction_2) {
    std::stringstream ss1, ss2;
    ss1 << "37A";
    ss2 << "37";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    num1 -= num2;
    std::stringstream output;
    num1.print(output);
    ASSERT_EQ(output.str(), "343");
}

TEST(ThirteenTest, EqualityComparison_2) {
    std::stringstream ss1, ss2;
    ss1 << "37A";
    ss2 << "37A";
    Thirteen num1(ss1);
    Thirteen num2(ss2);
    ASSERT_TRUE(num1 == num2);
}
