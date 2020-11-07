#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::IsEmpty;

namespace tests__map_words_length_to_count {
    TEST(tests__map_words_length_to_count, should_return_empty_map_when_text_is_empty)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string()),
            IsEmpty()
        );
    }

    TEST(tests__map_words_length_to_count, should_return_empty_map_when_text_is_whitespace_only)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("   \t\t   \t")),
            IsEmpty()
        );
    }

    TEST(tests__map_words_length_to_count, should_return_empty_map_when_text_is_puncatuation_only)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("...,,,..,,..")),
            IsEmpty()
        );
    }

    TEST(tests__map_words_length_to_count, should_return_empty_map_when_text_is_puncatuation_and_whitespace_only)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(std::string("...   ,,\t\t,. \t.,,..")),
            IsEmpty()
        );
    }
}