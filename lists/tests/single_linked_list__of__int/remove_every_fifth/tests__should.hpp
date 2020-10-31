#pragma once

#include <gtest\gtest.h>

#include "..\..\..\..\common\tests\asserts_collection_eq.hpp"
#include "..\..\..\single_linked_list.hpp"

namespace tests__single_linked_list__remove_every_fifth {
    class should : public ::testing::Test
    {
        protected:

        void should_return_expected_list_after_removing_every_fifth(const std::list<int>& inputRaw, const std::list<int>& expectedRaw)
        {
            auto sut = lists::single_linked_list<int>();
            std::copy(inputRaw.begin(), inputRaw.end(), std::back_inserter(sut));
            sut.remove_every_fifth();

            ASSERT_VECTORS_OR_LISTS_ARE_SAME(expectedRaw, sut.to_list());
        }
    };
}
