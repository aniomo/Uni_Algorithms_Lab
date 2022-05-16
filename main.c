#include <stdio.h>

#include "utils.h"
#include "heap.h"

int main()
{
    heap* nums = heap_create(7);
    heap_insert(nums, 1);
    heap_insert(nums, 6);
    heap_insert(nums, 3);
    heap_insert(nums, 4);
    heap_insert(nums, 5);
    heap_insert(nums, 9);
    heap_insert(nums, 7);
    heap_display(nums);
    
    return 0;
}