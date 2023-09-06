/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: array_stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static const int BLOCK_SIZE = 5;

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

static bool expand(const Stack s) {
    if (!s) return EXIT_FAILURE;

    int resize = s->size + BLOCK_SIZE;
    Item *new_contents = realloc(s->contents, resize * sizeof(Item));
    if (!new_contents)
        terminate("Error in realloc: stack could be inflated.");

    s->contents = new_contents;
    s->size = resize;

    return true;
}

Stack init_stack(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could be not created.");

    Item *data = malloc(size * sizeof(Item));
    if (data == NULL) {
        free(s);
        terminate("Error in create: stack could be not created.");
    }
    *s = (struct stack_type) { .contents = data, .top = 0, .size = size };

    return s;
}

Stack destroy(const Stack s) {
    if (!s) terminate("stack is not exist.");

    free(s->contents);
    free(s);

    return EXIT_SUCCESS;
}

void clear(const Stack s) {
    if (!s) terminate("stack is not exist.");
    s->top = 0;
}

bool empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == 0;
}

bool full(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == s->size;
}

Item top(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (empty(s)) terminate("stack is empty.");

    return s->contents[s->top-1];
}

void push(const Stack s, Item i) {
    if (!s) terminate("stack is not exist.");
    if (full(s)) {
        if (!expand(s)) return;
        printf("successfully scale capacity!\n");
    }
    s->contents[s->top++] = i;
}

Item pop(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (empty(s)) terminate("Error in pop: stack is empty.");

    return s->contents[--s->top];
}

size_t size(const Stack s) {
    return s->top;
}

Stack create(Stack s) {
    if (!s) terminate("stack doesn't exsit.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");

    int ch;
    while ((ch = getchar()) != '\n') push(s, ch);

    return s;
}

void output(const Stack s) {
    if (!s) terminate("stack doesn't exsit.");

    printf("::: Stack(%zu):[", size(s));
    for (int i = 0; i < s->top; i++) {
        i && printf(" ");
        printf("%c", s->contents[i]);
        fflush(stdout);
    }
    printf("\n");
}
