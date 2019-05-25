#include <string.h>
#include <stdio.h>

int main () {
   /*
   char str[10]= "11/10";
   char x = *str;
   const char s[2] = "/";
   char *token2;
   token2 = strtok(str, s);
   while( token2 != NULL ) {
      printf( " %d\n", atoi(token2));
      token2 = strtok(NULL, s);
   }
   */
  char valor = 'a';
  char valor2[15] = "ab";
   printf("%d", strcmp(valor2, (char*)valor));
   return(0);
}