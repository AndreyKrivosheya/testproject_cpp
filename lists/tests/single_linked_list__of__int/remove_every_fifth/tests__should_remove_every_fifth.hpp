#include "tests__should.hpp"

namespace tests__single_linked_list__remove_every_fifth {
    class should_remove_every_fifth : public should, public ::testing::WithParamInterface<std::tuple<std::list<int>, std::list<int>>>
    {
        protected:
        
        void should_return_expected_list_after_removing_every_fifth(std::tuple<std::list<int>, std::list<int>> inputAndExpected)
        {
            should::should_return_expected_list_after_removing_every_fifth(std::get<0>(inputAndExpected), std::get<1>(inputAndExpected));
        }
    };
}