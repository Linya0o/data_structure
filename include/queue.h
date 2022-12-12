/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: queue.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
 **/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef char Item;
typedef struct queue_type *Queue;

Queue queue(int size);
bool is_empty(const Queue q);
bool is_full(const Queue q);
Item get_head(const Queue q);
void push(const Queue q, Item i);
Item pop(const Queue q, Item *i);

#endif
