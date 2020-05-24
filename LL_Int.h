#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL

enum {FALSE = 0, TRUE = !0};
typedef unsigned int Bool;

#endif
#include "Nodo.h"

#ifndef LISTA_ENLAZADA_SIMPLE
#define LISTA_ENLAZADA_SIMPLE

struct LinkedList_Type
{
	Nodo * first;
	//apuntador al primer nodo
	Nodo * last;
	//apuntador al ultimo nodo
};
typedef struct LinkedList_Type LL;

LL* LL_Create();

void LL_Destroy (LL * this);

Bool LL_IsEmpty (LL * this);

Bool LL_FindIf (LL * this, int val1, float val2, char * cad);

Nodo * LL_Search (LL * this, int val1, float val2, char * cad);

Bool LL_Insert (LL * this, int pos, int val1, float val2, char * cad);

void LL_Print(LL * this, int tipo);

#endif


