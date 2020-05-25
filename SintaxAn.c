#include "SintaxAn.h"

void C(Stack * this)
{
	char tmp = Stack_Pop(this);
	if(tmp == 'c' || tmp == 'e' || tmp == 'r'){
		V(this,&tmp);
		B(this,&tmp);
		return;
	}
	else 
		printf("Error sintaxis 1.1 %c",tmp);
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
	else{
		printf("Error sintaxis 1.2 %c\n",*tmp);
		Stack_Print(this);}
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
			printf("Error Sintaxix 1.3 %c",*tmp);
		return;
	}
	else
		printf("Error Sintaxis 1.4 %c",*tmp);
}
void D(Stack * this, char *tmp)
{
	if(*tmp == 'c' || *tmp == 'e' || *tmp == 'r'){
		G(this,tmp);
		if(*tmp == 'a')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 2.1");
		if(*tmp == ';')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 2.2");
		return;
	}
	else
		printf("Error Sintaxis 2.3");
		
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
		printf("Error Sintaxis 2.3");
}
void A(Stack * this, char *tmp)
{
	if(*tmp == 'a'){
		*tmp = Stack_Pop(this);
		if(*tmp == '=')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 3.1\n");
		U(this,tmp);
		if(*tmp == ';')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 3.2\n");
		return;
	}
	else
		printf("Error Sintaxis 3.3\n");
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
		printf("Error Sintaxis 3.4\n");
}
void M(Stack * this, char *tmp)
{
	if(*tmp == 'm'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 4.1\n");
		R(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 4.2\n");
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else{
			printf("Error Sintaxis 4.3 %c\n",*tmp);
			Stack_Print(this);}
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 4.4\n");
		return;
	}
	else
		printf("Error Sintaxis 4.5\n");
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
		printf("Error Sintaxis 4.6 %c\n",*tmp);
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
		printf("Error Sintaxis 4.7\n");
}
void H(Stack * this, char *tmp)
{
	if(*tmp == 'p'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 5.1\n");
		N(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 5.2\n");
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 5.3\n");
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 5.4\n");
		return;
	}
	else
		printf("Error Sintaxis 5.5\n");
}
void N(Stack * this, char *tmp)
{
	if(*tmp == 'b' || *tmp == 'a'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis 5.6\n\n");
}
void I(Stack * this, char *tmp)
{
	if(*tmp == 's'){
		*tmp = Stack_Pop(this);
		if(*tmp == '(')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 6.1\n");
		R(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 6.2\n");
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 6.3\n");
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 6.4\n");
		L(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis 6.5\n");
}
void L(Stack * this, char *tmp)
{
	if(*tmp == 'l'){
		*tmp = Stack_Pop(this);
		if(*tmp == '[')
			*tmp = Stack_Pop(this);
		else 
			printf("Error Sintaxis 6.6\n");
		S(this,tmp);
		if(*tmp == ']')
			*tmp = Stack_Pop(this);
		else{
			printf("Error Sintaxis 6.7\n");
			Stack_Print(this);}
		return;
	}
	else if(*tmp == 'm' || *tmp == 's' || *tmp == 'p' || *tmp == 'a' || *tmp == ']')
		return;
	else
		printf("Error Sintaxis 6.8\n");
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
		printf("Error Sintaxis 7.1\n");
}
void Q(Stack * this, char *tmp)
{
	if(*tmp == 'a' || *tmp == 'b' || *tmp == 'z' || *tmp == 'f'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis 7.2\n");
}
void J(Stack * this, char *tmp)
{
	if(*tmp == 'i' || *tmp == '!' || *tmp == '>' || *tmp == '<' || *tmp == 'y' || *tmp == 'n'){
		*tmp = Stack_Pop(this);
		return;
	}
	else{
		printf("Error Sintaxis 7.3\n");
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
		printf("Error Sintaxis 8.1 %c\n",*tmp);
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
		printf("Error Sintaxis 8.2\n");
}
void T(Stack * this, char *tmp)
{
	if(*tmp == '(' || *tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis 8.3\n");
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
		printf("Error Sintaxis 8.4\n");
}
void F(Stack * this, char *tmp)
{
	if(*tmp == '('){
		*tmp = Stack_Pop(this);
		E(this,tmp);
		if(*tmp == ')')
			*tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis 8.5\n");
		return;
	}
	else if(*tmp == 'a' || *tmp == 'b' || *tmp == 'z'){
		*tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis 8.6\n");
}
		
