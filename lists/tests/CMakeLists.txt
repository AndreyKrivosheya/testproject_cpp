cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This lists_tests)

set(Headers
    single_linked_list__of__int/remove_every_fifth/tests__should.hpp
    single_linked_list__of__int/remove_every_fifth/tests__should_remove_every_fifth.hpp
)

set(Sources
    single_linked_list__of__int/remove_every_fifth/tests__should_remove_nothing.cpp
    single_linked_list__of__int/remove_every_fifth/tests__should_remove_5.cpp
    single_linked_list__of__int/remove_every_fifth/tests__should_remove_5_and_10.cpp
    single_linked_list__of__int/remove_every_fifth/tests__should_remove_5_10_and_15.cpp
    single_linked_list__of__int/reverse/tests__same_items.cpp
    single_linked_list__of__int/to_list/tests__same_items.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gmock
    gtest_main

    lists
)

gtest_discover_tests(${This})
