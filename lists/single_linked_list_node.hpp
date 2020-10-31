#pragma once

namespace lists
{
    template<typename T>
    struct single_linked_list_node
    {
        single_linked_list_node(const T& payload) : next(NULL), payload(payload)
        {
        }

        struct single_linked_list_node<T>* next;
        T payload;

        private:
    };
}