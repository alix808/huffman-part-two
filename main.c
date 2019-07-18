#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "size.h"
#include "sort.h"
#include "freq.h"
#include "tree.h"
#include "codebook.h"

int main(int argc, char ** argv)
{   
    int size;
    int node_count;
    TreeNode * root;
    int leaf_count;
    int tree_height;
    
    size =       Execute_size(argv[1]); 
                 Execute_sort(size, argv[1]);
    node_count = Execute_freq(size, array);
    root =       Execute_tree(node_count);
                 Execute_codebook(root);



    return 0;  
}
