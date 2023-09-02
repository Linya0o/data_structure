/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: main.c
 > Date     : 2022-12-03
 > Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/list.h"

int main(int argc, char *argv[]) {
    List li = init_list(10);

    create(li);
    output(li);

    /* visit every elements in order */
    printf("=== visit every elements in order:\n");
    for (int i = 0; i < size(li); i++) {
        Item *e = locate(li, i);
        int index = get_index(li, *e);
        printf("[%d] = %c\n", i, *e);
    }

    /* random insertion */
    printf("=== random insertion:\n");
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int num = rand() % size(li);
        printf("[insert %c at %2d] ", 'A'+i, num);
        insert(li, num, 'A'+i);
        output(li);
    }

    /* delete every elements and destroy list */
    printf("=== delete elements:\n");
    while (size(li)) {
        delete(li, 0, NULL);
        printf("size: %zu\n", size(li));
        output(li);
    }
    if (empty(li))
        printf("list now is empty!\n");
    destroy(li);

    return EXIT_SUCCESS;
}
