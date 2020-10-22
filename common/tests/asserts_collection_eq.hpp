#include "..\..\common\list.hpp"
#include "..\..\common\vector.hpp"

#define ASSERT_VECTORS_OR_LISTS_ARE_SAME(expectedRaw, actualRaw)    \
    {                                                               \
        auto expected = common::to_vector(expectedRaw);             \
        auto actual = common::to_vector(actualRaw);                 \
        ASSERT_EQ(expected.size(), actual.size());                  \
        for(size_t i = 0; i < expected.size(); i++)                 \
        {                                                           \
            EXPECT_EQ(expected[i], actual[i]) << "i = " << i;       \
        }                                                           \
    }
