#ifndef str_match_h
#define str_match_h

#include "utils.h"
#include "c_str.h"


// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// FUNCTIONS// // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
int str_horsepool(string* text, string* pattern);
// // // // // // // // // // // // // // // // // // // // // // // // // // // //
// // // // // // // // // // // // // // // // // // // // // // // // // // // //


int str_shift_table(string* pattern, char c)
{
    int k = 0;
    for(int i = pattern->size - 1; i >= 0 ; i--)
    {
        if(pattern->str[i] == c)
            break;
        k++;
    }
    if(k == 0)
    {
        for(int i = pattern->size-2; i >= 0; i--)
            if(pattern->str[i] == c)
                return pattern->size - 1 - i;
    }
    return k;
}

int str_horsepool(string* text, string* pattern)
{
    int i = pattern->size-1;
    while(i < text->size)
    {
        int k = 0;
        while(k < pattern->size && text->str[i - k] == pattern->str[pattern->size - 1 - k])
        { k++; }
            
        if(k == pattern->size)
            return i - k + 1;
        i += str_shift_table(pattern, text->str[i]);
    }
    return -1;
}



#endif // str_match_h