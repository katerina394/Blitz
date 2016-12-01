#include  < gtest/gtest.h>
#include "StructAndFunctions.h"
TEST(InvertNumber,  can_invert_a_positive_number) {
    EXPECT_EQ(321,  InvertNumber(123));
}
TEST(InvertNumber,  can_invert_a_negative_number) {
    EXPECT_EQ(-321,  InvertNumber(-123));
}
TEST(InvertNumber,  can_invert_a_figure) {
    EXPECT_EQ(5,  InvertNumber(5));
}
TEST(MaxCommonPrefix,  throws_when_any_pointer_is_NULL) {
    char **a  =  new char*[3];
    a[0]  =  "abcd";
    a[1]  =  0;
    a[2]  =  "lbhs";
    EXPECT_ANY_THROW(MaxCommonPrefix(a,  3));
    a  =  0;
    EXPECT_ANY_THROW(MaxCommonPrefix(a,  3));
}
TEST(MaxCommonPrefix,  can_find_max_common_prefix) {
    char **a  =  new char*[3];
    a[0]  =  "abcd";
    a[1]  =  "abfd";
    a[2]  =  "abhs";
    char*exp  =  "ab";
    char* res  =  MaxCommonPrefix(a,  3);
    for (int i = 0; exp[i] !=  0; i++)
        EXPECT_EQ(exp[i],  res[i]);
}
TEST(MaxCommonPrefix,  return_empty_string_when_there_is_no_common_prefix) {
    char **a  =  new char*[3];
    a[0]  =  "abcd";
    a[1]  =  "cbfd";
    a[2]  =  "lbhs";
    char *res  =  MaxCommonPrefix(a, 3);
    EXPECT_EQ(0,  res[0]);
}
TEST(MaxCommonPrefix,  can_find_max_common_prefix_when_all_strings_are_equal) {
    char **a  =  new char*[3];
    a[0]  =  "abcd";
    a[1]  =  "abcd";
    a[2]  =  "abcd";
    char*exp  =  "abcd";
    char* res  =  MaxCommonPrefix(a, 3);
    for (int i = 0; exp[i] !=  0; i++)
        EXPECT_EQ(exp[i],  res[i]);
}
TEST(InvertPairs,  throws_when_pointer_is_NULL) {
    CNode *list  =  0;
    EXPECT_ANY_THROW(InvertPairs(list));
}
TEST(InvertPairs,  can_invert_pairs_in_a_list_with_even_number_of_items) {
    CNode *list  =  0;
    CNode *node  =  new CNode;
    node->next  =  list;
    node->data  =  5;
    list  =  node;
    node  =  new CNode;
    node->next  =  list;
    node->data  =  6;
    list  =  node;
    node  =  new CNode;
    node->next  =  list;
    node->data  =  1;
    list  =  node;
    node  =  new CNode;
    node->next  =  list;
    node->data  =  6;
    list  =  node;
    CNode *res  =  InvertPairs(list);
    int a[]  =  {1, 6, 5, 6};
    for (int i = 0; i  <  4; i++) {
        EXPECT_EQ(a[i],  res->data);
        res  =  res->next;
    }
}
TEST(InvertPairs,  can_invert_pairs_in_a_list_with_odd_number_of_items) {
    CNode *list  =  0;
    CNode *node  =  new CNode;
    node->next  =  list;
    node->data  =  5;
    list  =  node;
    node  =  new CNode;
    node->next  =  list;
    node->data = 6;
    list = node;
    node = new CNode;
    node->next = list;
    node->data = 1;
    list = node;
    node = new CNode;
    node->next = list;
    node->data = 6;
    list = node;
    node = new CNode;
    node->next = list;
    node->data = 3;
    list = node;
    CNode *res = InvertPairs(list);
    int a[] = {6, 3, 6, 1, 5};
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i],  res->data);
        res = res->next;
    }
}
TEST(SearchPairs,  throws_when_pointer_is_NULL) {
    int *a = 0;
    EXPECT_ANY_THROW(SearchPairs(a, 3, 4));
}
TEST(SearchPairs,  throws_when_n_is_negative) {
    int a[5] = {0, 6, 2, 1, 7};
    EXPECT_ANY_THROW(SearchPairs(a, -3, 4));
}
TEST(SearchPairs,  can_find_pairs) {
    int a[5] = {0, 6, 2, 1, 7};
    int** exp;
    exp = new int*[2];
    exp[0] = new int[2];
    exp[1] = new int[2];
    exp[0][0] = 0;
    exp[0][1] = 7;
    exp[1][0] = 6;
    exp[1][1] = 1;
    int** res = SearchPairs(a, 5, 7);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            EXPECT_EQ(exp[i][j],  res[i][j]);
}
TEST(SearchPairs,  return_NULL_when_there_is_no_pairs) {
    int a[5] = {0, 6, 2, 1, 7};
    EXPECT_EQ(NULL,  SearchPairs(a, 5, 15));
}
