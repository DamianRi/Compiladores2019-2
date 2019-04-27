#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#define NUM_NON_TERM 7
#define NUM_TERM 9
extern int yylex();
extern char *yytext;


/**
 * @brief  Función que agrega un elemento en el tope de la pila.
 * @param  *stack: referencia a la pila sobre la cual se trabaja.
 * @param  symbol: símbolo que estará en el nodo en el tope de la pila. 
 * @retval None
 */
void push(Stack *stack, Sym symbol){

  Node * tope = malloc(sizeof(Node));
  tope -> info = symbol;

  if(stack -> num == 0 && stack -> root == NULL){
    stack -> root = tope;
  }else{
    Node * iterador = stack->root;
    //iterador = stack -> root;

    while (iterador -> next){
      iterador = iterador->next;
    }
    iterador -> next = tope;
  }
  stack -> num = stack -> num+1;
  printf("Push a la Pila.\n");

}

 /**
  * @brief  Función que elimina el nodo del tope de la pila.
  * @param  *stack: la referencia a la pila sobre la cual se trabaja.
  * @retval None
 */
void pop(Stack *stack){

  if(stack -> num == 0){
    printf("No hay elementos en la pila.\n");
  }else{
    //Caso en que haya un único elemento
    if (!stack -> root -> next){
      stack -> root = 0;
    }else{
      Node * iterador = stack -> root -> next;
      Node * penultimo = stack -> root;
      //Vamos al tope de la pila
      while (iterador -> next){
        iterador = iterador -> next;
        penultimo = penultimo ->next;
      }
      penultimo -> next = 0;
    }
    stack -> num = stack -> num-1;
    printf("Pop a la Pila.\n");
  }

}

/**
 * @brief  Función que dada un Stack devuelve la referencia al nodo que está al tope de la pila.
 * @param  *stack: referencia a la pila sobre la que se trabaja
 * @retval la referencia al nodo en el tope de la pila.
 */
Node * tope(Stack *stack){

  Node * iterador = stack -> root;
  //iterador = stack -> root;
  while (iterador -> next){
    iterador = iterador -> next;
  }
  return iterador; 
}

/**
 * @brief  Función que imprime la información de la pila que se pasa como parámetro
 * @param  stack: referencia a la pila sobre la cual se trabaja.
 * @retval None
 */
void infoStack(Stack * stack){
  if (stack->num != 0)
  {
    printf("Root: %s\nNum: %d\nTope: %s\n", stack->root->info.name, stack ->num, tope(stack) ->info.name);
  }else
  {
    printf("Root: NULL\nNum: 0\nTope: NULL\n");
  }
  

  
}


