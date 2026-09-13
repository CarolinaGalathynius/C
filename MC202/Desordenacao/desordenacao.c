/*

def medir_desordenacao(cadeia):
    desordenacao = 0
    for i in range(len(cadeia)):
        for k in range(i+1, len(cadeia)):
            if cadeia[i]>cadeia[k]:
                desordenacao += 1
    return desordenacao 

def main():
    c = int(input())
    for i in range(c):
        desordenacoes = []
        espaco = input()
        j, k = map(int, input().split())
        cadeias = [None] * k
        for a in range(k):
            cadeias[a] = input().strip()
            desordenacao = medir_desordenacao(cadeias[a])
            desordenacoes.append(desordenacao)
        des_ordenadas = sorted(desordenacoes)
        visitei = [0] * k
        for a in range(k):
            b = 0
            while desordenacoes[b] != des_ordenadas[a] or visitei[b]==1:
                b+=1
            visitei[b] = 1
            print(f"{cadeias[b]}")
        print()
main()
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ordenar_vetor(const void *a, const void *b){
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

int medir_desordenacao(char cadeia[]){
    int desordenacao = 0;
    for(int i=0; i<strlen(cadeia); i++){
        for(int k=i+1; k<strlen(cadeia); k++){
            if(cadeia[i]>cadeia[k]){
                desordenacao++;
            }
        }
    }
    return desordenacao;
}

int main(void){
    int c;
    scanf("%d", &c);
    for(int i = 0; i<c; i++){
        getchar();
        int k, j;
        scanf("%d %d", &j, &k);
        int desordenacoes[k];
        char cadeias[j][k];
        char cadeia;
        scanf("%c", &cadeia);
        int contador = 0;
        for(int a=0; a<k; a++){
            while(cadeia != "\n"){
                cadeias[a][contador] = cadeia;
                scanf("%c", &cadeia);
                contador++;
            }
            int desordenacao = medir_desordenacao(cadeias[a]);
            desordenacoes[a] = desordenacao;
        }
        int des_ordenadas = qsort()
    }
}


/*
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
    */