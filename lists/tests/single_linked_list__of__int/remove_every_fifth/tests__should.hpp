#pragma once

#include <gmock\gmock.h>
#include <gtest\gtest.h>

#include "..\..\..\single_linked_list.hpp"

using ::testing::ElementsAreArray;

namespace tests__single_linked_list__remove_every_fifth {
    class should : public ::testing::Test
    {
        protected:

        void should_return_expected_list_after_removing_every_fifth(const std::list<int>& input, const std::list<int>& expected)
        {
            auto sut = lists::single_linked_list<int>();
            std::copy(input.begin(), input.end(), std::back_inserter(sut));
            sut.remove_every_fifth();

            ASSERT_THAT(sut.to_list(), ElementsAreArray(expected));
        }
    };
}
