#ifndef FREQ_H
#define FREQ_H

typedef struct freqnode
{
    char value;
    int freq;
} FreqNode;

FreqNode * fn;

int Node_count(int size, char * arr);

void Allocate_freq(int node_count);

void Init_freq(int node_count);

void Freq_count(int size, char * arr);

void Insert_node(char val, int fr, int i);

void Sort_freq(int node_count);

int Freq_compare(const void * a, const void * b);

void Print_freq(int node_count);

int Execute_freq(int size, char * arr);

#endif