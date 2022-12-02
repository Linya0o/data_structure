/**
* Copyright (c) 2022 Author. All Rights Reserved.
* File Name: linked_list.c
* Date     : 2022-11-25
* Mail     : linya0o@163.com
**/
#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"

typedef struct list_type {
    Item data;
    struct list_type *next;
}node;

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

List list(const int size) {
    List list = malloc(sizeof(struct list_type));
    if (!list)
        terminate("Error in create: memory allocation failed!");

    *list = (struct list_type) { 0 };
    return list;
}

        bool is_empty(const List list) {
    if (!list)
        terminate("list doesn't exsit.");

    return list->next == NULL ? true : false;
}

Item get(const List list, unsigned index, Item *e) {
    if (!list) terminate("list doesn't exsit.");

    unsigned len = length(list);
    if (index < 0 || index >= len)
        terminate("index is illegal or list is empty.");

    List p = list->next;
    while (index) {
        p = p->next;
        index--;
    }
    if (e) *e = p->data;
    return p->data;
}

Position locate(const List list, Item e) {
    if (!list) terminate("list doesn't exsit.");

    List p = list->next;
    for (unsigned i = 0; list; i++) {
        if (p->data == e) return i;
        p = p->next;
    }

    return -1;
}

void clear(const List list) {
    if (!list) terminate("list doesn't exsit.");

    List p = list->next;
    node *tmp;
    while (p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

List destroy(List list) {
    if (!list) terminate("list doesn't exsit.");

    if (!is_empty(list)) clear(list);
    free(list);
    return EXIT_SUCCESS;
}

unsigned length(const List list) {
    unsigned len = 0;
    List p = list;
    while (p) {
        len++;
        p = p->next;
    }

    return len;
}

/**
 * @list: the entry of list
 * @index: the index of target, 0 ~ length
 * @e: the inserted element
 **/
List insert(const List list, Position index, Item e) {
    if (!list) terminate("list doesn't exsit");

    if (0 > index || length(list) < index)
        terminate("index is illegal.");

    List p = list;
    while (index--) p = p->next;
    node *tmp = malloc(sizeof(struct list_type));
    *tmp = (struct list_type) { .next = p->next, .data = e };
    p->next = tmp;
    return list;
}

/**
 * @list: the entry of list
 * @index: the index of target, 0 ~ length-1
 * @e: to save removed element
 **/
Item delete(const List list, Position index, Item *e) {
    if (!list) terminate("list doesn't exsit");

    if (0 > index || length(list) <= index)
        terminate("pos is illegal.");

    List pre = list, cur = list->next;
    while (index-- > 0) { pre = cur; cur = cur->next; }
    pre->next = cur->next;
    Item data = cur->data;
    if (e) *e = data;
    free(cur);
    return data;
}

List create(const List list) {
    if (!list) terminate("list doesn't exsit.");

    fputs("=== start reading the data(e.g. abcd...<cr>),\n=== type <cr> to finish: ", stdout);
    int ch;
    while ((ch = getchar()) != '\n') {
        node *p = malloc(sizeof(struct list_type));
        if (!p)
            terminate("Error in create: memory allocation failed!");

        *p = (struct list_type) { .data = ch, .next = NULL };

        p->next = list->next;
        list->next = p;
    }
    return list;
}

void output(const List list) {
    if (!list)
        terminate("list doesn't exsit");

    fputs("Header", stdout);
    List p = list->next;
    while (p) {
        printf("->%c", p->data);
        p = p->next;
    }
    puts("");
}
