#include <stdio.h>

int main() {
    int i, n;
    /*Cria 100 variáveis do tipo inteiro que
    são acessadas pelos índices 0 a 99*/
    int velocidades[100];

    scanf("%d", &n);

    /* guardamos as velocidades */
    for (i = 0; i < n; i++) {
        scanf("%d", &velocidades[i]);
    }

    int duracao;
    scanf("%d", &duracao);

    int limite;
    if (duracao == 1){
        limite = 100;
    }
    else if (duracao == 2){
        limite = 20;
    }
    else{
        limite = 10;
    }

    int maxima;
    maxima = 0;

    for (i=0; i<n; i++){
        if (velocidades[i] > maxima && velocidades[i]<=limite){
            maxima = velocidades[i];
        }
    }

    printf("%d\n", maxima);
}