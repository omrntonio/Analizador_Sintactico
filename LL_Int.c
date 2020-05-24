#include "LL_Int.h"
#include "Nodo.h"

/*
Crea la lista ligada vacia y devuelve una apuntador de tipo LL
o lista ligada
*/
LL* LL_Create()
{
	LL * n = (LL *) malloc (sizeof(LL));
	if(n){
		n->first = NULL;
		n->last = NULL;
	}
	return n;
}

/*
Libera la memoria de una lista ligada
*/
void LL_Destroy (LL * this)
{
	if (this == NULL){
		while(this->first != NULL){
		//elimina cada nodo de la lista
			Nodo * tmp = this->first->next;
			free(this->first);
			this->first = tmp;
		}
		free(this);
		//libera la memoria de la lista
	}
}

/*
Revisa si esta vacia la lista y devuelve falso o verdadero
dependiendo si esta vacia o no
*/
Bool LL_IsEmpty (LL * this)
{
	if (this == NULL) { return TRUE; }
	if(this->first == NULL) { return TRUE; }
	else return FALSE;
}

/*
Revisa si existe un valor predeterminado en la lista si lo
encuentra devuelve verdadero de lo contrario falso
*/
Bool LL_FindIf (LL * this, int val1, float val2, char * cad)
{
	if (this == NULL) { return FALSE; }
	if (LL_IsEmpty(this)) { return FALSE; }
	Nodo * tmp = this->first;
    	//se guarda la direccion del primer nodo
	while(this->first != NULL){
        //se busca en toda la lista el dato que 
        //coincida
        if(cad == NULL){
        	if(this->first->info.entero == val1 || this->first->info.decimal == val2){
				this->first = tmp;
				return TRUE;
        	}
			else {
				this->first = this->first->next;
			}
        }
        else{
			if(strcmp(this->first->info.cadena,cad)==0){
				this->first = tmp;
				return TRUE;
        	}
			else {
				this->first = this->first->next;
			}
		}
	}
	this->first = tmp;
	return FALSE;
}

/*
Busca en la lista ligada un nodo que contenga la informacion buscada
en caso de que lo encuentre devuelve un apuntador a ese nodo
*/
Nodo * LL_Search (LL * this, int val1, float val2, char * cad)
{
	if (this == NULL) { return NULL; }
	if (LL_IsEmpty(this)) { return NULL; }
	Nodo * tmp = this->first;
    //se guarda la direccion del primer nodo
	while(this->first != NULL){
        //devuelve el nodo que coincida con el dato
        if (cad == NULL){
        	if(this->first->info.entero == val1 || this->first->info.decimal == val2){
				Nodo * res = this->first;
				this->first = tmp;
				return res;
        	}
			else {
				this->first = this->first->next;
			}
        }else{
			if(strcmp(this->first->info.cadena,cad)==0){
				Nodo * res = this->first;
				this->first = tmp;
				return res;
        	}
			else {
				this->first = this->first->next;
			}
		}
	}
	this->first = tmp;
	return NULL;
}

/*
Se inserta un nodo nuevo en la lista ligada donde la informarcion del nodo
puede ser de tres tipos entera, real o una cadena pero solo puede ser una
a la vez, entonces si se quiere insertar un valor entero se tiene que enviar
un cero a los otros dos parametros(NULL en el caso de la cadena), de igual 
manera con el dato real y la cadena. Devuelve un dato booleano especificando
si se pudo insertar o no.
*/
Bool LL_Insert (LL * this, int pos, int val1, float val2, char * cad)
{
	Nodo * n;
	if (this == NULL) { return FALSE; }
	if ((val1 == 0 && val2 != 0) || (val1 != 0 && val2 == 0) || (cad != NULL && val1 == 0 && val2 == 0))
		{n = newNodo(pos,val1,val2,cad);}
	if(!n) { return FALSE; }
	//Si el nodo no se pudo crear devuelve FALSE
	
	//Para insertar en la lista cuando no esta vacia
	if( this->first != NULL) {
		this->last->next = n;
		//no es necesario n->next = NULL
		//cuando se crea se inicializa
		this->last = n;
	}
	//Cuando la lista esta vacia
	else {
		this->first = n;
		this->last = n;
	}
	return TRUE;
}


/*
Muestra el valor de cada nodo en una lista ligada, se tiene que especificar 
que tipo de valor se quiere mostrar ya que el nodo tres tipos de informacion
pero solo uno de ellos es valido.
*/
void LL_Print(LL * this, int tipo)
{
	if(!this) { printf("Apuntador invalido de lista ligada\n"); return;}
	Nodo * tmp = this-> first;
	if(!tmp) {printf("La lista esta vacia\n"); return;}
	do{
		if(tipo == 1) {printf("(%i,%i)\n",tmp->posicion,tmp->info.entero);}
		else if(tipo == 2){printf("(%i,%f)\n",tmp->posicion,tmp->info.decimal);}
		else if(tipo == 3){printf("(%i,%s)\n",tmp->posicion,tmp->info.cadena);}
		else{
			printf("Tipo de dato invalido\n");
			break;
		}
		if(tmp->next != NULL)
                    tmp = tmp->next;
	}while (tmp != this->last);
}



