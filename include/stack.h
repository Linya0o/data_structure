/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
***********************************************************/
#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stddef.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack init_stack(int size);
Stack destroy(const Stack s);
void clear(const Stack s);
bool empty(const Stack s);
bool full(const Stack s);
Item top(const Stack s);
void push(const Stack s, Item i);
Item pop(const Stack s);
size_t size(const Stack s);
Stack create(Stack s);
void output(const Stack s);

#endif
