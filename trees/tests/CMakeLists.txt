cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This trees_tests)

set(Headers
    tree__of__string/typedef.hpp
    convert_nodes_to_payload.hpp
)

set(Sources
    tree__of__string/find_all_longest_pathes_from_root_to_leaves_recursively/tests__should.cpp
    tree__of__string/find_all_longest_pathes_from_root_to_leaves/tests__should.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gtest_main

    common
    trees
)

gtest_discover_tests(${This})
