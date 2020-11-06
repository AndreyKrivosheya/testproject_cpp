#pragma once

#include "..\..\tree.hpp"

namespace tests__tree__of__string__ {
    typedef struct trees::tree_node<std::string> tree_node;
    typedef trees::tree<std::string> tree;
}