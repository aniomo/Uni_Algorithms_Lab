#ifndef ameth_array_h
#define ameth_array_h

#include <stdlib.h>

typedef struct am_array
{
    int size;
    int capacity;
    int* array;
}am_array;

am_array* am_create_array(int size);
int am_pop(am_array* array);
void am_append(am_array* array, int item);



am_array* am_create_array(int size)
{
    am_array* array = (am_array*)malloc(sizeof(am_array));
    array->size = 0;
    array->capacity = size;
    array->array = (int*)malloc(sizeof(int) * size);
    return array;
}

void am_append(am_array* array, int item)
{
    if(array == NULL)
        return;
    
    if(array->size == array->capacity)
    {
        int i;
        int* newArr = (int*)malloc(sizeof(int) * array->size * 2);
        for(i = 0; i < array->size; i++)
            newArr[i] = array->array[i];
        newArr[i++] = item;
        array->size = i;
        array->capacity *= 2;
        
        int* temp = array->array;
        array->array = newArr;
        free(temp);
    }
    else
        array->array[(array->size)++] = item;
}

int am_pop(am_array* array)
{
    if(array == NULL || array->size == 0)
        return 0;
    int item = array->array[--(array->size)];
    if(array->size < 0.25 * (array->capacity) && array->capacity * 0.25 >= 1)
    {
        int i;
        int* newArr = (int*)malloc(sizeof(int) * array->capacity * 0.25);
        for(i = 0; i < array->capacity * 0.25 - 1; i++)
            newArr[i] = array->array[i];
        array->size = i;
        array->capacity *= 0.25;
        
        int* temp = array->array;
        array->array = newArr;
        free(temp);
    }
    return item;
}

#endif /* ameth_array_h */
