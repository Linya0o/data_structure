/***********************************************************
 * Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 * File Name: sequential_queue.c
 * Date     : 2022-12-06
 * Mail     : linya0o@163.com
***********************************************************/
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

static bool expand(const Queue q) {
    unsigned resize = maxsize;
    Item *new_contents = NULL;
    while (resize) {
        new_contents = malloc((resize + maxsize) * sizeof(Item));
        if (new_contents) break;
        resize >>= 1;
    }
    if (!new_contents)
        terminate("Error in malloc: queue could be inflated.");
    for (unsigned i = q->front, j = 0; j < maxsize-1; j++) {
        new_contents[j] = q->contents[(i + j) % maxsize];
    }
    free(q->contents);
    *q = (struct queue_type) {
        .contents = new_contents,
        .front = 0,
        .rear = maxsize-1,
    };
    maxsize += resize;
    return true;
}

/**
 * 关于循环队列的判空判满问题的解决方案
 * 1.设置标志位
 * 2.设置size属性
 * 3.牺牲一个单元
 **/
Queue init_queue(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (!q) terminate("Error in create queue: memory allocation failed.");

    Item *data = malloc(size * sizeof(Item));
    if (!data) terminate("Error in create queue: memory allocation failed.");

    *q = (struct queue_type) { .contents = data, .front = 0, .rear = 0 };
    maxsize = size;
    return q;
}

bool empty(const Queue q) {
    if (!q) terminate("queue does not exist.");
    return q->front == q->rear;
}

bool full(const Queue q) {
    if (!q) terminate("queue does not exist.");

    return (q->rear + 1) % maxsize == q->front;
}

size_t size(const Queue q) {
    if (!q) terminate("queue doesn't exsit.");

    unsigned count = 0;
    for (unsigned i = q->front; i != q->rear; i++, count++) {}

    return count;
}

Item front(const Queue q) {
    if (!q) terminate("queue does not exist.");
    if (empty(q)) terminate("queue is empty.");

    return q->contents[q->front];
}

void push(const Queue q, Item i) {
    if (full(q)) {
        if (!expand(q)) return;
        printf("successfully scale capacity!\n");
    }
    q->contents[q->rear] = i;
    q->rear = (q->rear + 1) % maxsize;
}

Item pop(const Queue q, Item *i) {
    if (empty(q)) terminate("queue is empty.");

    Item data = q->contents[q->front];
    q->front = (q->front + 1) % maxsize;
    if (i) *i = data;
    return data;
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
    if (!q) terminate("queue doesn't exsit.");

    printf("::: Queue:[");
    for (int i = q->front; i != q->rear; i = (i + 1) % maxsize) {
        i != q->front && printf(" ");
        printf("%c", q->contents[i]);
    }
    printf("]\n");
}
