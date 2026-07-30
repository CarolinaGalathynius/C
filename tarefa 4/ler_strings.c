#include <stdio.h>

#define MAX_PALAVRA 10

int comprimento_str(char string[]) {
    /*Faz a mesma coisa que a função strlen*/
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
    printf("Você escreveu %s\n", palavra);
}