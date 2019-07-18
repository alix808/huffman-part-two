#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include "freq.h"

TreeNode * TreeNode_create(char val, int fr)
{
    TreeNode * tn = malloc(sizeof(TreeNode));
    tn -> left = NULL;
    tn -> right = NULL;
    tn -> value = val;
    tn -> freq = fr;
    return tn;
}

TreeNode * Tree_fuse(TreeNode * tn1, TreeNode * tn2)
{
    TreeNode * tn = malloc(sizeof(TreeNode));
    tn -> left = tn1;
    tn -> right = tn2;
    tn -> value = '\0';
    tn -> freq = tn1 -> freq + tn2 -> freq;
    return tn;
}

ListNode * ListNode_create(TreeNode * tn)
{
    ListNode * ln = malloc(sizeof(ListNode));
    ln -> next = NULL;
    ln -> tnptr = tn;
    return ln;
}

ListNode * List_insert(ListNode * head, ListNode * ln)
{
    if (head == NULL)
    {
        return ln;
    }
    int a = (head -> tnptr) -> freq;
    int b = (ln -> tnptr) -> freq;
    if(a > b)
    {   
        ln -> next = head;
        return ln;
    }
    head -> next = List_insert(head -> next, ln);
    return head;
}


ListNode * List_build(FreqNode * fnptr, int node_count)
{   
    ListNode * head = NULL;
    int i;
    for(i=0; i<node_count; i++)
    {
        TreeNode * tn = TreeNode_create(fnptr[i].value, fnptr[i].freq);
        ListNode * ln = ListNode_create(tn);
        head = List_insert(head, ln);
    }
    return head;
}

void Tree_print(TreeNode * tn, int level)
{
    if (tn == NULL)
    {
        return;
    }
    TreeNode * lc = tn -> left;
    TreeNode * rc = tn -> right;
    Tree_print(lc, level + 1);
    Tree_print(rc, level + 1);
    int i;
    for (i=0; i < level; i++)
    {
        printf("-----");
    }
    printf("freq: %d ", tn -> freq);
    if ((lc == NULL) && (rc == NULL))
    {   
        printf("value: %d, %c ", tn -> value, tn -> value);
    }
    printf("\n");
}

void List_print(ListNode * head)
{
    if (head == NULL)
    {
        return;
    }
    Tree_print(head -> tnptr, 0);
    List_print(head -> next);
}

ListNode * Fuse_list(ListNode * head)
{   
    while((head -> next) != NULL)
    {   
        ListNode * second = head -> next;
        ListNode * third = second -> next;

        TreeNode * tn1 = head -> tnptr;
        TreeNode * tn2 = second -> tnptr;

        free(head);
        free(second);
        head = third;

        TreeNode * mrg = Tree_fuse(tn1, tn2);
        ListNode * ln = ListNode_create(mrg);
        head = List_insert(head, ln);
    }
    return head;
}

TreeNode * Get_root(ListNode * head)
{
    TreeNode * root = head -> tnptr;
    free(head);
    return root;
}

TreeNode * Execute_tree(int node_count)
{
    ListNode * head1 = List_build(fn, node_count);
    ListNode * head2 = Fuse_list(head1);
    printf("\n\n");
    List_print(head2);
    TreeNode * root = Get_root(head2);
    return root;
}