/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: array.c
 * Date     : 2022-11-25
 * Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

struct list_type {
    Item *data;
    unsigned length;
    unsigned capacity;
};

static const int BLOCK_SIZE = 5;

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

static int array_inflate(const List list, size_t resize) {
    if (!list) return EXIT_FAILURE;

    Item* new_ptr = realloc(list->data, resize);
    if (!new_ptr)
        terminate("Error in realloc: array could be inflated.");

    list->data = new_ptr;
    list->capacity = resize;

    return 0;
}

List init_list(int size) {
    List list = malloc(sizeof(struct list_type));
    if (!list)
        terminate("Error in create: memory allocation failed!");

    list->data = malloc(size * sizeof(Item));
    if (!list->data) {
        free(list);
        terminate("Error in create: memory allocation failed!");
    }

    list->capacity = size;
    list->length = 0;

    return list;
}

bool empty(const List list) {
    if (!list) terminate("list doesn't exsit.");

    return !list->length;
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

size_t size(const List list) {
    return list->length;
}

Item *locate(const List list, Position index) {
    if (!list) terminate("list doesn't exsit");
    if (0 > index)
        terminate("index is illegal or list is empty.");
    if (index >= list->capacity)
        array_inflate(list, (index / BLOCK_SIZE + 1) * BLOCK_SIZE);

    return &list->data[index];
}

Position get_index(const List list, Item e) {
    if (!list) terminate("list doesn't exsit");

    for (size_t i = 0; i < list->length; i++) {
        if (list->data[i] == e) return i;
    }

    return -1;
}

/**
 * @list: the entry of list
 * @index: the index of target: [0 ~ length)
 * @e: the inserted element
 **/
List insert(const List list, Position index, Item e) {
    if (!list) terminate("list doesn't exsit.");

    if (0 > index || list->length <= index) return list;
    if (list->length == list->capacity)
        array_inflate(list, list->capacity+BLOCK_SIZE);

    for (unsigned i = list->length; i > index; i--)
        list->data[i] = list->data[i-1];

    list->data[index] = e;
    list->length += 1;

    return list;
}

/**
 * @list: the entrance of list
 * @index: the index of target: [0 ~ length)
 * @e: to save removed element
 **/
Item delete(const List list, Position index, Item *e) {
    if (!list) terminate("list doesn't exsit.");

    if (list->length == 0 || list->length <= index)
        terminate("list is empty or position is illegal");

    Item value = list->data[index];
    for (unsigned i = index+1; i < list->length; i++)
        list->data[i-1] = list->data[i];

    list->length -= 1;
    if (e) *e = value;

    return value;
}

List create(List list) {
    if (!list) terminate("list doesn't exsit.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");
    int ch;
    for (unsigned i = 0; i < list->capacity && (ch = getchar()) != '\n'; i++) {
        list->data[i] = ch;
        list->length++;
    }

    return list;
}

void output(const List list) {
    if (!list) terminate("list doesn't exsit.");

    printf("::: List(%zu):[", size(list));
    for (unsigned i = 0; i < list->length; i++) {
        i && printf(" ");
        printf("%c", list->data[i]);
    }
    printf("]\n");
}
