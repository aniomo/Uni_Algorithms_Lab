#ifndef utils_h
#define utils_h

// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// MACROS// // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
#define bool  int
#define true  1
#define false 0
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// FUNCTIONS// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
void swap(int* a, int* b);
void reverse_array(int* array, int size);
int* sub_array(int* array, int start, int end);
int max(int a, int b);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //



void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int* array, int size)
{
    for(int i = 0; i <= (size/2)-1; i++)
        swap(array+i, array+(size-1-i));
}

int* sub_array(int* array, int start, int end)
{
    int* subarr = (int*)malloc(end-start+1);
    for(int i = start; i <= end; i++)
        subarr[i - start] = array[i];
    return subarr;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

#endif //utils_h
