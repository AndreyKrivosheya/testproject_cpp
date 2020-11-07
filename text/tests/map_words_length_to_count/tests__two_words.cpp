#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_two_words_same_length_separated_by_whitespace)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word word")),
            ElementsAre(
                Pair(4, 2)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_two_words_same_length_separated_by_punctuation_without_space)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word.word")),
            ElementsAre(
                Pair(4, 2)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_two_words_different_length_separated_by_whitespace)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word words")),
            ElementsAre(
                Pair(4, 1),
                Pair(5, 1)
            )
        );
    }
}