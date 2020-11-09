#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\..\single_linked_list.hpp"

using ::testing::ElementsAreArray;

namespace test__single_linked_list__of__int__reverse {
    TEST(test__single_linked_list__of__int__reverse, should_return_empty_list_when_no_items_were_pushed_back)
    {
        auto expected = std::list<int>();
        auto sut = lists::single_linked_list<int>();
        sut.reverse();

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected.rbegin(), expected.rend()));
    }

    TEST(test__single_linked_list__of__int__reverse, should_return_list_of_1_when_1_was_pushed_back)
    {
        auto expected = std::list<int>({1});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));
        sut.reverse();

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected.rbegin(), expected.rend()));
    }

    TEST(test__single_linked_list__of__int__reverse, should_return_list_of_2_and_1_when_1_and_2_was_pushed_back)
    {
        auto expected = std::list<int>({1, 2});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));
        sut.reverse();

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected.rbegin(), expected.rend()));
    }

    TEST(test__single_linked_list__of__int__reverse, should_return_list_of_10_9_8_7_6_5_4_3_2_and_1_when_1_2_3_4_5_6_7_8_9_10_was_pushed_back)
    {
        auto expected = std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));
        sut.reverse();

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected.rbegin(), expected.rend()));
    }

    TEST(test__single_linked_list__of__int__reverse, should_return_list_of_10_9_8_7_6_5_4_3_2_1_and_11_when_1_2_3_4_5_6_7_8_9_10_was_pushed_back_then_reversed_and_then_11_was_pushed_back)
    {
        auto input = std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        auto expected = std::list<int>(input.rbegin(), input.rend());
        expected.push_back(11);
        auto sut = lists::single_linked_list<int>();
        std::copy(input.begin(), input.end(), std::back_inserter(sut));
        sut.reverse();
        sut.push_back(11);

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected.begin(), expected.end()));
    }
}