#ifndef stack_h
#define stack_h

#include <stdlib.h>

typedef struct stack
{
	int top, capacity;
	int* array;
}stack;

stack* create_stack(int capacity);
void push(stack* stack, int item);
int pop(stack* stack);
int peek(stack* stack);
void free_stack(stack* stk);
int is_in(stack* stk, int key);

stack* create_stack(int capacity)
{
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->top = -1;
	newStack->capacity = capacity;
	newStack->array = (int*)malloc(sizeof(int) * capacity);
	return newStack;
}

void push(stack* stack, int item)
{
	if(stack == NULL || stack->top+1 == stack->capacity)
		return;
	stack->array[++(stack->top)] = item;
}

int pop(stack* stack)
{
	if(stack == NULL || stack->top == -1)
		return 0;
	return stack->array[stack->top--];
}

int peek(stack* stack)
{
	if(stack == NULL || stack->top == -1)
		return 0;
	return stack->array[stack->top];	
}

void free_stack(stack* stk)
{
	free(stk->array);
	free(stk);
}

int is_in(stack* stk, int key)
{
    for(int i = 0; i < stk->top+1; i++)
    {
        if(stk->array[i] == key)
            return i;
    }
    return -1;
}

#endif
