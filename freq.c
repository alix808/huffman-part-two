#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "freq.h"

int Node_count(int size, char * arr)
{
    int i;
    int node_count = 0;
    for(i=0; i<size; i++)
    {
        if(arr[i] != arr[i+1])
        {
            node_count ++;
        }
    }
    return node_count;
}

void Allocate_freq(int node_count)
{
    fn = (FreqNode *) malloc(sizeof(FreqNode) * node_count);
}

void Init_freq(int node_count)
{
    int i;
    for(i=0; i<node_count; i++)
    {
        fn[i].value = '\0';
        fn[i].freq = 0;
    }
}

void Freq_count(int size, char * arr)
{   
    int i;
    int fr = 1;
    int ind = 0;
    char onechar = '\0';
    for(i=0; i<size; i++)
    {
        if(arr[i] == arr[i+1] && arr[i] != '\0')
        {
            fr ++;
        }
        if(arr[i] != arr[i+1])
        {   
            onechar = arr[i];
            Insert_node(onechar, fr, ind);
            fr = 1; 
            ind ++;
        }
    }
}

void Insert_node(char val, int fr, int i)
{
    fn[i].value = val;
    fn[i].freq = fr;
}

void Print_freq(int node_count)
{
    int i;
    for(i = 0; i<node_count; i++) {
        printf("value: %c, frequency: %d", fn[i].value, fn[i].freq);
        printf("\n");
    }
}

void Sort_freq(int node_count)
{
    qsort(fn, node_count, sizeof(FreqNode), Freq_compare);
}

int Freq_compare(const void * a, const void * b)
{
    const FreqNode * ia = (const FreqNode *) a;
    const FreqNode * ib = (const FreqNode *) b;
    const int iv1 = ia -> freq;
    const int iv2 = ib -> freq;
    return (iv1 - iv2);
}

int Execute_freq(int size, char * arr)
{
    int node_count;
    node_count = Node_count(size, arr);
    printf("Number of freq nodes: %d", node_count);
    printf("\n\n");
    Allocate_freq(node_count);
    Init_freq(node_count);
    Freq_count(size, arr);
    Sort_freq(node_count);
    Print_freq(node_count);
    return node_count;
}



