****************
# Práctica 3
## Rivera González Damián.
****************


## Contenido
Dentro de la carpeta "src" se encuentran los siguientes archivos:

### Ejercicio1.l: 
el código para Hacer un programa en lex que reciba como entrada un archivocon palabras escritas en minúsculas y genere como salida un archivo con todas las palabras escritas en mayúsculas. (considere una palabra como aquella cadena que la separan espacios)

    Uso:
``` 
        flex Ejercicio1.l   //Genera el archivo lex.yy.c
        gcc lex.yy.c -o Ej1 -lfl //Genera el ejecutable con el nombre Ej1
        ./Ej1 <archivo> 
```
        donde <archivo> debe ser un archivo de texto cualquiera

    Ejemplo de uso:
```
        ./Ej1 texto 
```
### Ejercicio2.l:
el código para Hacer un programa en lex que comporte como el comando wc de Linux, es decir dado un archivo de entrada debe arrojar a la salida cuantas palabras tiene, el número de lı́neas, el número de caracteres.
    
    Uso:
``` 
        flex Ejercicio2.l   //Genera el archivo lex.yy.c
        gcc lex.yy.c -o Ej2 -lfl //Genera el ejecutable con el nombre Ej2
        ./Ej2 <archivo> 
```    
        donde <archivo> debe ser un archivo de texto cualquiera

    Ejemplo de uso:
```
        ./Ej2 texto 
```
### Ejercicio3.l:
Hacer un programa en lex que reciba un archivo que contiene lı́neas de números enteros separadas por espacios, la lı́neas pueden terminar en A o en B, para las lı́neas que terminen en A imprimir la suma de los números de esa lı́nea, para las lı́neas que terminen en B imprimir la lı́nea tal como aparece en el programa fuente.
    Uso: 
```
        flex Ejercicio3.l   //Genera el archivo lex.yy.c
        gcc lex.yy.c -o Ej3 -lfl //Genera el ejecutable con el nombre Ej3
        ./Ej3 <archivo> 
```    
        donde <archivo> debe ser un archivo de texto cualquiera

    Ejemplo de uso:
```
        ./Ej3 sumas
```
### Ejercicio4.l:
Hacer un programa en lex que reciba un archivo con palabras y espacios en blanco y genere un archivo en donde se eliminaron los espacios en blanco.

    Uso: 
```
        flex Ejercicio4.l   //Genera el archivo lex.yy.c
        gcc lex.yy.c -o Ej4 -lfl //Genera el ejecutable con el nombre Ej4
        ./Ej1 <archivo> 
```    
        donde <archivo> debe ser un archivo de texto cualquiera

    Ejemplo de uso:
```
        ./Ej4 texto 
```
### Ejercicio5.l:
Hacer un analizador léxico que genere los siguientes tokens

Todas las definiciones que se solicitan están dentro del archivo Ejercicio5.l
El cual se debe usar como:

    Uso:
```
        flex Ejercicio5.l   //Genera el archivo lex.yy.c
        gcc lex.yy.c -o Ej5 -lfl //Genera el ejecutable con el nombre Ej5
        ./Ej5
```
