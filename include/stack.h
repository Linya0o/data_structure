/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
 **/
#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack stack(int size);
Stack destroy(const Stack s);
void make_empty(const Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
Item get_head(const Stack s);
void push(const Stack s, Item i);
Item pop(const Stack s);

#endif
