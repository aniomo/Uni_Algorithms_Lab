#ifndef hash_h
#define hash_h

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define HASH_TYPE int

// Open Addressing
struct Hashtable
{
    int n_elements;
    int capacity;

    bool* occupied;
    HASH_TYPE* table;

    int (*hash_function)(HASH_TYPE, int);
    int (*collision_resolution)(int, int, int);

};
typedef struct Hashtable Hashtable;



// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
Hashtable* create_open_hash(HASH_TYPE* array, int size, 
    int (*hash_func)(HASH_TYPE, int), int (*collision)(int, int, int));

int search_open_hash(Hashtable* hash, HASH_TYPE element);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //




// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
Hashtable* create_open_hash(HASH_TYPE* array, int size, 
    int (*hash_func)(HASH_TYPE, int), int (*collision)(int, int, int))
{
    //Recommended Load-Factor in percentage
    float load_factor = 70.0f; 

    Hashtable* newHash  = (Hashtable*)malloc(sizeof(Hashtable));

    newHash->n_elements = size;
    newHash->capacity   = size * (int)((100.0f + load_factor)/100.0f);

    newHash->hash_function        = hash_func;
    newHash->collision_resolution = collision;

    newHash->table    = (HASH_TYPE*)malloc(sizeof(HASH_TYPE) * newHash->capacity);
    newHash->occupied = (bool*)malloc(sizeof(bool) * newHash->capacity);

    for(int i = 0; i < newHash->capacity; i++) 
    { newHash->occupied[i] = false; }

    int hashindex;

    for(int i = 0; i < size; i++)
    {
        hashindex = newHash->hash_function(array[i], newHash->capacity);
        
        int attempts = 0;

        while(newHash->occupied[hashindex] != false)
        {
            if(attempts >= newHash->capacity)
            {
                printf("Hash Table Error: Cannot create hashtable because the hash function provided cannot compute a valid index.\n");
                return NULL;
            }
            hashindex %= newHash->capacity;
            hashindex = newHash->collision_resolution(hashindex, newHash->capacity, attempts++); 
        }

        newHash->table[hashindex] = array[i];
        newHash->occupied[hashindex] = true;
    }

    return newHash;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
int search_open_hash(Hashtable* hash, HASH_TYPE element)
{
    int hashindex = hash->hash_function(element, hash->capacity);
    if(hash->table[hashindex] == element)
        return hashindex;


    int attempts = 0;
    while(hash->table[hashindex] != element)
    { 
        if(attempts >= hash->capacity)
        { return -1; }

        hashindex %= hash->capacity;
        hashindex  = hash->collision_resolution(hashindex, hash->capacity, attempts++); 
    }
    return hashindex;
}

#endif //hash_h