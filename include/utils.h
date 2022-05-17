#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <stdlib.h>

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// MACROS// // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
#define bool  int
#define true  1
#define false 0
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// FUNCTIONS// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
void swap(int* a, int* b);
void reverse_array(int* array, int size);
int* sub_array(int* array, int start, int end);
int max(int a, int b);
int* copy_array(int* from, int fsize, int* to, int tsize);
void print_array(int* array, int size);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //



void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int* array, int size)
{
    for(int i = 0; i <= (size/2)-1; i++)
        swap(array+i, array+(size-1-i));
}

int* sub_array(int* array, int start, int end)
{
    int* subarr = (int*)malloc(end-start+1);
    for(int i = start; i <= end; i++)
        subarr[i - start] = array[i];
    return subarr;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int* copy_array(int* from, int fsize, int* to, int tsize)
{
    if(to == NULL)
        to = (int*)malloc(sizeof(int) * fsize);
    for(int i = 0; i < fsize; i++)
        to[i] = from[i];
    return to;
}

void print_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

#endif //utils_h
