#include "Nodo.h"

Nodo * newNodo (int pos, int val1, float val2, char * cad)
{
	Nodo * n = (Nodo *) malloc (sizeof(Nodo));
	if(n){
		n->posicion = pos;
		n->tipo = -1;
		if(val1 != 0 && val2 == 0){
			n->info.entero = val1;	
			n->next = NULL;
		}
		else if(val1 == 0 && val2 != 0){
			n->info.decimal = val2;
			n->next = NULL;
		}
		else if(cad != NULL && val1 == 0 && val2 == 0){
			strcpy(n->info.cadena, cad);
			n->next = NULL;
		}
	}
	return n;
}

void deleteNodo (Nodo * n)
{
	if(n){ free(n); }
}
