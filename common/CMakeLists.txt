cmake_minimum_required(VERSION 3.18)

set(This common)

set(Headers
    list.hpp
    vector.hpp
)
set(Sources
    empty.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})

add_subdirectory(tests)