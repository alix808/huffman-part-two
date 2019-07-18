#ifndef SORT_H
#define SORT_H

char * array;

void Allocate_memory(int size);

void Init_array(int size);

void Print_array();

void Read_file(char * filename);

void Sort_array(int size);

int Int_compare(const void * a, const void * b);

void Execute_sort(int size, char * filename);

void Clean_array();

#endif

