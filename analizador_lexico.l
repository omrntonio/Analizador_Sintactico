%{
/*
  Alumnos : 
  Merino Hernández Ailyn
  Omar Antonio González Luna
  Proyecto 1: Analizador Lexico de un lenguaje propuesto por nosotros.
*/
#include <stdlib.h>
#include <stdio.h>
#include "LL_Int.h"

//Se declaran las tablas de componentes lexicos variables
LL * Identificadores;
LL * Constantes_Ent;
LL * Constantes_Real;
LL * Constantes_Carac;

//Se declaran las tablas de componentes lexicos estaticos
char * PALRES[7] = {"carac","ent","mientras","para","real","si","sino"};
char * OPREL[6] = {".IG.",".DI.",".MY.",".MN.",".MYI.",".MNI."};
const int CARACESP[7] = {';','(',')','{','}','[',']'};
const int OPARIT[4] = {'+','-','x','/'};
const int OPASIG = '=';

//Archivos de salida del analisis y errores
FILE * salida1, *salida2, *salida3;

//Variable temporal
Nodo * tmp;
Bool cond;
//Indices para la posicion en las tablas
int index_ident=0, index_ent=0, index_real=0, index_caract=0;
%}
dig [1-9]
mayuscula [A-Z]
minuscula [a-z]
minuscula_x [a-wyz]
caract_esp [\;\(\)\{\}\[\]]
dec {dig}({dig}|0){0,4}
reales ((0|{dig})*\.(0|{dig})*((e|E)(\-|\+)?{dig}(0|{dig})*)?)|{dig}(0|{dig})*(e|E)(\-|\+)?{dig}(0|{dig})*
ident ({mayuscula}({minuscula}{0,5})(x{minuscula_x}|{minuscula_x}{1,2}))|{mayuscula}
caract \'.\'
op_arit [\+\-x\/]
op_asig \=
op_rel ".IG."|".DI."|".MY."|".MN."|".MYI."|".MNI."
res carac|ent|mientras|para|real|si|sino
%%
{reales}     {if(LL_FindIf(Constantes_Real,0,atof(yytext),NULL)){
                  fprintf(salida1,"(%i,%.5f)\n\n",4, atof(yytext));
              }
              else{
                  fprintf(salida1,"(%i,%.5f)\n\n",4, atof(yytext));
                  LL_Insert(Constantes_Real,index_real,0,atof(yytext),NULL);
                  index_real++;
                  }
              }
{dec}        {if(LL_FindIf(Constantes_Ent,atoi(yytext),0,NULL)){
                  fprintf(salida1,"(%i,%i)\n\n",3, atoi(yytext));
              }
              else{
                  fprintf(salida1,"(%i,%i)\n\n",3, atoi(yytext));
                  LL_Insert(Constantes_Ent,index_ent,atoi(yytext),0,NULL);
                  index_ent++;
                  }
              }
{caract_esp} {fprintf(salida1,"(%i,%i)\n\n",2,yytext[0]);}
{caract}     {if(LL_FindIf(Constantes_Carac,yytext[1],0,NULL))
	              fprintf(salida1,"(%i,%i)\n\n",5,yytext[1]);
	          else{
                  LL_Insert(Constantes_Carac,index_caract,yytext[1],0,NULL);
                  fprintf(salida1,"(%i,%i)\n\n",5,yytext[1]);
                  index_caract++;
	              }
             }
{op_arit}    {fprintf(salida1,"(%i,%i)\n\n",6,yytext[0]);}
{op_asig}    {fprintf(salida1,"(%i,%i)\n\n",7,yytext[0]);}
{op_rel}     {for(int i = 0; i<6; i++){
                  if(!strcmp(OPREL[i],yytext))
                      fprintf(salida1,"(%i,%i)\n\n",8,i);}
             }
{res}        {for(int i = 0; i<7; i++){
                  if(!strcmp(PALRES[i],yytext))
                      fprintf(salida1,"(%i,%i)\n\n",1,i);}
             }
{ident}      {if(LL_FindIf(Identificadores,0,0,yytext)){
                  tmp = LL_Search(Identificadores,0,0,yytext);
                  fprintf(salida1,"(%i,%i)\n\n",0,tmp->posicion);
             }
              else{
                  fprintf(salida1,"(%i,%i)\n\n",0,index_ident);
                  LL_Insert(Identificadores,index_ident,0,0,yytext);
                  index_ident++;
                  }
              }
--.*$
[ \t\n]+ 
. {fprintf(salida2,"Error componente lexico no reconocido: %s\n\n",yytext);}
%%
int main(int argc, char *argv[])
{
    //Se crean las tablas de componentes lexicos
    Identificadores = LL_Create();
    Constantes_Ent = LL_Create();
    Constantes_Real = LL_Create();
    Constantes_Carac = LL_Create();
    
    //Se lee el archivo de consola
    yyin=fopen(argv[1],"r");
    
    //Archivo con los tokens
    salida1 = fopen("analisis_lexico.txt","w");
    
    //Archivo con los errores lexicos
    salida2 = fopen("Errores_lexicos.txt","w");
    
    //Archivo con la cadena de atomos (Componentes lexicos)
    salida3 = fopen("InputSintaxis.txt","w+");
    
    yylex();
    fclose(salida1);
    fclose(salida2);
    fclose(salida3);

    //Se imprime los datos de las tablas
    printf("--------Tabla de Identificadores------------\n");
    LL_Print(Identificadores,3);
    printf("--------Tabla de Constantes Enteras---------\n");
    LL_Print(Constantes_Ent,1);
    printf("--------Tabla de Constantes Reales----------\n");
    LL_Print(Constantes_Real,2);
    printf("--------Tabla de Constantes Caracter--------\n");
    LL_Print(Constantes_Carac,1);

    //Se libera la memoria de las tablas
    LL_Destroy(Identificadores);
    LL_Destroy(Constantes_Ent);
    LL_Destroy(Constantes_Real);
    LL_Destroy(Constantes_Carac);
    return 0;
}
