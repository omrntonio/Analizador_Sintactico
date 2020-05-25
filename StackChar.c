#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "StackChar.h"

void Stack_Peek (const Stack *this)
{
	int copia = this->top;
	if (copia == 0){
		printf("La pila esta vacia\n");
	}
	else{
		--copia;
		printf("%i",(this->stack[copia]));
	}
}
void Stack_Push (Stack * this, char newVal)
{
	if (this->top >= this->max) { assert (0); }
	this->stack[this->top] = newVal;
	++this->top;
}
char Stack_Pop (Stack * this)
{
	if (this->top == 0) { assert (0); }
	--this->top;
	return this->stack[this->top];
}
Bool Stack_IsEmpty (Stack * this)
{
	return (this->top == 0);
}
Bool Stack_IsFull (Stack * this)
{
	return (this->top >= this->max);
}
void Stack_Print(const Stack *this)
{
	for (int i =this->top-1; i>-1;i--){
		printf("%c",this->stack[i]);
	}
	printf("\n");
}
Stack * Stack_Ctor (int max)
{
	Stack * newStack = (Stack *) malloc (sizeof (Stack));
	// crea a un nuevo objeto Stack en el heap
	assert (newStack);
	newStack->stack = (char *) malloc (max * sizeof (char));
	// crea a un nuevo contenedor (el arreglo) de char's en el heap
	assert (newStack->stack);
	newStack->top = 0;
	newStack->max = max;
	return newStack;
}
void Stack_Dtor (Stack * this)
{
	assert (this);
	free (this->stack);
	// devuelve la memoria del arreglo
	free (this);
	// devuelve la memoria del objeto
}
