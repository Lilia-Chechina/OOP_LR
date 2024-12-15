#include <gtest/gtest.h>
#include "../include/work_with_string.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("1101010101010101")==511);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("111")==7);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("1000000")==1);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("000")==0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("10101010")==15);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("11111111")==255);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("10000000")==1);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("01010101")==15);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("11001100")==15);
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("11110000")==15);
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("00001111")==15);
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("10101011")==31);
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("11110011")==63);
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("11101111")==127);
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(eliminate_unset_bits("10010010")==7);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}