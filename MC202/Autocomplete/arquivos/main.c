#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "funcoes_auto.h"


int main(void) {

  char cmd[13], x[10000];
  long f;
  int i, k;
  dicionario* head = NULL;

  while (1) {
    if (scanf("%s", cmd) != 1) exit(1);

    if (strcmp(cmd,"INSERT") == 0) {
      if (scanf("%s %ld", x, &f) != 2) exit(1);
      df_insert(&head, x, f);
    }

    else if (strcmp(cmd,"SEARCH") == 0) {
      if (scanf("%s", x) != 1) exit(1);
      df_search(head, x);
    }

    else if (strcmp(cmd,"AUTOCOMPLETE") == 0) {
      if (scanf("%s %ld", x, &f) != 2) exit(1);
      i = df_autocomplete(head, x, f);
    }

    else if (strcmp(cmd,"DELETE") == 0) {
      if (scanf("%s", x) != 1) exit(1);
      i = df_delete(&head, x);
    }

    else if (strcmp(cmd,"PRINT") == 0) {
      k=0;
      df_print(head, k);
      printf("\n");
    }
    else if (strcmp(cmd,"EXIT") == 0) {
      df_free(head);
      return 0;
    }
  }
}