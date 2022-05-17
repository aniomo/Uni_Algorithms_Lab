#ifndef c_str_h
#define c_str_h

#include <stdlib.h>

// Size of the char array will be size + 1 because of the '\0' termination character.
typedef struct string
{
    int size;
    char* str;
} string;

string* str_create(char* text)
{
    string* newString = (string*)malloc(sizeof(string));
    int i = 0;
    while(text[i] != '\0') i++;
    newString->size = i;
    newString->str = (char*)malloc(sizeof(char) * (i+1));
    for(int j = 0; j < i; j++)
        newString->str[j] = text[j];
    newString->str[i] = '\0';
    
    return newString;
}

#endif // c_str_h