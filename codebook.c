#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "codebook.h"
#include "tree.h"

void Leaf_count1(TreeNode * tn, int * freq)
{   
    if (tn == 0)
    {
        return;
    }
    TreeNode * lc = tn -> left;
    TreeNode * rc = tn -> right;
    if((lc == NULL) && (rc == NULL))
    {
        (* freq) ++;
        return;
    }
    Leaf_count1(lc, freq);
    Leaf_count1(rc, freq);
}

int Leaf_count2(TreeNode * tn)
{
    int freq = 0;
    Leaf_count1(tn, &freq);
    return freq;
}

int Tree_height(TreeNode * tn, int height)
{
    if(tn == 0)
    {
        return height;
    }
    int lh = Tree_height(tn -> left, height + 1);
    int rh = Tree_height(tn -> right, height + 1);
    if(lh < rh)
    {
        return rh;
    }
    if(lh > rh)
    {
        return lh;
    }
    return lh;
}

CodeBook * Codebook_create(int height)
{
    CodeBook * cb = malloc(sizeof(CodeBook));
    cb -> arr = (int *) malloc(sizeof(int) * height + 1);

    return cb;
}

void Populate_codebook(TreeNode * root, CodeBook * cb, int top)
{   
    TreeNode * lc = root -> left;
    TreeNode * rc = root -> right;

    if(lc != NULL)
    {
        cb -> arr[top] = 0;
        Populate_codebook(lc, cb, top + 1);
    }
    
    if(rc != NULL)
    {
        cb -> arr[top] = 1;
        Populate_codebook(rc, cb, top + 1);
    }

    if((lc == NULL) && (rc == NULL))
    {
        printf("%c: ", root -> value);
        Print_arr(cb -> arr, top);
    }
    
}

void Print_arr(int * arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

void Execute_codebook(TreeNode * root)
{
    int row = Leaf_count2(root);
    int col = Tree_height(root, 0);
    col ++;
    CodeBook * cb = Codebook_create(col);
    printf("\n\n");
    Populate_codebook(root, cb, 0);
}

