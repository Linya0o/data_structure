/**
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: main.c
 * Date     : 2022-11-23
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

int main(int argc, char *argv[]) {
    List l = list(30);
    create(l);
    output(l);
    printf(">>> get the value of the index 2: %c\n", get(l, 2, 0));
    printf(">>> locate the position of the value 'w': %d\n", locate(l, 'w'));
    puts(">>> insert 'z' on the index 4 of list.");
    insert(l, 4, 'z');
    output(l);
    puts(">>> delete element of the index 2.");
    printf(">>> the element %c is deleted already.\n", delete(l, 2, 0));
    output(l);
    puts(">>> the list will be destroyed.");
    l = destroy(l);
    output(l);

    return EXIT_SUCCESS;
}
