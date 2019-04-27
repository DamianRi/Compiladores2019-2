%{
  #include <stdio.h>
  #include "estructuras.h"
%}

%option noyywrap

digito [0-9]
identificador [a-zA-Z_][a-zA-Z0-9_]{0,31}

%%

"a" {printf("Letra a"); return 2;}
"b" {printf("Letra b"); return 1;}
"+" {printf("Mas +"); return 3;}
"*" {printf("Ast *"); return 4;}
"?" {printf("Opc ?"); return 5;}
"(" {printf("Pariz ("); return 6;}
"or" {printf("Or or"); return 7;}
")" {printf("Parde )"); return 8;}
"$" {printf("Fin $"); return 9;}

" " {/*Ignorar Espacios*/}
{digito} {return yytext;}
{identificador} {return yytext;} //<<EOF>> {return 0;}  regresar indices de los no terminales del arreglo de simbolos
. {printf("No reconocido, termina ejecución.\n"); return 0;}

%%
