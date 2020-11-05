#pragma once
#include "..\..\common\list.hpp"
#include "..\..\common\vector.hpp"

#define V(a, b) a##b

#define ASSERT_VECTORS_OR_LISTS_ARE_SAME_IMPL(expected, actual, counter)                                                            \
    {                                                                                                                               \
        auto V(__expected, counter) = common::to_vector(expected);                                                                  \
        auto V(__actual, counter) = common::to_vector(actual);                                                                      \
        ASSERT_EQ(V(__expected, counter).size(), V(__actual, counter).size());                                                      \
        for(size_t V(__i, counter) = 0; V(__i, counter) < V(__expected, counter).size(); V(__i, counter)++)                         \
        {                                                                                                                           \
            EXPECT_EQ(V(__expected, counter)[V(__i, counter)], V(__actual, counter)[V(__i, counter)]) << "i = " << V(__i, counter); \
        }                                                                                                                           \
    }

#define ASSERT_VECTORS_OR_LISTS_ARE_SAME(expected, actual) ASSERT_VECTORS_OR_LISTS_ARE_SAME_IMPL(expected, actual, __COUNTER__)
