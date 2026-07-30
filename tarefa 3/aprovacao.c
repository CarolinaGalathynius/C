#include <stdio.h>
#define MAX_ALUNOS 100

/*Você começa com float porque é o 
que a função vai retornar*/
float ler_media(int m) {
    int i;
    float media, nota;
    media = 0;
    for (i = 0; i < m; i++) {
        scanf("%f", &nota);
        media += nota;
    }
    media = media / m;
    return media;
}

void ler_notas_praticas(float P[MAX_ALUNOS], int n) {
    int i; /* índice da posição do vetor */
    for (i = 0; i < n; i++) {
        P[i] = ler_media(3);
    }
}

int main() {
    float media;
    float P[MAX_ALUNOS];
    media = ler_media(3);
    printf("%f\n", media);
}