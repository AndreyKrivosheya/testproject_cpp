#pragma once

#include <algorithm>
#include <list>

#include "tree_node.hpp"

namespace trees
{
    template<typename T>
    class tree
    {
        private:

        typedef struct tree_node<T> node;
        typedef node* pnode;

        public:

        tree() : root(NULL)
        {
        }
        tree(pnode root) : root(root)
        {
        }
        virtual ~tree()
        {
            std::list<pnode> queue_to_delete;
            // go from root to leaves and delete one by one
            queue_to_delete.push_back(root);
            while(!queue_to_delete.empty())
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

        private:

        pnode root;

        // no copy constructor
        tree(const tree<T>& another);

        //////////////////////////////////////////////////////////////////////////////////////
        // find_all_longest_pathes_from_root_to_leaves recursive implementation
        //////////////////////////////////////////////////////////////////////////////////////
        
        public:

        std::list<std::list<pnode>> find_all_longest_pathes_from_root_to_leaves_recursively()
        {
            std::list<std::list<pnode>> longest_pathes;
            if(NULL != root)
            {
                find_all_longest_pathes_from_root_to_leaves_recursively(root, longest_pathes);
            }
            return longest_pathes;
        }

        private:

        void find_all_longest_pathes_from_root_to_leaves_recursively(pnode node, std::list<std::list<pnode>>& longest_pathes)
        {
            std::list<std::list<pnode>> longest_pathes_left, longest_pathes_right;
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
                longest_pathes.push_back(std::list<pnode>({ node }));
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

        //////////////////////////////////////////////////////////////////////////////////////
        // find_all_longest_pathes_from_root_to_leaves non-recursive implementation
        //////////////////////////////////////////////////////////////////////////////////////
        
        public:

        std::list<std::list<pnode>> find_all_longest_pathes_from_root_to_leaves()
        {
            std::list<std::list<pnode>> longest_pathes;
            if(NULL != root)
            {
                std::list<std::list<pnode>> queue_to_visit;
                // start from root and go node by node
                queue_to_visit.push_back(std::list<pnode>({ root }));
                while(!queue_to_visit.empty())
                {
                    auto path = queue_to_visit.front();
                    queue_to_visit.pop_front();
                    
                    auto path_deepest_node = path.back();
                    if((NULL != path_deepest_node->left) || (NULL != path_deepest_node->right))
                    {
                        // all the previous pathes detected as longest were not
                        longest_pathes.clear();
                        // because there's at least one path longer
                        if(/*NULL != path_deepest_node->left && */NULL == path_deepest_node->right)
                        {
                            // build path to left node of deepest node of current path
                            // ... no node to append to copy of current path as it won't be used any further
                            // ... append left node of deepest node of current path
                            path.push_back(path_deepest_node->left);
                            // save path for further visiting
                            queue_to_visit.push_back(path);
                        }
                        else if(NULL == path_deepest_node->left/* && NULL != path_deepest_node->right*/)
                        {
                            // build path to right node of deepest node of current path
                            // ... no node to append to copy of current path as it won't be used any further
                            // ... append right node of deepest node of current path
                            path.push_back(path_deepest_node->right);
                            // save path for further visiting
                            queue_to_visit.push_back(path);
                        }
                        else/* if(NULL != path_deepest_node->left && NULL != path_deepest_node->right)*/
                        {
                            if(NULL != path_deepest_node->left)
                            {
                                // build path to left node of deepest node of current path
                                // ... copy path to deepest node of current path
                                std::list<pnode> path_left(path);
                                // ... append left node of deepest node of current path
                                path_left.push_back(path_deepest_node->left);
                                // save path for further visiting
                                queue_to_visit.push_back(path_left);
                            }
                            if(NULL != path_deepest_node->right)
                            {
                                // build path to right node of deepest node of current path
                                // ... copy path to deepest node of current path
                                std::list<pnode> path_right(path);
                                // ... append right node of deepest node of current path
                                path_right.push_back(path_deepest_node->right);
                                // save path for further visiting
                                queue_to_visit.push_back(path_right);
                            }
                        }
                    }
                    else
                    {
                        // reached the leaf
                        longest_pathes.push_back(path);
                    }
                }
            }
            return longest_pathes;
        }
    };
}