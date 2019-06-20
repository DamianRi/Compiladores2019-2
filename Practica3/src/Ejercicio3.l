%{
    #include <stdio.h>
    int suma;
    char linea[256];
    int i = 0;
%}
%option noyywrap

%%

[0-9]+ {suma += atoi(yytext); 
        linea[i] = *yytext; 
        i++;}
"A" {printf("%d\n", suma);}
"B" {linea[i] = *yytext; i++; printf("%s\n", linea);}
\n  {suma = 0; memset(linea, 0, sizeof(linea)); i= 0;}
. {linea[i] = *yytext; i++;}


%%

int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
	yyin = f;
    yylex();
    fclose(yyin);
}