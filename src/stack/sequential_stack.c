/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: sequential_stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Stack stack(int size) {
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

void make_empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    s->top = 0;
}

bool is_empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == 0;
}

bool is_full(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == s->size;
}

Item get_head(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (is_empty(s)) terminate("stack is empty.");
    return s->contents[s->top-1];
}

void push(const Stack s, Item i) {
    if (!s) terminate("stack is not exist.");
    if (is_full(s)) terminate("Error in push: stack is full.");
    s->contents[s->top++] = i;
}

Item pop(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (is_empty(s)) terminate("Error in pop: stack is empty.");
    return s->contents[--s->top];
}
