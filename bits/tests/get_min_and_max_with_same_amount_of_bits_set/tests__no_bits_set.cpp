#include <gtest\gtest.h>

#include "..\..\get_min_and_max_with_same_amount_of_bits_set.hpp"

namespace tests__get_min_and_max_with_same_amount_of_bits_set {
    TEST(tests__get_min_and_max_with_same_amount_of_bits_set, should_return_zero_as_min_and_max)
    {
        auto number = 0u;
        auto minExpected = 0u;
        auto maxExpected = 0u;
        auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
        EXPECT_EQ(minExpected, minActual);
        EXPECT_EQ(maxExpected, maxActual);
    }
}