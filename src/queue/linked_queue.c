/**
* Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
* File Name: linked_queue.c
* Date     : 2022-12-06
* Mail     : linya0o@163.com
**/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

Queue queue(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (!q) terminate("Error in create queue: memory allocation failed.");
    
    struct node *head = malloc(sizeof(struct node));
    if (!head) terminate("Error in create queue: memory allocation failed.");
    *head = (struct node) { 0 };
    *q = (struct queue_type) { .front = head, .rear = head };
    return q;
}

bool is_empty(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return  q->front == q->rear;
}

bool is_full(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return false;
}

Item get_head(const Queue q) {
    if (!q) terminate("queue does not exist.");
    if (is_empty(q)) terminate("queue is empty.");
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
    if (is_empty(q)) terminate("queue is empty.");
    
    struct node *p = q->front->next;
    Item data = p->data;
    q->front->next = p->next;
    if (q->rear == p) q->rear = q->front;
    if (i) *i = data;
    free(p);
    return data;
}
