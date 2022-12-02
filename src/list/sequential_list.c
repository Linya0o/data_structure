/**
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: linked_list.c
 * Date     : 2022-11-25
 * Mail     : linya0o@163.com
 **/
#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

struct list_type {
    Item *data;
    unsigned length;
    unsigned max;
};

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

List list(int size) {
    List list = malloc(sizeof(struct list_type));
    if (!list)
        terminate("Error in create: memory allocation failed!");

    list->data = malloc(size * sizeof(Item));
    if (!list->data) {
        free(list);
        terminate("Error in create: memory allocation failed!");
    }

    list->max = size;
    list->length = 0;
    return list;
}

bool is_empty(const List list) {
    if (!list) terminate("list doesn't exsit.");

    return list->length;
}

void clear(List list) {
    if (!list) terminate("list doesn't exsit.");

    list->length = 0;
}

List destroy(List list) {
    if (!list) terminate("list doesn't exsit.");

    free(list->data);
    free(list);
    return EXIT_SUCCESS;
}

Item get(const List list, Position index, Item *e) {
    if (!list) terminate("list doesn't exsit");

    if (0 > index || list->length <= index)
        terminate("index is illegal or list is empty.");

    if (e) *e = list->data[index];
    return list->data[index];
}

Position locate(const List list, Item e) {
    if (!list) terminate("list doesn't exsit");

    for (size_t i = 0; i < list->length; i++)
        if (list->data[i] == e) return i;

    return 0;
}

/**
 * @list: the entry of list
 * @index: the index of target, 0 ~ length
 * @e: the inserted element
 **/
List insert(const List list, Position index, Item e) {
    if (!list) terminate("list doesn't exsit.");

    if (list->length == list->max) terminate("list has no free space");
    
    for (unsigned i = list->length; i > index; i--)
        list->data[i] = list->data[i-1];

    list->data[index] = e;
    list->length += 1;
    return list;
}

/**
 * @list: the entry of list
 * @index: the index of target, 0 ~ length-1
 * @e: to save removed element
 **/
Item delete(const List list, Position index, Item *e) {
    if (!list) terminate("list doesn't exsit.");

    if (list->length == 0 || list->length <= index) terminate("list is empty or position is illegal");
    
    Item value = list->data[index];
    for (unsigned i = index+1; i < list->length; i++)
        list->data[i-1] = list->data[i];

    list->length -= 1;
    if (e) *e = value;
    return value;
}

List create(List list) {
    if (!list) terminate("list doesn't exsit.");

    fputs("=== start reading the data(e.g. abcd...<cr>),\n=== type <cr> to finish: ", stdout);
    int ch;
    for (unsigned i = 0; i < list->max && (ch = getchar()) != '\n'; i++) {
        list->data[i] = ch;
        list->length++;
    }

    return list;
}

void output(const List list) {
    if (!list) terminate("list doesn't exsit.");
    fputs("Header", stdout);
    for (unsigned i = 0; i < list->length; i++)
        printf("->%c", list->data[i]);

    puts("");
}
