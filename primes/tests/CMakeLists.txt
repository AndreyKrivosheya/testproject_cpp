cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This primes_tests)

set(Sources
    get_first_n_primes__tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
    primes
)

gtest_discover_tests(${This})
