#pragma once

#include <list>

#include "single_linked_list_node.hpp"

namespace lists
{
    template<typename T>
    class single_linked_list
    {
        public:

        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;

        single_linked_list() : head(nullptr), tail(nullptr)
        {
        }
        virtual ~single_linked_list()
        {
            while(nullptr != head)
            {
                auto to_delete = head;
                head = head->next;
                delete to_delete;
            }
            tail = nullptr;
        }

        std::list<T> to_list()
        {
            std::list<T> list;
            for(auto current = head; nullptr != current; current = current->next)
            {
                list.push_back(current->payload);
            }

            return list;
        }

        void push_back(const T& payload)
        {
            if(nullptr == tail)
            {
                head = tail = new single_linked_list_node<T>(payload);
            }
            else
            {
                tail = tail->next = new single_linked_list_node<T>(payload);
            }
        }

        void remove_every_fifth()
        {
            for(auto i = 1, current = head; nullptr != current; i++, current = current->next)
            {
                if(i == 4)
                {
                    if(nullptr != current->next)
                    {
                        auto to_delete = current->next;
                        current->next = current->next->next;
                        i = 0;
                        delete to_delete;
                    }
                }
            }
        }

        void reverse()
        {
            // and the last will become first
            std::swap(tail, head);

            struct single_linked_list_node<T>* prev = nullptr;
            auto curr = tail/*former head*/;
            while(nullptr != curr)
            {
                auto temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
        }

        private:

        struct single_linked_list_node<T>* head;
        struct single_linked_list_node<T>* tail;

        single_linked_list(const single_linked_list<T>& another);
    };
}