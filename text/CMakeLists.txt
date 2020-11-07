cmake_minimum_required(VERSION 3.18)

set(This text)

enable_testing()

set(Headers
    map_words_length_to_count.hpp
)
set(Sources
    map_words_length_to_count.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})
target_link_libraries(${This} PUBLIC
)

add_subdirectory(tests)