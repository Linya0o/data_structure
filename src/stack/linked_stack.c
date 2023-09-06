/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: linked_stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
***********************************************************/
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

Stack init_stack(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) terminate("Error in create: stack could be not created.");

    s->top = NULL;
    return s;
}

Stack destroy(const Stack s) {
    if (!s) terminate("stack is not exist.");
    clear(s);
    free(s);
    return EXIT_SUCCESS;
}

void clear(const Stack s) {
    if (!s) terminate("stack is not exist.");
    while (!empty(s))
        pop(s);
}

bool empty(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return s->top == NULL;
}

bool full(const Stack s) {
    if (!s) terminate("stack is not exist.");
    return false;
}

Item top(const Stack s) {
    if (!s) terminate("stack is not exist.");
    if (empty(s)) terminate("stack is empty.");
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
    if (empty(s)) terminate("Error in pop: stack is empty.");

    struct node *old_top = s->top;
    Item i = old_top->data;
    s->top = old_top->next;
    free(old_top);

    return i;
}

size_t size(const Stack s) {
    struct node *ptr = s->top;
    int count = 0;
    while (ptr) {
        ptr = ptr->next;
        count++;
    }
    return count;
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
    printf("::: Stack(%zu): ", size(s));
    for (struct node *ptr = s->top; ptr; ptr = ptr->next) {
        ptr != s->top && printf(" ");
        printf("%c", ptr->data);
    }
    printf("]\n");
}
