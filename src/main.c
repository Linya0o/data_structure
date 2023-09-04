/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: main.c
 > Date     : 2022-12-03
 > Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/queue.h"

int main(int argc, char *argv[]) {
    Queue q = init_queue(5);

    create(q);
    output(q);
    printf("size : %zu\n", size(q));

    printf("=== now, start randomly popping and push data.\n");
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int op = rand() % 2;
        int ch = rand() % 26;
        switch (op) {
            case 0: {
                printf("push %c to Queue.\n", 'a'+ch);
                push(q, 'a'+ch);
            } break;
            case 1: {
                if (empty(q))
                    printf("Queue is now empty!\n");
                else
                    printf("pop %c in Queue.\n", pop(q, 0));
            } break;
        }
        output(q), puts("");
    }

    return EXIT_SUCCESS;
}
