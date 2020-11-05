#pragma once
#include <vector>

using namespace std;

namespace common
{
    template<typename T>
    constexpr vector<T>& to_vector(vector<T>& vector)
    {
         return vector;
    }

    template<typename T>
    constexpr const vector<T>& to_vector(const vector<T>& vector)
    {
        return vector;
    }
}