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
                auto min = 0u, max = 0u;
                for(auto numberTemp = number; numberTemp != 0; numberTemp = numberTemp >> 1)
                {
                    if((numberTemp & 1u) == 1u)
                    {
                        min = (min << 1) | 1;
                        max = (max >> 1) | 0x80000000;
                    }
                }

                return make_pair(min, max);
            }
        }
    }
}