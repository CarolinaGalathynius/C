#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ordenar_vetor(const void *a, const void *b){
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

void trocar_linhas(int V[], int k, int j, char **cadeias, int i1, int i2){
    // A posição i1 inverte com a i2 em ambos os vetores V e cadeias
}

int main(void){
    int c;
    scanf("%d", &c);
    int k, j;
    for(int i=0; i<c; i++){
        getchar(); 
        scanf("%d %d", &k, &j);
        cadeias = (char **)malloc(k * sizeof(char *));
        //Terminar de alocar memória para cada cadeia de caracteres
    }
    for(int i=0; i<k; i++){
        free(cadeias[i]);
    }
    free(cadeias);
}