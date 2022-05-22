#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "hash.h"

int hash_func(int element, int size)
{
    return element % size;
}

int collision(int hashindex, int size , int attempts)
{
    return (hashindex+1) % size;
}

int main()
{
    int arr[] = {4, 5, 2, 9, 1};

    Hashtable* hash = create_open_hash(&arr[0], 5, hash_func, collision);    

    print_array(hash->table, hash->capacity);

    int element = 4;
    printf("%d is found at index %d\n", element, search_open_hash(hash, element));

    return 0;
}