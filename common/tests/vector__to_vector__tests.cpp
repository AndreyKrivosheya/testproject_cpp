#include <vector>

#include <gtest\gtest.h>

#include "..\..\common\vector.hpp"

TEST(vector__to_vector__tests, should_return_the_same_vector)
{
    auto vector = std::vector<int> {1, 2, 3};
    auto expected = &vector;
    auto actual = &(common::to_vector(vector));
    ASSERT_EQ(expected, actual);
}