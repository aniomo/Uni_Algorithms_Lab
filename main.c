#include <stdio.h>

#include "utils.h"
#include "sorting.h"

int main()
{
    int size = 10;
    int array[] = {9, 2, 21, 60, 11, 8, 7, 67, 17, 89};

    int* sorted = heap_sort(&(array[0]), size);

    print_array(sorted, size);

    return 0;
}