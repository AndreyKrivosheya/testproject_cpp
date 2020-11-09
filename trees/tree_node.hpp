#pragma once
#include <cstddef>

namespace trees
{
    template<typename T>
    struct tree_node
    {
        tree_node(const T& payload)
            : left(nullptr), right(nullptr), payload(payload)
        {
        }
        tree_node(const T& payload, struct tree_node<T>* left, struct tree_node<T>* right)
            : left(left), right(right), payload(payload)
        {
        }

        struct tree_node<T>* left;
        struct tree_node<T>* right;
        T payload;
    };
}