#include <list>
#include <vector>

#include <gtest\gtest.h>

#include "..\..\common\list.hpp"
#include "..\..\common\vector.hpp"

TEST(list__to_vector__tests, should_return_new_empty_vector)
{
    auto list = std::list<int> {};
    auto expected = std::vector<int> {};
    auto actual = common::to_vector(expected);
    ASSERT_NE(&expected, &actual);
    ASSERT_EQ(expected.size(), actual.size());
    ASSERT_EQ(0, actual.size());
}

TEST(list__to_vector__tests, should_return_new_vector_with_same_one_item)
{
    auto list = std::list<int> {1};
    auto expected = std::vector<int> {1};
    auto actual = common::to_vector(expected);
    ASSERT_NE(&expected, &actual);
    ASSERT_EQ(expected.size(), actual.size());
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], actual[i] ) << "i = " << i;
    }
}

TEST(list__to_vector__tests, should_return_new_vector_with_same_two_items)
{
    auto list = std::list<int> {1, 2};
    auto expected = std::vector<int> {1, 2};
    auto actual = common::to_vector(expected);
    ASSERT_NE(&expected, &actual);
    ASSERT_EQ(expected.size(), actual.size());
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], actual[i] ) << "i = " << i;
    }
}

TEST(list__to_vector__tests, should_return_new_vector_with_same_three_items)
{
    auto list = std::list<int> {1, 2, 3};
    auto expected = std::vector<int> {1, 2, 3};
    auto actual = common::to_vector(expected);
    ASSERT_NE(&expected, &actual);
    ASSERT_EQ(expected.size(), actual.size());
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], actual[i] ) << "i = " << i;
    }
}

TEST(list__to_vector__tests, should_return_new_vector_with_same_ten_items)
{
    auto list = std::list<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto expected = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto actual = common::to_vector(expected);
    ASSERT_NE(&expected, &actual);
    ASSERT_EQ(expected.size(), actual.size());
    for(size_t i = 0; i < expected.size(); i++)
    {
        EXPECT_EQ(expected[i], actual[i] ) << "i = " << i;
    }
}