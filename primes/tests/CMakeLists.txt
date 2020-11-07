cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This primes_tests)

set(Sources
    get_first_n_primes/tests__caching.cpp
    get_first_n_primes/tests__first_n_primes.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gmock
    gtest_main

    primes
)

gtest_discover_tests(${This})
