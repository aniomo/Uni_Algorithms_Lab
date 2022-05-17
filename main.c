#include <stdio.h>

#include "utils.h"
#include "str_match.h"

int main()
{
    string* pattern = str_create("alaska");
    string* text = str_create("tabalaska");

    int found = str_horsepool(text, pattern);

    printf("%d\n", found);

    return 0;
}