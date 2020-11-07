#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_with_one_dash)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word-word")),
            ElementsAre(
                Pair(9, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_with_trailing_dash_after_word)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word-")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_with_trailing_dash_before_word)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("-word")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_two_words_with_one_dash)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word-word  words-words")),
            ElementsAre(
                Pair(9, 1),
                Pair(11, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_with_two_dashes)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("word-word-word")),
            ElementsAre(
                Pair(14, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_word_with_one_dash_and_one_word_with_two_dashes)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("words-words   word-word-word")),
            ElementsAre(
                Pair(11, 1),
                Pair(14, 1)
            )
        );
    }
}