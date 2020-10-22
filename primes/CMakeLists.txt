cmake_minimum_required(VERSION 3.18)

set(This primes)

enable_testing()

set(Headers
    get_first_n_primes.hpp
)
set(Sources
    get_first_n_primes.cpp
)

add_library(${This} STATIC ${Sources} ${Headerss})
target_link_libraries(${This} PUBLIC
    common
)

add_subdirectory(tests)