#include "SintaxAn.h"

void C(Stack * this)
{
	char tmp = Stack_Pop(this);
	if(tmp == 'c' || tmp == 'e' || tmp == 'r' || tmp == '['){
		V(this,&tmp);
		B(this,&tmp);
		return;
	}
	else 
		printf("\nError de Sintaxis se esperaba declaracion de variable o '[' pero se encontro %s\n",tipoAtomo(tmp));
}
void V(Stack * this, char *tmp)
{
	if(*tmp == 'c' || *tmp == 'e' || *tmp == 'r'){
		D(this,tmp);
		V(this,tmp);
		return;
	}
	else if(*tmp == '[')
		return;
	else
		printf("\nError Sintaxis se esperaba declaracion de variable o '[' pero se encontro %s\n",tipoAtomo(*tmp));
}
void B(Stack * this, char *tmp)
{
	if(*tmp == '['){
		*tmp = Stack_Pop(this);
		P(this,tmp);
		S(this,tmp);	
		if(*tmp == ']')
			return;
		else
			printf("\nError Sintaxis se esperaba ']' pero se encontro %s\n",tipoAtomo(*tmp));
		return;
	}
	else
		printf("\nError Sintaxis se esperaba '[' o ']' pero se encontro %s\n",tipoAtomo(*tmp));
}
void D(Stack * this, char *tmp)
{
	if(*tmp == 'c' || *tmp == 'e' || *tmp == 'r'){
		G(this,tmp);
		if(*tmp == 'a')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba un identificador pero se encontro %s\n", tipoAtomo(*tmp));
		if(*tmp == ';')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ';' pero se encontro %s\n", tipoAtomo(*tmp));
		return;
	}
	else
		printf("\nError Sintaxis se esperaba declaracion de variable o identificador o ';' pero se encontró  %s\n", tipoAtomo(*tmp));
		
}
void G(Stack * this, char *tmp)
{
	if(*tmp == 'c'){
		*tmp = Stack_Pop(this);
		return;
	}
	else if(*tmp == 'e'){
		*tmp = Stack_Pop(this);
		return;
	}
	else if(*tmp == 'r'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba declaracion de variable pero se encontro %s\n", tipoAtomo(*tmp));
}
void A(Stack * this, char *tmp)
{
	if(*tmp == 'a'){
		*tmp = Stack_Pop(this);
		if(*tmp == '=')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '=' pero se encontro %s\n",tipoAtomo(*tmp));
		U(this,tmp);
		if(*tmp == ';')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ';' pero se encontro %s\n",tipoAtomo(*tmp));
		return;
	}
	else
		printf("\nError Sintaxis se esperaba identificador pero se encontro %s\n", tipoAtomo(*tmp));
}
void U(Stack * this, char *tmp)
{
	if(*tmp == '(' || *tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		E(this,tmp);
		return;
	}
	else if(*tmp == 'f'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba expresión relacional pero se encontro %s\n", tipoAtomo(*tmp));
}
void M(Stack * this, char *tmp)
{
	if(*tmp == 'm'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '(' pero se encontro %s \n", tipoAtomo(*tmp));
		R(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ')' pero se encontro %s \n", tipoAtomo(*tmp));
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else{
			printf("\nError Sintaxis se esperaba '[' pero se encontro %s\n",*tipoAtomo(*tmp));
			Stack_Print(this);}
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ']' pero es econtro %s \n", tipoAtomo(*tmp));
		return;
	}
	else
		printf("\nError Sintaxis se esperaba palabra reservada pero es encontro %s \n", tipoAtomo(*tmp));
}
void S(Stack * this, char *tmp)
{
	if(*tmp == 'm' || *tmp == 's' || *tmp == 'p' || *tmp == 'a'){
		P(this,tmp);
		S(this,tmp);
		return;
	}
	else if(*tmp == ']')
		return;
	else{
		printf("\nError Sintaxis se esperaba ']' pero se encontro %s\n",tipoAtomo(*tmp));
		Stack_Print(this);}
}
void P(Stack * this, char *tmp)
{
	if(*tmp == 'm'){
		M(this,tmp);
		return;
	}
	else if(*tmp == 's'){
		I(this,tmp);
		return;
	}
	else if(*tmp == 'p'){
		H(this,tmp);
		return;
	}
	else if(*tmp == 'a'){
		A(this,tmp);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba identificador pero se encontro %s\n", tipoAtomo(*tmp));
}
void H(Stack * this, char *tmp)
{
	if(*tmp == 'p'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '(' pero se encontro %s\n", tipoAtomo(*tmp));
		N(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ')' pero se encontro %s\n", tipoAtomo(*tmp));
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '[' pero se encontro %s \n", tipoAtomo(*tmp));
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ']' pero se encontro %s  \n", tipoAtomo(*tmp));
		return;
	}
	else
		printf("\nError Sintaxis se esperaba palabra reservada pero se encontro %s\n", tipoAtomo(*tmp));
}
void N(Stack * this, char *tmp)
{
	if(*tmp == 'b' || *tmp == 'a'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba identificador o constante numerica pero se encontro %s \n\n", tipoAtomo(*tmp));
}
void I(Stack * this, char *tmp)
{
	if(*tmp == 's'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '(' pero se encontro %s \n", tipoAtomo(*tmp));
		R(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ')' pero se encontro %s \n", tipoAtomo(*tmp));
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba '[' pero se ecnontro %s \n", tipoAtomo(*tmp));
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ']' pero se encontro %s \n", tipoAtomo(*tmp));
		L(this,tmp);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba palabra reservada pero se encontro %s\n", tipoAtomo(*tmp));
}
void L(Stack * this, char *tmp)
{
	if(*tmp == 'l'){
		*tmp = Stack_Pop(this);
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else 
			printf("\nError Sintaxis se esperaba '[' pero se encontro %s \n", tipoAtomo(*tmp));
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else{
			printf("\nError Sintaxis se esperaba ']' pero se encontro %s \n", tipoAtomo(*tmp));
			Stack_Print(this);}
		return;
	}
	else if(*tmp == 'm' || *tmp == 's' || *tmp == 'p' || *tmp == 'a' || *tmp == ']')
		return;
	else
		printf("\nError Sintaxis se esperaba palabra reservada o identificador o ']' pero se encontro % s\n", tipoAtomo(*tmp));
}
void R(Stack * this, char *tmp)
{
	if(*tmp == 'a' || *tmp == 'b' || *tmp == 'z' || *tmp == 'f'){
		Q(this,tmp);
		J(this,tmp);
		Q(this,tmp);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba identificador o constante numerica pero se encontro %s\n", tipoAtomo(*tmp));
}
void Q(Stack * this, char *tmp)
{
	if(*tmp == 'a' || *tmp == 'b' || *tmp == 'z' || *tmp == 'f'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba identificador, constante numerica entera, real o caracter pero se encontro %s\n", tipoAtomo(*tmp));
}
void J(Stack * this, char *tmp)
{
	if(*tmp == 'i' || *tmp == '!' || *tmp == '>' || *tmp == '<' || *tmp == 'y' || *tmp == 'n'){
		*tmp = Stack_Pop(this);
		return;
	}
	else{
		printf("\nError Sintaxis se esperaba operador relacional pero se encontro %s\n", tipoAtomo(*tmp));
		Stack_Print(this);}
}
void E(Stack * this, char *tmp)
{
	if(*tmp == '(' || *tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else{
		printf("\nError Sintaxis se esperaba '(' o identificador o constante numerica pero se encontro %s\n",tipoAtomo(*tmp));
		Stack_Print(this);}
}
void EP(Stack * this, char *tmp)
{
	if(*tmp == '+'){
		*tmp = Stack_Pop(this);
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else if(*tmp == '-'){
		*tmp = Stack_Pop(this);
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else if(*tmp == ')' || *tmp == ';')
		return;
	else
		printf("\nError Sintaxis se esperaba ')' pero se encontro ';' pero se encontro %s\n", tipoAtomo(*tmp));
}
void T(Stack * this, char *tmp)
{
	if(*tmp == '(' || *tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba '(' o identificador o constante numerica pero se encontro %s\n", tipoAtomo(*tmp));
}
void TP(Stack * this, char *tmp)
{
	if(*tmp == 'x'){
		*tmp = Stack_Pop(this);
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else if(*tmp == '/'){
		*tmp = Stack_Pop(this);
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else if(*tmp == '+' || *tmp == '-' || *tmp == ')' || *tmp == ';')
		return;
	else
		printf("\nError Sintaxis se esperaba operador aritmetico o ')' o ';' pero se encontro %s\n", tipoAtomo(*tmp));
}
void F(Stack * this, char *tmp)
{
	if(*tmp == '('){
		*tmp = Stack_Pop(this);
		E(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("\nError Sintaxis se esperaba ')' pero se encontro %s \n", tipoAtomo(*tmp));
		return;
	}
	else if(*tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("\nError Sintaxis se esperaba un identificador o una constante numerica pero se encontro %s \n", tipoAtomo(*tmp));
}
char * tipoAtomo(char tmp)
{
	switch(tmp)
	{
	case 'a':
		return "Identificador";
	break;
	case ';':
		return "Caracter Especial: ';'";
	break;
	case '(':
		return "Caracter Especial: '('";
	break;
	case ')':
		return "Caracter Especial: ')'";
	break;
	case '[':
		return "Caracter Especial: '['";
	break;
	case ']':
		return "Caracter Especial: ']'";
	break;
	case 'b':
		return "Constante Numerica Entera";
	break;
	case 'z':
		return "Constante Numerica Real";
	break;
	case 'f':
		return "Constante Caracter";
	break;
	case '+':
		return "Operador Aritmetico: '+'";
	break;
	case '-':
		return "Operador Aritmetico: '-'";
	break;
	case 'x':
		return "Operador Aritmetico: 'x'";
	break;
	case '/':
		return "Operador aritmetico: '/'";
	break;
	case '=':
		return "Operador de Asignacion: '='";
	break;
	case 'i':
		return "Operador Relacional: .IG.";
	break;
	case '!':
		return "Operador Relacional: .DI.";
	break;
	case '>':
		return "Operador Relacional: .MY.";
	break;
	case '<':
		return "Operador Relacional: .MN.";
	break;
	case 'y':
		return "Operador Relacional: .MYI.";
	break;
	case 'n':
		return "Operador Relacional: .MNI.";
	break;
	case 'c':
		return "Palabra Reservada: carac";
	break;
	case 'e':
		return "Palabra Reservada: ent";
	break;
	case 'm':
		return "Palabra Reservada: mientras";
	break;
	case 'p':
		return "Palabra Reservada: para";
	break;
	case 'r':
		return "Palabra Reservada: real";
	break;
	case 's':
		return "Palabra Reservada: si";
	break;
	case 'l':
		return "Palabra Reservada: sino";
	break;
	default:
		return "Palabra no reconocida";
	break;
	}
}
		
