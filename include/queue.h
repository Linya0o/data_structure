/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: queue.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
***********************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stddef.h>

typedef char Item;
typedef struct queue_type *Queue;

Queue init_queue(int size);
bool empty(const Queue q);
bool full(const Queue q);
size_t size(const Queue q);
Item front(const Queue q);
void push(const Queue q, Item i);
Item pop(const Queue q, Item *i);
Queue create(Queue q);
void output(const Queue q);

#endif
