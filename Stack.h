#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

#endif
#define StackItem char
//#include "Nodo.h"

# ifndef  _STACK_H_INCLUDED
# define  _STACK_H_INCLUDED

struct StackNodo 
{
	StackItem nodo;				
    //Datos del nodo
	struct StackNodo *below;		
    //Apuntador al nodo debajo del que se encuentra en el tope
};
typedef struct StackNodo Nodo;

//Define la estructura de la pila
struct Stack_Type
{
	Nodo *top;
    size_t count; 		
};
typedef struct Stack_Type Stack;

Stack *stack_Create();
void stack_Destroy(Stack *stack);
Bool stack_Is_Empty(Stack *stack);
size_t stack_Size(Stack *stack);
StackItem stack_Top(Stack *stack);
Bool stack_Push(Stack *stack, StackItem item);
StackItem stack_Pop(Stack *stack);

#endif