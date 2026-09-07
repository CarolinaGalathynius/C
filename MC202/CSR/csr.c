#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int comparar(const void *a, const void *b){
    int *A = (int *)a;
    int *B = (int *)b;
    if(A[0] != B[0]){
        return A[0] - B[0];
    } else {
        return A[1] - B[1];
    }
}

int encontrar_maior(int k, int M[k][3]){
    int maior = 0;
    for(int i = 0; i < k; i++){
        if(M[i][0] > maior){
            maior = M[i][0];
        }
    }
    return maior;
}

// A, de tamanho k, armazenas os elementos não-zero de M por linhas.
void montar_A(int A[], int k, int M[k][3]){
    for(int i=0; i<k; i++){
        A[i] = M[i][2];
    }
}

// C, de tamanho k, armazena a coluna de cada elemento de A.
void montar_C(int C[], int k, int M[k][3]){
    for(int i=0; i<k; i++){
        C[i] = M[i][1];
    }
}

void montar_R(int R[], int k, int M[][3], int maior){
    int i = 0;
    R[0] = 0;
    for (int linha = 0; linha <= maior; linha++){
        int suporte = 0;
        while (i < k && M[i][0] == linha){
            suporte++;
            i++;
        }
        R[linha + 1] = R[linha] + suporte;
    }
}

void imprimir_saida(int i, int j, int num){
    printf("(%d,%d) = %d\n", i, j, num);
}

int main(void){
    int k;
    scanf("%d", &k); // Número de elementos não-zero

    int (*M)[3] = malloc(k * sizeof(*M)); 
    if(M == NULL) {
        return 1;
    }
    for(int i=0; i<k; i++){
        for(int w=0; w<3; w++){
            scanf("%d", &M[i][w]);
        }
    }

    qsort(M, k, sizeof(M[0]), comparar);
    int maior = encontrar_maior(k, M);
    int *R = malloc((maior + 2) * sizeof(int));
    int *A = malloc(k * sizeof(int));
    int *C = malloc(k * sizeof(int));

    montar_A(A, k, M);
    montar_C(C, k, M);
    montar_R(R, k, M, maior);
    if(R == NULL || A == NULL || C == NULL){
        free(M);
        return 1;
    }

    int i, j;
    scanf("%d %d", &i, &j);
    bool encontrou = false;

    while(j != -1 && i != -1){
        encontrou = false;
        if(i>maior || R[i] == R[i+1]){
            imprimir_saida(i, j, 0);
            encontrou = true;
        } else {
            for(int w=R[i]; w<R[i+1]; w++){
                if(C[w] == j){
                    imprimir_saida(i, j, A[w]);
                    encontrou = true;
                }
            }
        } if(encontrou == false){
            imprimir_saida(i, j, 0);
        }
        scanf("%d %d", &i, &j);
    }
    free(R);
    free(A);
    free(C);
    free(M);
    return 0;
}