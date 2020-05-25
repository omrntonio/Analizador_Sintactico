#include "SintaxAn.h"

void C(Stack * this)
{
	char tmp = Stack_Pop(this);
	if(tmp == 'c' || tmp == 'e' || tmp == 'r'){
		V(this,tmp);
		B(this,tmp);
		return;
	}
	else 
		printf("Error sintaxis");
	return;
}
void V(Stack * this, char tmp)
{
	if(tmp == 'c' || tmp == 'e' || tmp 'r'){
		D(this,tmp);
		V(this,tmp);
		return;
	}
	else if(tmp == ']'){
		return;
}
void B(Stack * this, char tmp)
{
	if(tmp == '['){
		tmp = Stack_Pop(this);
		P(this,tmp);
		S(this,tmp);
		if(tmp == ']')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxix");
		return;
	}
	else
		printf("Error Sintaxis");
}
void D(Stack * this, char tmp)
{
	if(tmp == 'c' || tmp == 'e' || tmp == 'r'){
		G(this,tmp);
		if(tmp == 'a')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		return;
	}
	else
		printf("Error Sintaxis");
		
}
void G(Stack * this, char tmp)
{
	if(tmp == 'c'){
		tmp = Stack_Pop(this);
		return;
	}
	else if(tmp == 'e'){
		tmp = Stack_Pop(this);
		return;
	}
	else if(tmp == 'r'){
		tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis");
}
void A(Stack * this, char tmp)
{
	if(tmp == 'a'){
		tmp = Stack_Pop(this);
		if(tmp == '=')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		U(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void U(Stack * this, char tmp)
{
	if(tmp == '(' || tmp == 'a' || tmp == 'b' || tmp == 'z'){
		E(this,tmp);
		return;
	}
	else if(tmp == 'f'){
		tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis");
}
void M(Stack * this, char tmp)
{
	if(tmp == 'm'){
		tmp = Stack_Pop(this);
		if(tmp == '(')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		R(this,tmp);
		if(tmp == ')')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		if(tmp == ']'){
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		S(this,tmp);
		if(tmp == ']')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		return;
	}
	else
		printf("Error Sintaxis");
}
void S(Stack * this, char tmp)
{
	if(tmp == 'm' || tmp == 's' || tmp == 'p' || tmp == 'a'){
		P(this,tmp);
		S(this,tmp);
		return;
	}
	else if(tmp == ']')
		return;
	else
		printf("Error Sintaxis");
}
void P(Stack * this, char tmp)
{
	if(tmp == 'm'){
		M(this,tmp);
		return;
	}
	else if(tmp == 's'){
		I(this,tmp);
		return;
	}
	else if(tmp == 'p'){
		H(this,tmp);
		return;
	}
	else if(tmp == 'a'){
		A(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void H(Stack * this, char tmp)
{
	if(tmp == 'p'){
		tmp = Stack_Pop(this);
		if(tmp == '(')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		N(this,tmp);
		if(tmp == ')')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		if(tmp == '[')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		S(this,tmp);
		if(tmp == ']')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		return;
	}
	else
		printf("Error Sintaxis");
}
void N(Stack * this, char tmp)
{
	if(tmp == 'b' || tmp == 'a'){
		tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis");
}
void I(Stack * this, char tmp)
{
	if(tmp == 's'){
		tmp = Stack_Pop(this);
		if(tmp == '(')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		R(this,tmp);
		if(tmp == ')')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		if(tmp == '[')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		S(this,tmp);
		if(tmp == ']')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		L(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void L(Stack * this, char tmp)
{
	if(tmp == 'l'){
		tmp = Stack_Pop(this);
		if(tmp == '[')
			tmp = Stack_Pop(this);
		else 
			printf("Error Sintaxis");
		S(this,tmp);
		if(tmp == '[')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		return;
	}
	else if(tmp == 'm' || tmp == 's' || tmp == 'p' || tmp == 'a' || tmp == ']')
		return;
	else
		printf("Error Sintaxis");
}
void R(Stack * this, char tmp)
{
	if(tmp == 'a' || tmp == 'b' || tmp == 'z' || tmp == 'f'){
		Q(this,tmp);
		J(this,tmp);
		Q(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void Q(Stack * this, char tmp)
{
	if(tmp == 'a' || tmp == 'b' || tmp == 'z' || tmp == 'f'){
		tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis");
}
void J(Stack * this, char tmp)
{
	if(tmp == 'i' || tmp == '!' || tmp == '>' || tmp == '<' || tmp == 'y' || tmp == 'n'){
		tmp = Stack_Pop(this);
		return;
	else
		printf("Error Sintaxis");
}
void E(Stack * this, char tmp)
{
	if(tmp == '('){
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void EP(Stack * this, char tmp)
{
	if(tmp == '+'){
		tmp = Stack_Pop(this);
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else if(tmp == '-'){
		tmp = Stack_Pop(this);
		T(this,tmp);
		EP(this,tmp);
		return;
	}
	else if(tmp == ')' || tmp == ';')
		return;
	else
		printf("Error Sintaxis");
}
void T(Stack * this, char tmp)
{
	if(tmp == '(' || tmp == 'a' || tmp == 'b' || tmp == 'z'){
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else
		printf("Error Sintaxis");
}
void TP(Stack * this, char tmp)
{
	if(tmp == 'x'){
		tmp = Stack_Pop(this);
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else if(tmp == '/'){
		tmp = Stack_Pop(this);
		F(this,tmp);
		TP(this,tmp);
		return;
	}
	else if(tmp == '+' || tmp == '-' || tmp == ')' || tmp == ';')
		return;
	else
		printf("Error Sintaxis");
}
void F(Stack * this, char tmp)
{
	if(tmp == '('){
		tmp = Stack_Pop(this);
		E(this,tmp);
		if(tmp == ')')
			tmp = Stack_Pop(this);
		else
			printf("Error Sintaxis");
		return;
	}
	else if(tmp == 'a' || tmp == 'b' || tmp == 'z'){
		tmp = Stack_Pop(this);
		return;
	}
	else
		printf("Error Sintaxis");
}
		
