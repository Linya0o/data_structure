/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: main.c
 > Date     : 2022-12-03
 > Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/stack.h"

int main(int argc, char *argv[]) {
    Stack s = init_stack(5);

    create(s);
    output(s);
    printf("size : %zu\n", size(s));

    printf("=== now, start randomly popping and push data.\n");
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int op = rand() % 2;
        int ch = rand() % 26;
        switch (op) {
            case 0: {
                printf("push %c to Stack.\n", 'a'+ch);
                push(s, 'a'+ch);
            } break;
            case 1: {
                if (empty(s))
                    printf("Stack is now empty!\n");
                else
                    printf("pop %c in Stack.\n", pop(s));
            } break;
        }
        output(s), puts("");
    }

    return EXIT_SUCCESS;
}
