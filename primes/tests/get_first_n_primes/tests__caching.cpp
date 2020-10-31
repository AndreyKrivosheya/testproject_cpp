#include <list>
#include <vector>

#include <gtest\gtest.h>

#include "..\..\..\common\tests\asserts_collection_eq.hpp"
#include "..\..\get_first_n_primes.hpp"

namespace tests__get_first_n_primes {
    TEST(tests__get_first_n_primes, should_cache_no_more_than_10240_first_primes)
    {
        auto max_capacity = 10u * 1024;

        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_capacity());
        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_size());

        // generate max_capacity + 1 first primes
        EXPECT_EQ(max_capacity + 1, primes::get_first_n_primes(max_capacity + 1).size());
        // ... cache should not exceed max_capacity
        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_capacity());
        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_size());

        // generate max_capacity + 2 first primes
        EXPECT_EQ(max_capacity + 2, primes::get_first_n_primes(max_capacity + 2).size());
        // ... cache should not exceed max_capacity
        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_capacity());
        EXPECT_GE(max_capacity, primes::get_first_n_primes_cache_size());
    }
}