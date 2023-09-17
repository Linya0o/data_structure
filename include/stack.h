/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: stack.h
 * Date     : 2022-12-2
 * Mail     : linya0o@163.com
***********************************************************/
#ifndef _STACK_H_
#define _STACK_H_

#include <stddef.h>
#include <stdbool.h>

#define FORMAT(a) _Generic((a), \
    char:"%c", \
    int:"%d", \
    double:"%lf", \
    default:"%p")

typedef struct _node* StackData;
typedef struct stack_type *Stack;

Stack init_stack();
bool empty(const Stack s);
bool full(const Stack s);
size_t size(const Stack s);
StackData top(const Stack s);
void push(const Stack s, StackData i);
StackData pop(const Stack s);
Stack destroy_stack(const Stack s);
Stack create_stack(Stack s);
void output_stack(const Stack s);

#endif
