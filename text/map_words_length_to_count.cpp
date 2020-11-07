#include <regex>

#include "map_words_length_to_count.hpp"

namespace text {
    map<unsigned int, unsigned int> map_words_length_to_count(const string& text)
    {
        map<unsigned int, unsigned int> words_length_to_count;

        regex words_boundary_regex("(i.\\s*?e.?)|(\\b[^\\s]+?(-[^\\s]+?)*\\b)|(\\b[^\\s]+?\\b)");
        auto words_boundary_regex_begin = std::sregex_iterator(text.begin(), text.end(), words_boundary_regex);
        auto words_boundary_regex_end = std::sregex_iterator();
 
        for(auto words_boundary_regex_it = words_boundary_regex_begin; words_boundary_regex_it != words_boundary_regex_end; ++words_boundary_regex_it)
        {
            if(regex_search(words_boundary_regex_it->str(), regex("^\\w")))
            {
                auto word_length = words_boundary_regex_it->length();
                auto words_length_to_count_lookup_by_word_length = words_length_to_count.find(word_length);
                if(words_length_to_count_lookup_by_word_length != words_length_to_count.end())
                {
                    words_length_to_count_lookup_by_word_length->second++;
                }
                else
                {
                    words_length_to_count.insert({word_length, 1});
                }
            }
        }

        return words_length_to_count;
    }
}