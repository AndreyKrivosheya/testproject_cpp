cmake_minimum_required(VERSION 3.18)
include(GoogleTest)

set(This text_tests)

set(Sources
    map_words_length_to_count/tests__free_text.cpp
    map_words_length_to_count/tests__no_words.cpp
    map_words_length_to_count/tests__one_word.cpp
    map_words_length_to_count/tests__special_case_word_with_dash.cpp
    map_words_length_to_count/tests__special_case_word_with_digits.cpp
    map_words_length_to_count/tests__special_word_ie.cpp
    map_words_length_to_count/tests__two_words.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC "-static"
    gmock
    gtest_main

    text
)

gtest_discover_tests(${This})
