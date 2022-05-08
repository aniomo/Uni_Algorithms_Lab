#ifndef sorting_h
#define sorting_h

#include "utils.h"



void merge(int* array, int p, int q, int r, int* count)
{
    int* low_half = sub_array(array, p, q);
    int* high_half = sub_array(array, q+1, r);
    int i = 0, j = 0, k = p;
    while(i < (q-p+1) && j < (r-q))
    {
        (*count)++;
        if(low_half[i] < high_half[j])
            array[k++] = low_half[i++];
        else
            array[k++] = high_half[j++];
    }
    while(i < (q-p+1))
        array[k++] = low_half[i++];
    while(j < (r-q))
        array[k++] = high_half[j++];
    free(low_half);
    free(high_half);
}

void merge_sort(int* array, int p, int r, int* count)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(array, p, q, count);
        merge_sort(array, q+1, r, count);
        merge(array, p, q, r, count);
    }
}

int partition(int* array, int p, int r, int* count)
{
    int q = p, j = p;
    int pivot = array[r];
    while(j < r)
    {
        (*count)++;
        if(array[j] > pivot)
            j++;
        else
            swap(array+(q++), array+(j++));
    }
    swap(array+q, array+r);
    return q;
}

void quick_sort(int* array, int p, int r, int* count)
{
    
    if(p < r-1)
    {
        int q = partition(array, p, r, count);
        quick_sort(array, p, q-1, count);
        quick_sort(array, q+1, r, count);
    }
}

#endif //sorting_h
