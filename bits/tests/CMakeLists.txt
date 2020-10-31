cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This bits_tests)

set(Sources
    get_min_and_max_with_same_amount_of_bits_set/tests__all_bits_set
    get_min_and_max_with_same_amount_of_bits_set/tests__no_bits_set
    get_min_and_max_with_same_amount_of_bits_set/tests__one_bit_set.cpp
    get_min_and_max_with_same_amount_of_bits_set/tests__three_bits_set.cpp
    get_min_and_max_with_same_amount_of_bits_set/tests__two_bits_set.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
    bits
)

gtest_discover_tests(${This})
