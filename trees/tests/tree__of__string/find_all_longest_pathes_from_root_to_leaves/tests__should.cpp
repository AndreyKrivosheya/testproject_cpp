#include <gmock\gmock.h>
#include <gtest\gtest.h>
#include <string>

#include "..\..\..\tree.hpp"

#include "..\..\convert_nodes_to_payload.hpp"
using namespace tests__tree__of__;
#include "..\typedef.hpp"
using namespace tests__tree__of__string__;

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::IsEmpty;

namespace tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves {
    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_empty_list_when_tree_has_no_nodes)
    {
        auto sut = tree();
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);
        
        ASSERT_THAT(
            longest_pathes_payloads,
            IsEmpty()
        );
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_with_one_path_of_root_when_tree_has_only_root)
    {
        auto sut = tree(new tree_node("R"));
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R"})
            )
        );
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l"),
                nullptr
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l"})
            )
        );
    }

    TEST(test__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_r)
    {
        auto sut = tree(
            new tree_node("R",
                nullptr,
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "r"})
            )
        );
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l_and_path_of_R_to_r)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l"),
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l"}),
                ElementsAreArray({"R", "r"})
            )
        );
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l_to_lr_to_lrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        nullptr,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r")
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l", "lr", "lrr"})
            )
        );
    }

    TEST(test__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l_to_lr_to_lrr_and_path_of_R_to_r_to_rr_to_rrl)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        nullptr,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r",
                    nullptr,
                    new tree_node("rr",
                        new tree_node("rrl"),
                        nullptr
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l", "lr", "lrr"}),
                ElementsAreArray({"R", "r", "rr", "rrl"})
            )
        );
    }

    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_Rto_l_to_lr_to_lrr_and_path_of_R_to_r_to_rr_to_rrl_and_path_of_R_to_r_to_rr_to_rrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll"),
                    new tree_node("lr",
                        nullptr,
                        new tree_node("lrr")
                    )
                ),
                new tree_node("r",
                    nullptr,
                    new tree_node("rr",
                        new tree_node("rrl"),
                        new tree_node("rrr")
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l", "lr", "lrr"}),
                ElementsAreArray({"R", "r", "rr", "rrl"}),
                ElementsAreArray({"R", "r", "rr", "rrr"})
            )
        );
    }


    TEST(tests__tree__of__string__find_all_longest_pathes_from_root_to_leaves, should_return_list_of_path_of_R_to_l_to_ll_to_lll_and_path_of_R_to_r_to_rr_to_rrr)
    {
        auto sut = tree(
            new tree_node("R",
                new tree_node("l",
                    new tree_node("ll",
                        new tree_node("lll"),
                        nullptr
                    ),
                    nullptr
                ),
                new tree_node("r",
                    nullptr,
                    new tree_node("rr",
                        nullptr,
                        new tree_node("rrr")
                    )
                )
            )
        );
        auto longest_pathes_nodes = sut.find_all_longest_pathes_from_root_to_leaves();
        auto longest_pathes_payloads = convert_nodes_to_payload(longest_pathes_nodes);

        ASSERT_THAT(
            longest_pathes_payloads,
            ElementsAre(
                ElementsAreArray({"R", "l", "ll", "lll"}),
                ElementsAreArray({"R", "r", "rr", "rrr"})
            )
        );
    }
}