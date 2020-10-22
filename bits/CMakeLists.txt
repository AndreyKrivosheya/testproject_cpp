cmake_minimum_required(VERSION 3.18)

set(This bits)

enable_testing()

set(Headers
    get_min_and_max_with_same_amount_of_bits_set.hpp
)
set(Sources
    get_min_and_max_with_same_amount_of_bits_set.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})
target_link_libraries(${This} PUBLIC
    common
)

add_subdirectory(tests)