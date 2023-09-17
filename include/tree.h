/***********************************************************
 > Copyright (c) 2022 linya0o@163.com. All Rights Reserved.
 > File Name: tree.h
 > Date     : 2023-09-06
 > Mail     : linya0o@163.com
***********************************************************/
#ifndef _TREE_H_
#define _TREE_H_

#include <stddef.h>
#include <stdbool.h>

typedef char TreeData;
typedef struct tree_type *Tree;

Tree init_tree();
void destroy_tree(Tree tree);

void pre_order(const Tree tree);
void in_order(const Tree tree);
void post_order(const Tree tree);

// insert as Binary Search Tree
void insert(const Tree tree, TreeData e);

// create as Binary Search Tree
Tree create_tree(const Tree tree);

// build as Generalized List
void build_tree(const Tree tree);

// output as Generalized List
void output_tree(const Tree tree);

#endif