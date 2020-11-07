#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\..\single_linked_list.hpp"

using ::testing::ElementsAreArray;

namespace test__single_linked_list__of__int__to_list {
    TEST(test__single_linked_list__of__int__to_list, should_return_empty_list_when_no_items_were_pushed_back)
    {
        auto expected = std::list<int>();
        auto sut = lists::single_linked_list<int>();

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected));
    }

    TEST(test__single_linked_list__of__int__to_list, should_return_list_of_1_when_1_was_pushed_back)
    {
        auto expected = std::list<int>({1});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected));
    }

    TEST(test__single_linked_list__of__int__to_list, should_return_list_of_1_and_2_when_1_and_2_was_pushed_back)
    {
        auto expected = std::list<int>({1, 2});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected));
    }

    TEST(test__single_linked_list__of__int__to_list, should_return_list_of_1_2_3_4_5_6_7_8_9_and_10_when_1_2_3_4_5_6_7_8_9_10_was_pushed_back)
    {
        auto expected = std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        auto sut = lists::single_linked_list<int>();
        std::copy(expected.begin(), expected.end(), std::back_inserter(sut));

        ASSERT_THAT(sut.to_list(), ElementsAreArray(expected));
    }
}