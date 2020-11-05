cmake_minimum_required(VERSION 3.18)

set(This lists)

enable_testing()

set(Headers
    single_linked_list_node.hpp
    single_linked_list.hpp
)
set(Sources
    single_linked_list_node.cpp
    single_linked_list.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})
target_link_libraries(${This} PUBLIC
    common
)

add_subdirectory(tests)