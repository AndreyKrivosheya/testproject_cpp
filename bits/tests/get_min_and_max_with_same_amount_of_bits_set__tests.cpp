#include <gtest\gtest.h>

#include "..\get_min_and_max_with_same_amount_of_bits_set.hpp"
#include <numeric>
// minimum
TEST(get_min_and_max_with_same_amount_of_bits_set__tests, should_return_zero)
{
    auto number = 0u;
    auto minExpected = 0u;
    auto maxExpected = 0u;
    auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
    EXPECT_EQ(minExpected, minActual);
    EXPECT_EQ(maxExpected, maxActual);
}

// maximum
TEST(get_min_and_max_with_same_amount_of_bits_set__tests, should_return_max)
{
    auto number = (unsigned int)-1;
    auto minExpected = (unsigned int)-1;
    auto maxExpected = (unsigned int)-1;
    auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
    EXPECT_EQ(minExpected, minActual);
    EXPECT_EQ(maxExpected, maxActual);
}

// one bit set numbers
class one_bit_set : public ::testing::TestWithParam<unsigned int>
{
};

TEST_P(one_bit_set, should_return_1_and_2_147_483_648)
{
    auto number = GetParam();
    auto minExpected = 1u;
    auto maxExpected = 1u << 31 /*2 147 483 648*/;
    auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
    EXPECT_EQ(minExpected, minActual);
    EXPECT_EQ(maxExpected, maxActual);
}

INSTANTIATE_TEST_CASE_P(get_min_and_max_with_same_amount_of_bits_set__tests, one_bit_set,
    ::testing::Values(
        1u,         1u << 1,    1u << 2,    1u << 3,    1u << 4,    1u << 5,
        1u << 6,    1u << 7,    1u << 8,    1u << 9,    1u << 10,   1u << 11,
        1u << 12,   1u << 13,   1u << 14,   1u << 15,   1u << 16,   1u << 17,
        1u << 18,   1u << 19,   1u << 20,   1u << 21,   1u << 22,   1u << 23,
        1u << 24,   1u << 25,   1u << 26,   1u << 27,   1u << 28,   1u << 29,
        1u << 30,   1u << 31)
);

// two bits set numbers
class two_bits_set : public ::testing::TestWithParam<unsigned int>
{
};

TEST_P(two_bits_set, should_return_3_and_3_221_225_472)
{
    auto number = GetParam();
    auto minExpected = 3u;
    auto maxExpected = 3u << 30 /*3 221 225 472*/;
    auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
    EXPECT_EQ(minExpected, minActual);
    EXPECT_EQ(maxExpected, maxActual);
}

INSTANTIATE_TEST_CASE_P(get_min_and_max_with_same_amount_of_bits_set__tests, two_bits_set,
    ::testing::Values(
        /*11*/
        3u,         3u << 1,    3u << 2,    3u << 3,    3u << 4,    3u << 5,
        3u << 6,    3u << 7,    3u << 8,    3u << 9,    3u << 10,   3u << 11,
        3u << 12,   3u << 13,   3u << 14,   3u << 15,   3u << 16,   3u << 17,
        3u << 18,   3u << 19,   3u << 20,   3u << 21,   3u << 22,   3u << 23,
        3u << 24,   3u << 25,   3u << 26,   3u << 27,   3u << 28,   3u << 29,
        3u << 30,
        /*101*/
        5u,         5u << 1,    5u << 2,    5u << 3,    5u << 4,    5u << 5,
        5u << 6,    5u << 7,    5u << 8,    5u << 9,    5u << 10,   5u << 11,
        5u << 12,   5u << 13,   5u << 14,   5u << 15,   5u << 16,   5u << 17,
        5u << 18,   5u << 19,   5u << 20,   5u << 21,   5u << 22,   5u << 23,
        5u << 24,   5u << 25,   5u << 26,   5u << 27,   5u << 28,   5u << 29,
        /*1001*/
        9u,         9u << 1,    9u << 2,    9u << 3,    9u << 4,    9u << 5,
        9u << 6,    9u << 7,    9u << 8,    9u << 9,    9u << 10,   9u << 11,
        9u << 12,   9u << 13,   9u << 14,   9u << 15,   9u << 16,   9u << 17,
        9u << 18,   9u << 19,   9u << 20,   9u << 21,   9u << 22,   9u << 23,
        9u << 24,   9u << 25,   9u << 26,   9u << 27,   9u << 28)
);

// three bits set numbers
class three_bits_set : public ::testing::TestWithParam<unsigned int>
{
};

TEST_P(three_bits_set, should_return_7_and_3_758_096_384)
{
    auto number = GetParam();
    auto minExpected = 7u;
    auto maxExpected = 7u << 29 /*3 758 096 384*/;
    auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
    EXPECT_EQ(minExpected, minActual);
    EXPECT_EQ(maxExpected, maxActual);
}

INSTANTIATE_TEST_CASE_P(get_min_and_max_with_same_amount_of_bits_set__tests, three_bits_set,
    ::testing::Values(
        /*111*/
        7u,         7u << 1,    7u << 2,    7u << 3,    7u << 4,    7u << 5,
        7u << 6,    7u << 7,    7u << 8,    7u << 9,    7u << 10,   7u << 11,
        7u << 12,   7u << 13,   7u << 14,   7u << 15,   7u << 16,   7u << 17,
        7u << 18,   7u << 19,   7u << 20,   7u << 21,   7u << 22,   7u << 23,
        7u << 24,   7u << 25,   7u << 26,   7u << 27,   7u << 28,   7u << 29)
);