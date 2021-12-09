/*
** (not) EPITECH PROJECT, 2021
** Libfox
** File description:
** UT: Create a binary tree
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tests/wrappers/wrap_malloc.h"

#include "fox_datastruct.h"

Test(create_tree, normal_usage)
{
    foxtree_t tree = NULL;

    cr_expect_not(tree_create(&tree));
    cr_assert_not_null(tree);
    cr_expect_eq(tree->nodes, 0);
    cr_expect_null(tree->trunk);
}

Test(create_tree, broken_malloc, .fini = fix_malloc)
{
    foxtree_t tree = NULL;

    malloc_counter = 0;
    cr_expect(tree_create(&tree));
    cr_assert_null(tree);
}
