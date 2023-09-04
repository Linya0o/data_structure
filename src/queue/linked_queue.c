/***********************************************************
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: linked_queue.c
 * Date     : 2022-12-06
 * Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/queue.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front, *rear;
};

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Queue init_queue(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (!q) terminate("Error in create queue: memory allocation failed.");

    struct node *head = malloc(sizeof(struct node));
    if (!head) terminate("Error in create queue: memory allocation failed.");
    *head = (struct node) { 0 };
    *q = (struct queue_type) { .front = head, .rear = head };
    return q;
}

bool empty(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return  q->front == q->rear;
}

bool full(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return false;
}

Item front(const Queue q) {
    if (!q) terminate("queue does not exist.");
    if (empty(q)) terminate("queue is empty.");
    return q->front->next->data;
}

void push(const Queue q, Item i) {
    if (!q) terminate("queue does not exist.");

    struct node *tmp = malloc(sizeof(struct node));
    if (!tmp) terminate("Error in push: memory allocation failed.");

    *tmp = (struct node) { .data = i, .next = NULL };
    q->rear->next = tmp;
    q->rear = tmp;
}

Item pop(const Queue q, Item *i) {
    if (!q) terminate("queue does not exist.");
    if (empty(q)) terminate("queue is empty.");

    struct node *p = q->front->next;
    Item data = p->data;
    q->front->next = p->next;
    if (q->rear == p) q->rear = q->front;
    if (i) *i = data;
    free(p);
    return data;
}
size_t size(const Queue q) {
    if (!q) terminate("queue doesn't exsit.");

    unsigned count = 0;
    for (struct node *ptr = q->front; ptr != NULL; ptr = ptr->next, count++) {}
    return count;
}

Queue create(Queue q) {
    if (!q) terminate("queue doesn't exsit.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");

    int ch;
    while ((ch = getchar()) != '\n') push(q, ch);

    return q;
}

void output(const Queue q) {
    printf("::: Queue:[");
    for (struct node *ptr = q->front->next; ptr != NULL; ptr = ptr->next) {
        ptr != q->front->next && printf(" ");
        printf("%c", ptr->data);
    }
    printf("]\n");
}
