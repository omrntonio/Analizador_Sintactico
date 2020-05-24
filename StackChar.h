#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


#ifndef BOOL
#define BOOL

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

#endif

#ifndef PILA_CHAR
#define PILA_CHAR

struct Stack_Type
{
	char * stack;
	int top;
	int max;
};
	typedef struct Stack_Type Stack;

void Stack_Peek (const Stack *this);

void Stack_Push (Stack * this, char newVal);

char Stack_Pop (Stack * this);

Bool Stack_IsEmpty (Stack * this);

Bool Stack_IsFull (Stack * this);

void Stack_Print(const Stack *this);

Stack * Stack_Ctor (int max);

void Stack_Dtor (Stack * this);

#endif //Fin de la definicion Pila
