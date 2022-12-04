/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: linked_stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/stack.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Stack stack(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) terminate("Error in create: stack could be not created.");

    s->top = NULL;
    return s;
}

Stack destroy(const Stack s) {
    if (!s) terminate("stack is not exist.");
    make_empty(s);
    free(s);
    return EXIT_SUCCESS;
}

void make_empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    while (!is_empty(s))
        pop(s);
}

bool is_empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == NULL;
}

bool is_full(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return false;
}

Item get_head(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (is_empty(s)) terminate("stack is empty.");
    return s->top->data;
}

void push(const Stack s, Item i) {
    if (!s) terminate("stack is not exist.");
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) terminate("Error in push: stack is full.");

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(const Stack s) {
    if (!s) terminate("stack is not exist.");

    if (is_empty(s)) terminate("Error in pop: stack is empty.");

    struct node *old_top = s->top;
    Item i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}
