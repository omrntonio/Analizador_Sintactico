#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NODO_ENTERO
#define NODO_ENTERO

union Dato{
	int entero;
	float decimal;
	char cadena[50];
};

struct Nodo_Type
{
	int posicion;
	int tipo;
	union Dato info;
	// la informacion que contiene el nodo
	struct Nodo_Type * next;
	//apuntador al siguiente nodo
};
typedef struct Nodo_Type Nodo;

Nodo * newNodo (int pos, int val1, float val2, char * cad);

void deleteNodo (Nodo * n);

#endif
