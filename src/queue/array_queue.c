/**
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: sequential_queue.c
 * Date     : 2022-12-06
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/queue.h"

struct queue_type {
    Item *contents;
    int front, rear;
};

static int maxsize;

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

/**
 * 关于循环队列的判空判满问题的解决方案
 * 1.设置标志位
 * 2.设置size属性
 * 3.牺牲一个单元
 **/
Queue queue(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (!q) terminate("Error in create queue: memory allocation failed.");

    Item *data = malloc(size * sizeof(Item));
    if (!data) terminate("Error in create queue: memory allocation failed.");

    *q = (struct queue_type) { .contents = data, .front = 0, .rear = 0 };
    maxsize = size;
    return q;
}

bool is_empty(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return q->front == q->rear;
}

bool is_full(const Queue q) {
    if (!q) terminate("queue does not exist.");

    return (q->rear + 1) % maxsize == q->front;
}

Item get_head(const Queue q) {
    if (!q) terminate("queue does not exist.");
    if (is_empty(q)) terminate("queue is empty.");

    return q->contents[q->front];
}

void push(const Queue q, Item i) {
    if (is_full(q)) terminate("queue has been full.");

    q->contents[q->rear] = i;
    q->rear = (q->rear + 1) % maxsize;
}

Item pop(const Queue q, Item *i) {
    if (is_empty(q)) terminate("queue is empty.");

    Item data = q->contents[q->front];
    q->front = (q->front + 1) % maxsize;
    if (i) *i = data;
    return data;
}
