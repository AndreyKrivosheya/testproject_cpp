cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This bits_tests)

set(Sources
    get_min_and_max_with_same_amount_of_bits_set__tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
    bits
)

gtest_discover_tests(${This})
