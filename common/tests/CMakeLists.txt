cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This common_tests)

set(Sources
    list__to_vector__tests.cpp
    vector__to_vector__tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
)

gtest_discover_tests(${This})

