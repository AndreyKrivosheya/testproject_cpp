cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This common_tests)

set(Sources
    list__of__int/to_vector/tests__same_items.cpp
    vector__of__int/to_vector/tests__same.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
)

gtest_discover_tests(${This})

