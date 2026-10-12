#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "funcoes_index.h"


int main(void) {

  char cmd[2], nivel[10], estado[14];
  long x;

  dicionario* head = NULL;

  while(1){
    if (scanf("%s", cmd) != 1) exit(1);

    if (strcmp(cmd,"i") == 0) {
      if (scanf("%ld %s %s", &x, nivel, estado) != 3) exit(1);
    }

    else if (strcmp(cmd,"a") == 0) {
      if (scanf("%ld %s %s", &x, nivel, estado) != 3) exit(1);
    }

    else if (strcmp(cmd,"b") == 0) {
      if (scanf("%ld ", &x) != 1) exit(1);
    }

    else if (strcmp(cmd,"l") == 0) {
      // O progaram debe imprimir os identificadores dos documentos 
      // da árvore em ordem crescente em uma única linha separados 
      // por espaço. Se o índice estiver vazio, o programa deve 
      // imprimir Indice vazio.
    }

    else if (strcmp(cmd,"t") == 0) {
      // Deve imprimir o número de documentos no índice categorizando 
      // por estado.
    }

    else if (strcmp(cmd,"f") == 0) {
      // FREE TUDO
      return 0;
    }
  }
}