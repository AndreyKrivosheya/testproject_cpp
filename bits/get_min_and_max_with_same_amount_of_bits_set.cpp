#include <numeric>
#include <vector>

#include "get_min_and_max_with_same_amount_of_bits_set.hpp"

using namespace std;

namespace bits
{
    pair<unsigned int, unsigned int> get_min_and_max_with_same_amount_of_bits_set(const unsigned int& number)
    {
        if(number == 0)
        {
            return make_pair(0u, 0u);
        }
        else
        {
            const unsigned int maxUnsignedInt = ((unsigned int)-1);
            if(number == maxUnsignedInt)
            {
                return make_pair(maxUnsignedInt, maxUnsignedInt);
            }
            else
            {
                static const vector<unsigned int> indicies { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
                
                auto lambda_to_count_bits_of_a_number =
                    [&](unsigned int a, unsigned int b) {
                        return a + ((number & (1u << b)) ? 1 : 0);
                    };
                auto n = accumulate(indicies.begin(), indicies.end(), 0u, lambda_to_count_bits_of_a_number);
                
                auto lambda_to_build_min_and_max_numbers =
                    [&](unsigned int a, unsigned int b) {
                        return a | (1 << b);
                    };
                auto min = accumulate(indicies.begin(), next(indicies.begin(), n), 0u, lambda_to_build_min_and_max_numbers);
                auto max = accumulate(indicies.rbegin(), next(indicies.rbegin(), n), 0u, lambda_to_build_min_and_max_numbers);
                
                return make_pair(min, max);
            }
        }
    }
}