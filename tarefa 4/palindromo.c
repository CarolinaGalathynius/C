#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA 20

/* funções comprimento_str e copiar_inverso */

int comprimento_str(char string[]) {
    int comprimento = 0;
    while (string[comprimento] != '\0') {
        comprimento += 1;
    }
    return comprimento;
}

void copiar_inverso(char palavra[], char inverso[]) {
    int i, j;
    i = comprimento_str(palavra) - 1;  /* índice da última letra de palavra */
    j = 0;                             /* índice da primeira posição de inverso */
    while (i >= 0) {
        /* copia a i-ésima letra de palavra para a j-ésima posição de inverso */
        inverso[j] = palavra[i];
        i = i - 1;
        j = j + 1;
    }
    /* adicionamos o '\0' para indicar que a string inverso terminou */
    inverso[j] = '\0';
}

int main() {
    char palavra[MAX_PALAVRA];
    char inverso[MAX_PALAVRA];

    scanf("%s", palavra);
    copiar_inverso(palavra, inverso);
    if (strcmp(palavra, inverso) == 0) /* se as strings são iguais */
        printf("É palíndromo\n");
    else
        printf("Não é palíndromo\n");
}