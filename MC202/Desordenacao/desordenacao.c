#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ordenar_vetor(const void *a, const void *b){
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

void trocar_linhas(int V[], int k, int j, char **cadeias, int i1, int i2){
    char *apoio_c;
    apoio_c = cadeias[i1];
    cadeias[i1] = cadeias[i2];
    cadeias[i2] = apoio_c;
    int apoio_v;
    apoio_v = V[i1];
    V[i1] = V[i2];
    V[i2] = apoio_v;
}

int main(void){
    int c;
    scanf("%d", &c);
    int k, j;
    for(int i=0; i<c; i++){
        getchar(); 
        scanf("%d %d", &k, &j);
        char **cadeias;
        cadeias = (char **)malloc(k * sizeof(char *));
        for(int i=0; i<k; i++){
            cadeias[i] = (char *)malloc(j * sizeof(char));
        }
        for(int i=0; i<k; i++){
            free(cadeias[i]);
        }
        free(cadeias);
    }
}