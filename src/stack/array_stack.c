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
    StackData *contents;
    int top;
    int size;
};

static const int BLOCK_SIZE = 10;

static
void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

static
bool expand(const Stack s) {
    if (!s) return EXIT_FAILURE;

    int resize = s->size + BLOCK_SIZE;
    StackData *new_contents = realloc(s->contents, resize * sizeof(StackData));
    if (!new_contents)
        terminate("Error in realloc: stack could be inflated.");

    s->contents = new_contents;
    s->size = resize;

    return true;
}

Stack init_stack() {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could be not created.");

    StackData *data = malloc(BLOCK_SIZE * sizeof(StackData));
    if (data == NULL) {
        free(s);
        terminate("Error in create: stack could be not created.");
    }
    *s = (struct stack_type) { .contents = data, .top = 0, .size = BLOCK_SIZE };

    return s;
}

static
void clear_node(const Stack s) {
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

size_t size(const Stack s) {
    return s->top;
}

StackData top(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (empty(s)) terminate("stack is empty.");

    return s->contents[s->top-1];
}

void push(const Stack s, StackData i) {
    if (!s) terminate("stack is not exist.");
    if (full(s)) {
        if (!expand(s)) return;
        printf("successfully scale capacity!\n");
    }
    s->contents[s->top++] = i;
}

StackData pop(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (empty(s)) terminate("Error in pop: stack is empty.");

    return s->contents[--s->top];
}

Stack destroy_stack(const Stack s) {
    if (!s) terminate("stack is not exist.");

    free(s->contents);
    free(s);

    return EXIT_SUCCESS;
}

Stack create_stack(Stack s) {
    if (!s) terminate("stack doesn't exsit.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");

    int ch;
    while ((ch = getchar()) != '\n') push(s, ch);

    return s;
}

void output_stack(const Stack s) {
    if (!s) terminate("stack doesn't exsit.");

    printf("::: Stack(%zu):[", size(s));
    for (int i = 0; i < s->top; i++) {
        i && printf(" ");
        printf(FORMAT(s->contents[i]), s->contents[i]);
        fflush(stdout);
    }
    printf("\n");
}
