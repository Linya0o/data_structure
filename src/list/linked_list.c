/**********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: linked_list.c
 * Date     : 2022-11-25
 * Mail     : linya0o@163.com
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/list.h"

typedef struct list_type {
    Item data;
    struct list_type *next;
}node;

static void terminate(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

/**
 * @list: the entrance of list
 * @index: the index of target: [0, length)
 * @return: the element's address of the index position
 **/
static List get(const List list, Position index) {
    if (!list) terminate("list doesn't exsit.");

    unsigned len = size(list);
    if (index < 0 || index >= len)
        terminate("index is illegal or list is empty.");

    List target = list->next;
    while (index--) {
        target = target->next;
    }

    return target;
}

/* head node assumed */
List init_list(const int size) {
    List list = malloc(sizeof(struct list_type));
    if (!list)
        terminate("Error in create: memory allocation failed!");

    *list = (struct list_type) { 0 };

    return list;
}

bool empty(const List list) {
    if (!list)
        terminate("list doesn't exsit.");

    return !list->next;
}

/**
 * @list: the entrance of list
 * @index: the index of target: [0, length)
 **/
Item *locate(const List list, Position index) {
    if (!list) terminate("list doesn't exsit.");

    unsigned len = size(list);
    if (index < 0 || index >= len)
        terminate("index is illegal or list is empty.");

    List p = list->next;
    while (index--) {
        p = p->next;
    }

    return &p->data;
}

/**
 * @list: the entrance of list
 * @e: the inserted element
 * @return: the index of target: [0, length)
 **/
Position get_index(const List list, Item e) {
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

    if (!empty(list)) clear(list);
    free(list);

    return EXIT_SUCCESS;
}

size_t size(const List list) {
    unsigned len = 0;
    List p = list->next;
    while (p) {
        len++;
        p = p->next;
    }

    return len;
}

/**
 * @list: the entrance of list
 * @index: the index of target: [0, length]
 * @e: the inserted element
 **/
List insert(const List list, Position index, Item e) {
    if (!list) terminate("list doesn't exsit");

    if (0 > index || size(list) < index)
        terminate("index is illegal.");

    List p = list;
    while (index--) p = p->next;

    node *temp = malloc(sizeof(struct list_type));
    *temp = (struct list_type) {
        .next = p->next,
        .data = e
    };
    p->next = temp;

    return list;
}

/**
 * @list: the entrance of list
 * @index: the index of target: [0, length)
 * @e: to save removed element
 **/
Item delete(const List list, Position index, Item *e) {
    if (!list) terminate("list doesn't exsit");

    if (0 > index || size(list) <= index)
        terminate("index is illegal.");

    List *indirect = &list->next;
    List entry = get(list, index);

    while ((*indirect) != entry) {
        indirect = &(*indirect)->next;
    }

    List temp = *indirect;
    Item data = temp->data;
    *indirect = entry->next;
    if (e) *e = data;
    free(temp);

    return data;
}

/* head insertion */
List create(const List list) {
    if (!list) terminate("list doesn't exsit.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");
    int ch;
    while ((ch = getchar()) != '\n') {
        node *p = malloc(sizeof(struct list_type));
        if (!p) terminate("Error in create: memory allocation failed!");

        *p = (struct list_type) { .data = ch, .next = NULL };

        p->next = list->next;
        list->next = p;
    }

    return list;
}

void output(const List list) {
    if (!list) terminate("list doesn't exsit");

    printf("::: List(%zu):[", size(list));
    for (List ptr = list->next; ptr; ptr = ptr->next) {
        ptr != list->next && printf(" ");
        printf("%c", ptr->data);
    }
    printf("]\n");
}
