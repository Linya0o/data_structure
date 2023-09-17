/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: main.c
 > Date     : 2022-12-03
 > Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/tree.h"
#include "include/stack.h"

int main(int argc, char *argv[]) {
    Tree tree = init_tree();
    build_tree(tree);
    output_tree(tree);

    printf("\n=== now, start randomly insert data.\n");
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int offset = rand() % 26;
        insert(tree, 'a'+offset);
        output_tree(tree);
    }

    printf("\n=== traverse sequence.\n");
    pre_order(tree);
    in_order(tree);
    post_order(tree);

    return EXIT_SUCCESS;
}
