#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_consisting_of_digits)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("123")),
            ElementsAre(
                Pair(3, 1)
            )
        );
    }
}