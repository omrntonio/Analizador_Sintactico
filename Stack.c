#include "Stack.h"

//Crea la pila vacía y devuelve una apuntador de tipo Stack
Stack *stack_Create()
{
	Stack *stack = (Stack *) malloc(sizeof *stack);
	if(stack == NULL)
		return NULL;
	
	stack->count = 0;
	stack->top = NULL;
	
	return stack;
}

//Libera memoria de la pila
void stack_Destroy(Stack *stack)
{
	while(!stack_Is_Empty(stack))
		stack_Pop(stack);
	   
	free(stack);
}
//Revisa si la pila está vacía
bool stack_Is_Empty(Stack *stack)
{
	if(stack->top == NULL)
	   return true;
	else
	   return false;
}
//Devuelve el tamaño de la pila
size_t stack_Size(Stack *stack)
{
	return stack->count;
}
//Devuelve el dato del elemento que está en el tope de la pila
StackItem stack_Top(Stack *stack)
{
	return stack->top->nodo;
}
/*Inserta un nuevo elemento en la pila y devuelve
verdadero si pudo insertar el elemento
*/
bool stack_Push(Stack *stack, StackItem nodo)
{
	StackNodo *newNodo = (StackNodo *) malloc(sizeof *newNodo);
	if(newNodo == NULL)
		return false;
	
	newNodo->nodo = nodo;
	newNodo->next = stack->top;
	stack->top = newNode;
	
	stack->count += 1;
	return true;
}
//Devuelve el último dato de la pila
StackItem stack_Pop(Stack *stack)
{
	Nodo *this;
	StackItem nodo;
	
	if(stack->top == NULL)
		return 0; 

	this = stack->top;
	nodo = this->nodo;
	stack->top = this->below;
	free(this);
	this = NULL;
	
	stack->count -= 1;
	return nodo;
}