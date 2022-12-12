/**
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: main.c
 * Date     : 2022-12-03
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/queue.h"

int main(int argc, char *argv[]) {
    Queue q = queue(25);
    int ch;
    fputs(">>> now, start reading data: ", stdout);
    while ((ch = getchar()) != '\n') push(q, ch);
    printf("=== the head of queue: %c\n", get_head(q));
    fputs(">>> now, start popping data.\n:::", stdout);
    while (!is_empty(q))
        printf(" <-%c", pop(q, 0));

    puts("");
    return EXIT_SUCCESS;
}
