#pragma once
#include <map>
#include <string>

using namespace std;

namespace text
{
    map<unsigned int, unsigned int> map_words_length_to_count(const string& text);
}