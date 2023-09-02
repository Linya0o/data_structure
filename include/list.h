/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: list.h
 * Date     : 2022-11-25
 * Mail     : linya0o@163.com
***********************************************************/
#ifndef _LIST_H_
#define _LIST_H_
#include <stddef.h>
#include <stdbool.h>

typedef char Item;
typedef unsigned Position;
typedef struct list_type *List;

List init_list(int size);
bool empty(const List list);
size_t size(const List list);
Position get_index(const List list, Item e);
Item *locate(const List list, Position index);
void clear(const List list);
List destroy(const List);
List insert(const List list, Position index, Item e);
Item delete(const List list, Position index, Item *e);
List create(const List list);
void output(const List list);

#endif
