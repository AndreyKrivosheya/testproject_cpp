#pragma once 
#include <list>
#include <vector>

using namespace std;

namespace common
{
    template<typename T>
    vector<T> to_vector(const list<T>& list)
    {
        return vector<T>(list.begin(), list.end());
    }
}