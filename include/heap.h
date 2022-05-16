#ifndef heap_h
#define heap_h

#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#define HEAP_TYPE int
#define HEAP_NULL 0

typedef struct heap
{
    int arr_size, heap_size;
    HEAP_TYPE* heap_arr;
}heap;

////////////////////////////////////////////////////////////////////////////////////////
// Utility Functions
bool heap_is_full(heap* hp);
bool heap_is_empty(heap* hp);

int heap_parent(heap* hp, int node);
int heap_left_child(heap* hp, int node);
int heap_right_child(heap* hp, int node);
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
// Basic Heap operations
heap* heap_create(int size);
void heap_insert(heap* hp, HEAP_TYPE value);
////////////////////////////////////////////////////////////////////////////////////////



int heap_parent(heap* hp, int node)
{
    if(node > hp->heap_size || node < 0)
        return -1;
    return (node-2)/2;
}

int heap_left_child(heap* hp, int node)
{
    if(node > hp->heap_size || node < 0)
        return -1;
    return (node-1)*2;
}

int heap_right_child(heap* hp, int node)
{
    if(node > hp->heap_size || node < 0)
        return -1;
    return 2*(node-1) + 1;
}

bool heap_is_full(heap* hp) { return (hp->heap_size >= hp->arr_size); }
bool heap_is_empty(heap* hp) { return (hp->heap_size == 0); }

heap* heap_create(int size)
{
    heap* new_heap = (heap*)malloc(sizeof(heap));
    new_heap->heap_size = 0;
    new_heap->arr_size = size;
    new_heap->heap_arr = (HEAP_TYPE*)malloc(sizeof(HEAP_TYPE) * size);

    return new_heap;
}



void heap_insert(heap* hp, HEAP_TYPE value)
{
    if(heap_is_full(hp))
        return;
    hp->heap_arr[hp->heap_size++] = value;
    // swaping
    int k = hp->heap_size;
    while(k >= 1 && hp->heap_arr[k - 1] > hp->heap_arr[heap_parent(hp, k)])
    {
        swap(hp->heap_arr+(k - 1), hp->heap_arr + heap_parent(hp, k));
        k = heap_parent(hp, k);
    }
}

void heap_display(heap* hp)
{
    int level = 1;
    int leaves = (hp->heap_size/2 + 1);
    int tabs = leaves/2;

    int index_printed = 0;
    while(index_printed < hp->heap_size)
    {
        for(int j = 0; j <= tabs; j++) { printf("\t"); }
        tabs--;
        for(int j = 0; j < level; j++) { printf("%d\t", hp->heap_arr[index_printed++]); }
        printf("\n");
        level *= 2;
    }
}

#endif // heap_h