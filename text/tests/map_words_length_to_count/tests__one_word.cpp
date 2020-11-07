#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_and_no_whitespaces)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_and_trailing_whitespaces_before_word)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string(" \tword")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_and_trailing_whitespaces_after_word)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word\t\t")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_and_trailing_whitespaces_before_andafter_word)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string(" \tword  ")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }
}