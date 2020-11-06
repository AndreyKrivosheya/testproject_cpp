cmake_minimum_required(VERSION 3.18)

set(This trees)

enable_testing()

set(Headers
    tree_node.hpp
    tree.hpp
)
set(Sources
    tree_node.cpp
    tree.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})
target_link_libraries(${This} PUBLIC
    common
)

add_subdirectory(tests)