void configuracion(){
  Sym term_a = {type:1, name:"a", pos:0};
  Sym term_b = {type:1, name:"b", pos:1};
  Sym term_mas = {type:1, name: "+", pos:2};
  Sym term_est = {type:1, name: "*", pos:3};
  Sym term_opc = {type:1, name: "?", pos:4};
  Sym term_parizq = {type:1, name: "(", pos:5};
  Sym term_or = {type:1, name:"or", pos:6};
  Sym term_parder = {type:1, name: ")", pos:7};
  Sym term_fin = {type:1, name: "$", pos:8};
  Sym epsilon = {type: 3, name:"epsilon", pos:9};
  
  Sym A = {type: 2, name:"A", pos:0};
  Sym AP = {type: 2, name:"AP", pos:1};
  Sym B = {type: 2, name:"B", pos:2};
  Sym BP = {type: 2, name:"BP", pos:3};
  Sym C = {type: 2, name:"C", pos:4};
  Sym CP = {type: 2, name:"CP", pos:5};
  Sym D = {type: 2, name:"D", pos:6};
  
  Sym simbolos[17];
  simbolos[0] = term_a;
  simbolos[1] = term_b;
  simbolos[2] = term_mas;
  simbolos[3] = term_est;
  simbolos[4] = term_opc;
  simbolos[5] = term_parizq;
  simbolos[6] = term_or;
  simbolos[7] = term_parder;
  simbolos[8] = term_fin;
  simbolos[9] = A;
  simbolos[10] = AP;
  simbolos[11] = B;
  simbolos[12] = BP;
  simbolos[13] = C;
  simbolos[14] = CP;
  simbolos[15] = D;
  simbolos[16] = epsilon;

  Prod p0 = {head:9 ,body:"11/10", num:2};  //A->BAP
  Prod p1 = {head:10 ,body:"6/9", num:2};   //AP->orA
  Prod p2 = {head:10 ,body:"16", num:1};    //AP->epsilon
  Prod p3 = {head:11 ,body:"13/12", num:2}; //B->CBP
  Prod p4 = {head:12 ,body:"11", num:1};    //BP->B
  Prod p5 = {head:12 ,body:"16", num:1};    //BP->epsilon
  Prod p6 = {head:13 ,body:"15/14", num:2}; //C->DCP
  Prod p7 = {head:14 ,body:"2/14", num:2};  //CP->+CP
  Prod p8 = {head:14 ,body:"3/14", num:2};  //CP->*CP
  Prod p9 = {head:14 ,body:"4/14", num:2};  //CP->?CP
  Prod p10 = {head:14 ,body:"16", num:1};   //CP-> epsilon
  Prod p11 = {head:15 ,body:"5/9/7", num:3};//D->(A)
  Prod p12 = {head:15 ,body:"0", num:1};    //D->a
  Prod p13 = {head:15 ,body:"1", num:1};    //D->b

  Prod producciones[14];
  producciones[0] = p0; //A->BAP
  producciones[1] = p1; //AP->orA
  producciones[2] = p2; //AP->epsilon
  producciones[3] = p3; //B->CBP
  producciones[4] = p4; //BP->B
  producciones[5] = p5; //BP->epsilon
  producciones[6] = p6; //C->DCP
  producciones[7] = p7; //CP->+CP
  producciones[8] = p8; //CP->*CP
  producciones[9] = p9; //CP->?CP
  producciones[10] = p10; //CP-> epsilon
  producciones[11] = p11; //D->(A)
  producciones[12] = p12; //D->a
  producciones[13] = p13; //D->b

  int matriz[NUM_NON_TERM][NUM_TERM];
  //Renglon A
  matriz[0][0] = 0;
  matriz[0][1] = 0;   
  matriz[0][2] = -1;
  matriz[0][3] = -1;
  matriz[0][4] = -1;
  matriz[0][5] = 0;
  matriz[0][6] = -1;
  matriz[0][7] = -1;
  matriz[0][8] = -1;
  //Renglon AP
  matriz[1][0] = -1;
  matriz[1][1] = -1;
  matriz[1][2] = -1;
  matriz[1][3] = -1;
  matriz[1][4] = -1;
  matriz[1][5] = -1;
  matriz[1][6] = 1;
  matriz[1][7] = 2;
  matriz[1][8] = 2;
  //Renglon B
  matriz[2][0] = 3;
  matriz[2][1] = 3;
  matriz[2][2] = -1;
  matriz[2][3] = -1;
  matriz[2][4] = -1;
  matriz[2][5] = 3;
  matriz[2][6] = -1;
  matriz[2][7] = -1;
  matriz[2][8] = -1;
  //Renglon BP
  matriz[3][0] = 4;
  matriz[3][1] = 4;
  matriz[3][2] = -1;
  matriz[3][3] = -1;
  matriz[3][4] = -1;
  matriz[3][5] = 4;
  matriz[3][6] = 5;
  matriz[3][7] = 5;
  matriz[3][8] = 5;
  //Renglon C
  matriz[4][0] = 6;
  matriz[4][1] = 6;
  matriz[4][2] = -1;
  matriz[4][3] = -1;
  matriz[4][4] = -1;
  matriz[4][5] = 6;
  matriz[4][6] = -1;
  matriz[4][7] = -1;
  matriz[4][8] = -1;
  //Renglon CP
  matriz[5][0] = 10;
  matriz[5][1] = 10;
  matriz[5][2] = 7;
  matriz[5][3] = 8;
  matriz[5][4] = 9;
  matriz[5][5] = 10;
  matriz[5][6] = 10;
  matriz[5][7] = 10;
  matriz[5][8] = 10;
  //Renglon D
  matriz[6][0] = 12;
  matriz[6][1] = 13;
  matriz[6][2] = -1;
  matriz[6][3] = -1;
  matriz[6][4] = -1;
  matriz[6][5] = 11;
  matriz[6][6] = -1;
  matriz[6][7] = -1;
  matriz[6][8] = -1;


}

int main() {
  /*
  Stack pila = {root:0, num: 0};
  Sym sym = {type:1, name:"a", pos:0};
  Sym sym2 = {type:2, name: "A", pos:1};
  Sym sym3 = {type:3, name: "epsilon", pos:2};
  push(&pila, sym);
  push(&pila, sym2);
  push(&pila, sym3);
  infoStack(&pila);
  pop(&pila);
  infoStack(&pila);
  pop(&pila);
  infoStack(&pila);
  push(&pila, sym3);
  infoStack(&pila);
  pop(&pila);
  pop(&pila);
  infoStack(&pila);
  */



  while(yylex() != 0) {
    //primera forma
    /*
    char *token1 = strdup(yytext);
    printf("token1 value: %s\n", token1);
    free(token1);
    */
    
    //segunda forma
    int indice = 0;
    char *token2 = malloc(sizeof(yytext));    
    strcpy(token2, yytext);
    if(*token2 == 'a'){
      printf("a");
      indice = 0;
      printf("Indice %d", indice);
    }
    printf("token2 value: %s\n", token2);
    free(token2);
  };
  /*
  */
} 
