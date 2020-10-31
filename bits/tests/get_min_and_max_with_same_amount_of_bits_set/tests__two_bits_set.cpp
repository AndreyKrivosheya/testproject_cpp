#include <gtest\gtest.h>

#include "..\..\get_min_and_max_with_same_amount_of_bits_set.hpp"

namespace tests__get_min_and_max_with_same_amount_of_bits_set {
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

    INSTANTIATE_TEST_CASE_P(tests__get_min_and_max_with_same_amount_of_bits_set, two_bits_set,
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
}