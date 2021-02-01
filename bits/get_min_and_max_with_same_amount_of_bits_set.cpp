#include <numeric>
#include <vector>

#include "get_min_and_max_with_same_amount_of_bits_set.hpp"

using namespace std;

namespace bits
{
    pair<unsigned int, unsigned int> get_min_and_max_with_same_amount_of_bits_set(unsigned int number)
    {
        auto min = 0u, max = 0u;
        for(;number != 0; number = number & number - 1)
        {
            min = (min << 1) | 1;
            max = (max >> 1) | 0x80000000;
        }

        return make_pair(min, max);
    }
}