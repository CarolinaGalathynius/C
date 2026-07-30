#include <stdio.h>
#define MAX_ALUNOS 100

float obter_maximo(float vetor[MAX_ALUNOS], int n) {
    int i;
    float maximo = vetor[0];
    for (i = 0; i < n; i++) {
        if (maximo < vetor[i])
            maximo = vetor[i];
    }
    return maximo;
}

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

void ler_notas_teoricas(float T[MAX_ALUNOS], int n){
    int i; /* índice da posição do vetor */
    for (i = 0; i < n; i++) {
        T[i] = ler_media(2);
    }
}

void mutiplicar_fator(float vetor[MAX_ALUNOS], int n, float fator) {
    int i;
    for (i = 0; i < n; i++) {
        vetor[i] = vetor[i] * fator;
    }
}

void encontrar_finais(float notas[MAX_ALUNOS], float P[MAX_ALUNOS], float T[MAX_ALUNOS], int n){
    int i; /* índice da posição do vetor */
    int media;
    for (i = 0; i < n; i++) {
        media = ((P[i]+T[i])/2);
        notas[i] = media;
    }
}

void imprimir_finais(float notas[MAX_ALUNOS], int n){
    int i; /* índice da posição do vetor */
    for (i = 0; i < n; i++) {
        printf("%.1f\n", notas[i]);
    }
}

float computar_media(float vetor[MAX_ALUNOS], int n){
    int media, i;
    for(i=0; i<n; i++){
        media = media + vetor[i];
    }
    media = media/n;
    return media;
}

int main() {
    int n;
    float P[MAX_ALUNOS];
    float T[MAX_ALUNOS];
    float notas[MAX_ALUNOS];
    float maximo_p, maximo_te, media_p, media_te;

    scanf("%d", &n);

    ler_notas_praticas(P, n);
    ler_notas_teoricas(T, n);
    mutiplicar_fator(P, n, 1.1);

    maximo_p = obter_maximo(P, n);
    maximo_te = obter_maximo(T, n);

    mutiplicar_fator(T, n, 10/maximo_te);
    maximo_te = obter_maximo(T, n);

    encontrar_finais(notas, P, T, n);

    imprimir_finais(notas, n);

    printf("Max P: %.1f\n", maximo_p);
    printf("Max T: %.1f\n", maximo_te);

    media_p = computar_media(P, n);
    media_te = computar_media(T, n);

    printf("Media P: %.1f\n", media_p);
    printf("Media T: %.1f\n", media_te);

}