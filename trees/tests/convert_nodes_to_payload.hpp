#pragma once

#include "..\tree.hpp"

namespace tests__tree__of__ {
    template<typename T>
    std::list<T> convert_nodes_to_payload(const std::list<struct trees::tree_node<T>*>& path)
    {
        std::list<T> converted;
        std::transform(path.begin(), path.end(), std::back_inserter(converted), [](struct trees::tree_node<T>* node) { return node->payload; } );

        return converted;
    }

    template<typename T>
    std::list<std::list<T>> convert_nodes_to_payload(const std::list<std::list<struct trees::tree_node<T>*>>& pathes)
    {
        std::list<std::list<T>> converted;
        std::transform(pathes.begin(), pathes.end(), std::back_inserter(converted), [](const std::list<struct trees::tree_node<T>*>& path) { return convert_nodes_to_payload(path); });

        return converted;
    }
}