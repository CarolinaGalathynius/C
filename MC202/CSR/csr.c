#include<stdio.h>
#include<stdbool.h>

int ordenar_linhas(int k, int M[k][3]){
    int a, b, c;
    int maior = 0;

    for(int i = 0; i < k - 1; i++){
        for(int j = 0; j < k - 1 - i; j++){
            if(maior < M[j][0]){
                maior = M[j][0];
            }
            if(M[j][0] > M[j+1][0] || (M[j][0] == M[j+1][0] && M[j][1] > M[j+1][1])){
                a = M[j][0];
                b = M[j][1];
                c = M[j][2];
                M[j][0] = M[j+1][0];
                M[j][1] = M[j+1][1];
                M[j][2] = M[j+1][2];
                M[j+1][0] = a;
                M[j+1][1] = b;
                M[j+1][2] = c;
            }
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

    int M[k][3];
    for(int i=0; i<k; i++){
        for(int w=0; w<3; w++){
            scanf("%d", &M[i][w]);
        }
    }

    int A[k], C[k], R[10000];

    int maior = ordenar_linhas(k, M);

    montar_A(A, k, M);
    montar_C(C, k, M);
    montar_R(R, k, M, maior);

    int i, j;
    scanf("%d %d", &i, &j);
    bool encontrou = false;

    while(j != -1 && i != -1){
        encontrou = false;
        if(R[i] == R[i+1]){
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
    return 0;
}