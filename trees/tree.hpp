#pragma once

#include <algorithm>
#include <list>

#include "tree_node.hpp"

namespace trees
{
    template<typename T>
    class tree
    {
        public:

        tree() : root(NULL)
        {
        }
        tree(struct tree_node<T>* root) : root(root)
        {
        }
        virtual ~tree()
        {
            std::list<struct tree_node<T>*> queue_to_delete;
            // go from root to leaves and delete one by one
            queue_to_delete.push_back(root);
            while(queue_to_delete.size() > 0)
            {
                auto to_delete = queue_to_delete.front();
                queue_to_delete.pop_front();
                if(NULL != to_delete)
                {
                    queue_to_delete.push_back(to_delete->left);
                    queue_to_delete.push_back(to_delete->right);
                    delete to_delete;
                }
            }
            
            root = NULL;
        }

        std::list<std::list<struct tree_node<T>*>> find_all_longest_pathes_from_root_to_leaves()
        {
            std::list<std::list<struct tree_node<T>*>> longest_pathes;
            if(NULL != root)
            {
                find_all_longest_pathes_from_root_to_leaves_recursively(root, longest_pathes);
            }
            return longest_pathes;
        }

        private:

        struct tree_node<T>* root;

        void find_all_longest_pathes_from_root_to_leaves_recursively(struct tree_node<T>* node, std::list<std::list<struct tree_node<T>*>>& longest_pathes)
        {
            std::list<std::list<struct tree_node<T>*>> longest_pathes_left, longest_pathes_right;
            if(NULL != node->left)
            {
                find_all_longest_pathes_from_root_to_leaves_recursively(node->left, longest_pathes_left);
            }
            if(NULL != node->right)
            {
                find_all_longest_pathes_from_root_to_leaves_recursively(node->right, longest_pathes_right);
            }
            
            if(longest_pathes_left.empty() && longest_pathes_right.empty())
            {
                longest_pathes.push_back(std::list<struct tree_node<T>*>({ node }));
            }
            else
            {
                auto longest_left_size = 0ul;
                if(!longest_pathes_left.empty())
                {
                    longest_left_size = longest_pathes_left.front().size();
                }
                auto longest_right_size = 0ul;
                if(!longest_pathes_right.empty())
                {
                    longest_right_size = longest_pathes_right.front().size();
                }
                
                auto longest_size = std::max(longest_left_size, longest_right_size);
                if(longest_left_size == longest_size)
                {
                    for(auto longest_pathes_left_it = longest_pathes_left.begin(); longest_pathes_left_it != longest_pathes_left.end(); ++longest_pathes_left_it)
                    {
                        longest_pathes_left_it->push_front(node);
                        longest_pathes.push_back(*longest_pathes_left_it);
                    }
                }
                if(longest_right_size == longest_size)
                {
                    for(auto longest_pathes_right_it = longest_pathes_right.begin(); longest_pathes_right_it != longest_pathes_right.end(); ++longest_pathes_right_it)
                    {
                        longest_pathes_right_it->push_front(node);
                        longest_pathes.push_back(*longest_pathes_right_it);
                    }
                }
            }
        }

        tree(const tree<T>& another);
    };
}