#ifndef dy_array_h
#define dy_array_h

#include <stdlib.h>

#include "utils.h"

typedef struct pairs
{
	int a, b;
}pairs;

#define M_TYPE int
#define M_TYPE_DEFAULT -1

typedef struct dy_array
{
	int size, capacity;
	M_TYPE* array;
}dy_array;



// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
dy_array* dy_create_array(int size);
void dy_append(dy_array* arr, M_TYPE item);
M_TYPE dy_pop(dy_array* arr);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //



dy_array* dy_create_array(int size)
{
	dy_array* newarr = (dy_array*)malloc(sizeof(dy_array));
	newarr->array = (M_TYPE*)malloc(sizeof(M_TYPE) * size);
	newarr->capacity = size;
	newarr->size = 0;
	return newarr;
}

void dy_append(dy_array* arr, M_TYPE item)
{
	if(arr == NULL)
		return;
	if(arr->size == arr->capacity)
	{
		M_TYPE* newarr = (M_TYPE*)malloc(sizeof(M_TYPE) * arr->capacity * 2);
		
		for(int i = 0; i < arr->size; i++)
			newarr[i] = arr->array[i];

		arr->capacity *= 2;
		newarr[arr->size++] = item;
		
		M_TYPE* temp = arr->array;
		arr->array = newarr;
		free(temp);
	}
	else
	{
		arr->array[arr->size++] =  item;
	}
}

M_TYPE dy_pop(dy_array* arr)
{
	if(arr == NULL || arr->size == 0)
		return M_TYPE_DEFAULT;
	
	M_TYPE item;
	if(arr->size < arr->capacity * 0.25 && arr->capacity * 0.25 >= 1)
	{
		M_TYPE* newarr = (M_TYPE*)malloc(sizeof(M_TYPE) * arr->capacity * 0.25);
		
		for(int i = 0; i < arr->size; i++)
			newarr[i] = arr->array[i];

		arr->capacity *= 0.25;
		item = newarr[--(arr->size)];
		
		M_TYPE* temp = arr->array;
		arr->array = newarr;
		free(temp);
	}
	else
	{
		item = arr->array[--(arr->size)];
	}
	return item;
}

#endif //dy_array_h
