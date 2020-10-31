#include <gtest\gtest.h>

#include "..\..\get_min_and_max_with_same_amount_of_bits_set.hpp"

namespace tests__get_min_and_max_with_same_amount_of_bits_set {
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

    INSTANTIATE_TEST_SUITE_P(tests__get_min_and_max_with_same_amount_of_bits_set, one_bit_set,
        ::testing::Values(
            1u,         1u << 1,    1u << 2,    1u << 3,    1u << 4,    1u << 5,
            1u << 6,    1u << 7,    1u << 8,    1u << 9,    1u << 10,   1u << 11,
            1u << 12,   1u << 13,   1u << 14,   1u << 15,   1u << 16,   1u << 17,
            1u << 18,   1u << 19,   1u << 20,   1u << 21,   1u << 22,   1u << 23,
            1u << 24,   1u << 25,   1u << 26,   1u << 27,   1u << 28,   1u << 29,
            1u << 30,   1u << 31)
    );
}
