/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: list.h
 * Date     : 2022-11-25
 * Mail     : linya0o@163.com
 **/
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

typedef char Item;
typedef unsigned Position;
typedef struct list_type *List;

List list(int size);
bool is_empty(const List list);
unsigned length(const List list);
Item get(const List list, Position index, Item *e);
Position locate(const List list, Item e);
void clear(const List list);
List destroy(const List list); 
List insert(const List list, Position index, Item e);
Item delete(const List list, Position index, Item *e);
List create(const List list);
void output(const List list);

#endif
