#ifndef CODEBOOK_H
#define CODEBOOK_H
#include "tree.h"

typedef struct codebook
{
    int * arr;
} CodeBook;

void Leaf_count1(TreeNode * tn, int * freq);

int Leaf_count2(TreeNode * tn);

int Tree_height(TreeNode * tn, int height);

void Init_codebook(int row, int col);

void Execute_codebook(TreeNode * root);

CodeBook * Codebook_create(int height);

void Populate_codebook(TreeNode * root, CodeBook * cb, int top);

void Print_arr(int * arr, int n);

#endif