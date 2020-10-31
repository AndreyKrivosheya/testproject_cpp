#include "tests__should_remove_every_fifth.hpp"

namespace tests__single_linked_list__remove_every_fifth {
    class should_remove_5_and_10 : public should_remove_every_fifth
    {
    };

    TEST_P(should_remove_5_and_10, should_be_input_list_without_5_and_10)
    {
        should_return_expected_list_after_removing_every_fifth(GetParam());
    }

    INSTANTIATE_TEST_CASE_P(single_linked_list__remove_every_fifth__tests, should_remove_5_and_10,
        ::testing::Values(
            std::make_tuple(
                std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
                std::list<int>({1, 2, 3, 4,    6, 7, 8, 9})
            ),
            std::make_tuple(
                std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}),
                std::list<int>({1, 2, 3, 4,    6, 7, 8, 9,     11})
            ),
            std::make_tuple(
                std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}),
                std::list<int>({1, 2, 3, 4,    6, 7, 8, 9,     11, 12})
            ),
            std::make_tuple(
                std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}),
                std::list<int>({1, 2, 3, 4,    6, 7, 8, 9,     11, 12, 13})
            ),
            std::make_tuple(
                std::list<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}),
                std::list<int>({1, 2, 3, 4,    6, 7, 8, 9,     11, 12, 13, 14})
            )
        )
    );
}