#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "size.h"

int Execute_size(char * filename)
{
    FILE * fptr = fopen(filename, "r");
    int size = 0;
    while (!feof (fptr))
    {
        int onechar = fgetc(fptr);
        if (onechar != EOF)
        {
            size ++;
        }
    }
    fclose(fptr);
    return size;
}