/***********************************************************
 * Copyright (c) 2022 Author. All Rights Reserved.
 * File Name: linked_binary_tree.h
 * Date     : 2023-09-06
 * Mail     : linya0o@163.com
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "include/tree.h"
#include "include/stack.h"

/**
 * 树的存储结构:
 *  [1] 双亲表示法
 *  [2] 孩子表示法
 *  [3] 孩子兄弟表示法
 */
typedef struct _node{
    TreeData data;
    bool ltag, rtag;
    struct _node *lchild, *rchild;
}Node;

struct tree_type {
    struct _node *root;
    int length;
};

static
void terminate(void *ptr, const char *message) {
    if (ptr) return;
    perror(message);
    exit(EXIT_FAILURE);
}

static
void clear_tree_node(Node *root) {
    if (root == NULL) return;
    clear_tree_node(root->lchild);
    clear_tree_node(root->rchild);
    free(root);
    return;
}

Tree init_tree() {
    Tree tree = malloc(sizeof(struct tree_type));
    terminate(tree,
        "Error in initialization: tree could be not created");

    *tree = (struct tree_type) {0};
    return tree;
}

void destroy_tree(Tree tree) {
    terminate(tree, "tree is not exist.");
    clear_tree_node(tree->root);
    free(tree);
    return;
}

static
Node *insert_node(Node *root, TreeData e, bool *status) {
    if (root == NULL) {
        Node *node = malloc(sizeof(struct _node));
        terminate(node,
            "Error in insert_node: memory allocation failed.");
        *node = (struct _node) { .data = e };
        *status = true;
        return node;
    }
    if (root->data > e)
        root->lchild = insert_node(root->lchild, e, status);
    if (root->data < e)
        root->rchild = insert_node(root->rchild, e, status);

    return root;
}

void insert(const Tree tree, TreeData e) {
    terminate(tree, "tree is not exist.");
    bool status = false;
    tree->root = insert_node(tree->root, e, &status);
    tree->length += status;
}

static
void pre_order_node(const Node *root) {
    if (root == NULL) return;
    printf(" %c", root->data);
    pre_order_node(root->lchild);
    pre_order_node(root->rchild);
    return;
}

void pre_order(const Tree tree) {
    terminate(tree, "tree is not exist.");
    printf("::: Pre_Order :");
    pre_order_node(tree->root);
    printf("\n");
}

static
void in_order_node(const Node *root) {
    if (root == NULL) return;
    in_order_node(root->lchild);
    printf(" %c", root->data);
    in_order_node(root->rchild);
    return;
}

void in_order(const Tree tree) {
    terminate(tree, "tree is not exist.");
    printf("::: In_Order  :");
    in_order_node(tree->root);
    printf("\n");
}

static
void post_order_node(const Node *root) {
    if (root == NULL) return;
    post_order_node(root->lchild);
    post_order_node(root->rchild);
    printf(" %c", root->data);
    return;
}

void post_order(const Tree tree) {
    terminate(tree, "tree is not exist.");
    printf("::: Post_Order:");
    post_order_node(tree->root);
    printf("\n");
}

Tree create_tree(const Tree tree) {
    terminate(tree, "tree is not exist.");

    printf(">>> start reading the data(e.g. abcd...<cr>)\n");
    printf(">>> type <cr> to finish: ");
    int ch;
    while ((ch = getchar()) != '\n') {
        insert(tree, ch);
    }

    return tree;
}

static
void output_node(const Node *root) {
    if (root == NULL) return;
    printf("%c", root->data);
    if (!root->lchild  && !root->rchild) return;
    printf("(");
    output_node(root->lchild);
    printf(",");
    output_node(root->rchild);
    printf(")");
    return;
}

void output_tree(const Tree tree) {
    terminate(tree, "tree is not exist.");
    printf("Tree(%d): ", tree->length);
    output_node(tree->root);
    printf("\n");
    return;
}

static
Node *build(const char *str, int *nodes) {
    Stack s = init_stack();
    int ch;
    enum status { BUILD_LCHIRD, BUILD_RCHIRD };
    enum status flag = BUILD_LCHIRD;

    Node *temp = NULL, *root = NULL;
    while (*str) {
        switch (*str) {
            default: {
                temp = malloc(sizeof(Node));
                terminate(temp,
                    "Error in build: memory allocation failed.");
                *temp = (Node) { .data = *str };
                ++*nodes;
                if (!empty(s) && flag == BUILD_LCHIRD)
                    top(s)->lchild = temp;
                else if (!empty(s) && flag == BUILD_RCHIRD)
                    top(s)->rchild = temp;
            } break;
            case '(': {
                push(s, temp);
                flag = BUILD_LCHIRD;
            } break;
            case ',': {
                flag = BUILD_RCHIRD;
            } break;
            case ')': {
                root = pop(s);
            } break;
            case ' ': break;
        }
        str++;
    }
    destroy_stack(s);
    if (temp && root == NULL) root = temp;
    return root;
}

void build_tree(const Tree tree) {
    terminate(tree, "tree is not exist.");
    int nodes = 0;
    char str[100] = {0};
    printf(">>> start reading generalized list sequence.\n");
    printf(">>> type <cr> to finish: ");
    scanf("%s", str);
    tree->root = build(str, &nodes);
    tree->length = nodes;
    return ;
}
