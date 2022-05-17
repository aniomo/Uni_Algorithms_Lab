#ifndef heap_h
#define heap_h

#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

#define HEAP_TYPE int
#define HEAP_NULL 0

// For the heap the index starts at 1, 
// so as a rule of thumb always subtract the index by 1 whenever you
// dereference the array at that index. ie( heap[i - 1] to get value at index i)

typedef struct heap
{
    int arr_size, heap_size;
    HEAP_TYPE* heap_arr;
}heap;

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// FUNCTIONS// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
heap* heap_build_max_heap(int* elements, int size);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //




// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// Utility Functions // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
int heap_parent(int i) { return (i/2); }
int heap_left(int i) { return (2*i); }
int heap_right(int i) { return (2*i + 1); }
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// MAX heap
// We assume the heap is already heapified elsewhere except the current index
void max_heapify(heap* A, int i)
{
    int left = heap_left(i);
    int right = heap_right(i);

    int largest = i;
    if(left <= A->heap_size && A->heap_arr[left - 1] > A->heap_arr[i - 1])
        largest = left;
    if(right <= A->heap_size && A->heap_arr[right - 1] > A->heap_arr[largest - 1])
        largest = right;
    if(largest != i)
    {
        swap(A->heap_arr+(i-1), A->heap_arr+(largest-1));
        max_heapify(A, largest);
    }
}

heap* heap_build_max_heap(int* elements, int size)
{
    heap* newHeap = (heap*)malloc(sizeof(heap));
    newHeap->arr_size = size;
    newHeap->heap_size = size;
    newHeap->heap_arr = copy_array(elements, size, newHeap->heap_arr, size);

    for(int i = size/2; i > 0; i--)
        max_heapify(newHeap, i);

    return newHeap;
}

#endif // heap_h