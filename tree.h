#ifndef TREE_H
#define TREE_H
#include "freq.h"

typedef struct treenode
{
    struct treenode * left;
    struct treenode * right;
    char value;
    int freq;
} TreeNode;

typedef struct listnode
{
    struct listnode * next;
    TreeNode * tnptr;
} ListNode;

TreeNode * TreeNode_create(char val, int fr);

TreeNode * Tree_fuse(TreeNode * tn1, TreeNode * tn2);

ListNode * ListNode_create(TreeNode * tn);

ListNode * List_insert(ListNode * head, ListNode * ln);

ListNode * List_build(FreqNode * fnptr, int node_count);

void Tree_print(TreeNode * tn, int level);

void List_print(ListNode * head);

ListNode * Fuse_list(ListNode * head);

TreeNode * Get_root(ListNode * head);

TreeNode * Execute_tree(int node_count);


#endif