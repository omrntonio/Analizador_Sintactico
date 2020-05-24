#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

#endif
#define StackItem char
#include "Nodo.h"

# ifndef  _STACK_H_INCLUDED
# define  _STACK_H_INCLUDED

struct Stack_Type
{
	Nodo * first;
	//apuntador al primer nodo
	Nodo * last;
	//apuntador al ultimo nodo
};
typedef struct Stack_Type Stack;

Stack *stackCreate();
void stack_Destroy(Stack *stack);
Bool stack_Is_Empty(Stack *stack);
StackItem stackTop(Stack *stack);
Bool stackPush(Stack *stack, StackItem item);
StackItem stackPop(Stack *stack);

#endif