#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.e")),
            ElementsAre(
                Pair(3, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_with_trailing_dot)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.e.")),
            ElementsAre(
                Pair(4, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_with_space_between)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.  e.")),
            ElementsAre(
                Pair(6, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_special_case_01)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.i.  e.")),
            ElementsAre(
                Pair(1, 1),
                Pair(6, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_special_case_02)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.  e.i.")),
            ElementsAre(
                Pair(1, 1),
                Pair(6, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_special_case_03)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("e.i.  e.")),
            ElementsAre(
                Pair(1, 1),
                Pair(6, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_special_case_04)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.  e.e.")),
            ElementsAre(
                Pair(1, 1),
                Pair(6, 1)
            )
        );
    }

    TEST(tests__map_words_length_to_count, should_return_map_when_text_is_only_one_special_word_ie_special_case_05)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("i.  i.  e.  e.")),
            ElementsAre(
                Pair(1, 2),
                Pair(6, 1)
            )
        );
    }
}