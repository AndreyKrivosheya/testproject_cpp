#include "tests__should.hpp"

namespace tests__single_linked_list__remove_every_fifth {
    class should_remove_nothing : public should, public ::testing::WithParamInterface<std::list<int>>
    {
        protected:
        
        void should_return_expected_list_after_removing_every_fifth(const std::list<int>& inputAndExpected)
        {
            should::should_return_expected_list_after_removing_every_fifth(inputAndExpected, inputAndExpected);
        }
    };

    TEST_P(should_remove_nothing, should_be_same_list_as_input)
    {
        should_return_expected_list_after_removing_every_fifth(GetParam());
    }

    INSTANTIATE_TEST_CASE_P(tests__single_linked_list__remove_every_fifth, should_remove_nothing,
        ::testing::Values(
            std::list<int>(),
            std::list<int>({1}),
            std::list<int>({1, 2}),
            std::list<int>({1, 2, 3}),
            std::list<int>({1, 2, 3, 4})
        )
    );
}