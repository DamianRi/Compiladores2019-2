# PRÁCTICA 4

### Contenido

Dentro de la carpeta `src` se encuentran los archivos para ejecutar

lexer.l: el archivo que reconoce la gramática 

estructuras.h : donde estan las estructuras y de simbolos, producciones, pila y nodo.
 
conexcion.c : el archivo donde se encuentran las funciones sobre la pila así como el algoritmo de 
análisis sintáctico


### Ejecución

1. Generar el archivo de C del analizador de flex con el cual se generará el archivo `lex.yy.c`
```
flex lexer.l
```

2. Enlazar el archivo lex.yy.c con el código en C, que ejecutará el algoritmo
```
gcc -Wall lex.yy.c conexion.c -o practica
```
Con el cual generará el ejecutable `practica`

#### Forma de Usar

Debido a que se debe ingresar un archivo de texto con la sintáxis para analizar deberá pasarse 
como parametro para la ejecución del programa.
Se da el archivo `texto` como ejemplo para uso.

```
 ./practica texto

	o

 ./practica <archivo> 
 donde <archivo> es el nombre del archivo de texto para analizar
```

### NOTAS

Para el analisis de las sentencias que se escriban en el archivo de texto, cada sentencia debe 
terminar con el símbolo `$` (de pesos) así sea la última sentencia del archivo.

Además para hacer referencia al token "OR" se tomará como símbolo "|" (pipe)

