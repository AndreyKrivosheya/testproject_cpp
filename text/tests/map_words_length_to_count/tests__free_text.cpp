#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\map_words_length_to_count.hpp"

using ::testing::ElementsAre;
using ::testing::Pair;

namespace tests__map_words_length_to_count {
    std::string join(const std::vector<std::string>& strings, std::string delimiter = "")
    {
        std::string result;
        for(const auto& string : strings)
        {
            if(!result.empty())
            {
                result += delimiter;
            }
            result += string;
        }

        return result;
    }

    TEST(tests__map_words_length_to_count, should_return_map_for_sample_text_01)
    {
        ASSERT_THAT(
            text::map_words_length_to_count(
                join(std::vector<string>({
                    "In this test method, you have to read a text from which sentences or, sometimes, short paragraphs, have been removed.",
                    "The missing sentences are arranged in a jumbled order after the text, and your task is to reconstruct the text by selecting from a list of several options the right sentence to fill each gap in the text.",
                    "The gaps in the text are numbered, while the choices given after the text are marked with letters.",
                    "Note that, among the choices, there is always one extra sentence, which does not fit in any of the gaps."
                }), " ")
            ),
            ElementsAre(
                Pair(1, 3),
                Pair(2, 14),
                Pair(3, 21),
                Pair(4, 25),
                Pair(5, 12),
                Pair(6, 3),
                Pair(7, 8),
                Pair(8, 4),
                Pair(9, 4),
                Pair(10, 1),
                Pair(11, 1)
            )
        );
    }
}