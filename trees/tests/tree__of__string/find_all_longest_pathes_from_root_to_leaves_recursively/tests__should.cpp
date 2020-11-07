#include <gtest\gtest.h>
#include <string>

#include "..\..\..\..\common\tests\asserts_collection_eq.hpp"
#include "..\..\..\..\common\vector.hpp"
#include "..\..\..\tree.hpp"

#include "..\..\convert_nodes_to_payload.hpp"
using namespace tests__tree__of__;
#include "..\typedef.hpp"
using namespace tests__tree__of__string__;

namespace tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively {
    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_empty_list_when_tree_has_no_nodes)
    {
        auto sut = tree();
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);
        
        ASSERT_EQ(0, longest_pathes_payloads.size());
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_with_one_path_of_root_when_tree_has_only_root)
    {
        auto sut = tree(new tree_node("R"));
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(1, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<std::string>({"R"}), longest_pathes_payloads[0]);
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_R_to_l)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l"),
                NULL
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(1, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l"}), longest_pathes_payloads[0]);
    }

    TEST(test__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_R_to_r)
    {
        auto sut = tree(
            new tree_node("R",
                NULL,
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(1, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "r"}), longest_pathes_payloads[0]);
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_R_to_l_and_path_of_R_to_r)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l"),
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(2, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l"}), longest_pathes_payloads[0]);
        ASSERT_EQ(std::list<string>({"R", "r"}), longest_pathes_payloads[1]);
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_R_to_l_to_lr_to_lrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        NULL,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(1, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l", "lr", "lrr"}), longest_pathes_payloads[0]);
    }

    TEST(test__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_R_to_l_to_lr_to_lrr_and_path_of_R_to_r_to_rr_to_rrl)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        NULL,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r",
                    NULL,
                    new tree_node("rr",
                        new tree_node("rrl"),
                        NULL
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(2, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l", "lr", "lrr"}), longest_pathes_payloads[0]);
        ASSERT_EQ(std::list<string>({"R", "r", "rr", "rrl"}), longest_pathes_payloads[1]);
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves_recursively, should_return_list_of_path_of_Rto_l_to_lr_to_lrr_and_path_of_R_to_r_to_rr_to_rrl_and_path_of_R_to_r_to_rr_to_rrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        NULL,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r",
                    NULL,
                    new tree_node("rr",
                        new tree_node("rrl"),
                        new tree_node("rrr")
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(3, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l", "lr", "lrr"}), longest_pathes_payloads[0]);
        ASSERT_EQ(std::list<string>({"R", "r", "rr", "rrl"}), longest_pathes_payloads[1]);
        ASSERT_EQ(std::list<string>({"R", "r", "rr", "rrr"}), longest_pathes_payloads[2]);
    }


    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l_to_ll_to_lll_and_path_of_R_to_r_to_rr_to_rrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll",
                        new tree_node("lll"),
                        NULL
                    ),
                    NULL
                ),
                new tree_node("r",
                    NULL,
                    new tree_node("rr",
                        NULL,
                        new tree_node("rrr")
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves_recursively();
        auto longest_pathes_payloads = common::to_vector(convert_nodes_to_payload(longest_pathes_nodes));

        ASSERT_EQ(2, longest_pathes_payloads.size());

        ASSERT_EQ(std::list<string>({"R", "l", "ll", "lll"}), longest_pathes_payloads[0]);
        ASSERT_EQ(std::list<string>({"R", "r", "rr", "rrr"}), longest_pathes_payloads[1]);
    }
}