#include <gtest\gtest.h>

#include "..\..\get_min_and_max_with_same_amount_of_bits_set.hpp"

namespace tests__get_min_and_max_with_same_amount_of_bits_set {
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

    INSTANTIATE_TEST_CASE_P(tests__get_min_and_max_with_same_amount_of_bits_set, three_bits_set,
        ::testing::Values(
            /*111*/
            7u,         7u << 1,    7u << 2,    7u << 3,    7u << 4,    7u << 5,
            7u << 6,    7u << 7,    7u << 8,    7u << 9,    7u << 10,   7u << 11,
            7u << 12,   7u << 13,   7u << 14,   7u << 15,   7u << 16,   7u << 17,
            7u << 18,   7u << 19,   7u << 20,   7u << 21,   7u << 22,   7u << 23,
            7u << 24,   7u << 25,   7u << 26,   7u << 27,   7u << 28,   7u << 29)
    );
}