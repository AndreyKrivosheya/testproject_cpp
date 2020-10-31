#include <gtest\gtest.h>

#include "..\..\get_min_and_max_with_same_amount_of_bits_set.hpp"

namespace tests__get_min_and_max_with_same_amount_of_bits_set {
    TEST(tests__get_min_and_max_with_same_amount_of_bits_set, should_return_4_294_967_295_as_min_and_max)
    {
        auto number = (unsigned int)-1;
        auto minExpected = (unsigned int)-1;
        auto maxExpected = (unsigned int)-1;
        auto [minActual, maxActual] = bits::get_min_and_max_with_same_amount_of_bits_set(number);
        EXPECT_EQ(minExpected, minActual);
        EXPECT_EQ(maxExpected, maxActual);
    }
}