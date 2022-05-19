#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "heap.h"


int main()
{
    int arr[] = {4, 5, 2, 9};

    heap* hp = heap_build_max_heap(&(arr[0]), 4);

    print_array(hp->heap_arr, 4);

    return 0;
}