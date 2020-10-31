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

        single_linked_list() : head(NULL), tail(NULL)
        {
        }
        virtual ~single_linked_list()
        {
            while(NULL != head)
            {
                auto to_delete = head;
                head = head->next;
                delete to_delete;
            }
            tail = NULL;
        }

        std::list<T> to_list()
        {
            std::list<T> list;
            for(auto current = head; NULL != current; current = current->next)
            {
                list.push_back(current->payload);
            }

            return list;
        }

        void push_back(const T& payload)
        {
            if(NULL == tail)
            {
                head = tail = new single_linked_list_node<T>(payload);
            }
            else
            {
                tail->next = new single_linked_list_node<T>(payload);
                tail = tail->next;
            }
        }

        void remove_every_fifth()
        {
            for(auto i = 1, current = head; NULL != current; i++, current = current->next)
            {
                if(i == 4)
                {
                    if(NULL != current->next)
                    {
                        auto to_delete = current->next;
                        current->next = current->next->next;
                        i = 0;
                        delete to_delete;
                    }
                }
            }
        }

        private:

        single_linked_list_node<T>* head;
        single_linked_list_node<T>* tail;
    };
}