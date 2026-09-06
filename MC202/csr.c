#include<stdio.h>

// Ordena as linhas de M, de modo que as linhas fiquem em ordem crescente
void ordenar_linhas(M[m][n]){
    int apoio, a, b, c;
    for(int i=0; i<(m-1); i++){
        for(int k=0; k<(m-1); k++){
            apoio=M[i][0];
            if(apoio>M[i+1][0]){
                a = M[i][0];
                b = M[i][1];
                c = M[i][2];
                M[i][0] =M[i+1][0];
                M[i][1] =M[i+1][1];
                M[i][2] =M[i+1][2];
                M[i+1][0] =a;
                M[i+1][1] = b;
                M[i+1][2] = c;
            }
        }
    }
}

// A, de tamanho k, armazenas os elementos não-zero de M por linhas.
void montar_A(A[], M[][], k){
    for(int i=0; i<k; i++){
        A[i] = M[i][2]
    }
}

// C, de tamanho k, armazena a coluna de cada elemento de A.
void montar_C(C[], M[][], k){
    for(int i=0; i<k; i++){
        C[i] = M[i][1]
    }
}

// R, de tamanho m+1, é tal que R[i], armazena o número de elementos 
// não-zero em M até o início da linha i, e R[m] é igual a k.
void montar_R(R[], M[][], k){
    int apoio = 0, linha_atual = -1;
    for(int i=0; i<k; i++){
        if(M[i][0] == linha_atual){
            apoio++;
        } else {
            linha_atual++;
            R[linha_atual] = apoio;
        }
    }
    R[linha_atual] = apoio;
}

void imprimir_saida(int i, int j, int num){
    printf("(%d, %d) = %d\n", i, j, num);
}

#include<stdio.h>
    int main(void){
    int k;
    scanf("%d", &k); // Número de elementos não-zero

    int M[k][3];

    for(int i=0; i<k; i++){
        for(int w=0; w<3; w++){
            scanf("%d", &M[i][w]);
        }
    }

    int A[k], C[k], R[m+1];

    ordenar_linhas(M);

    A = montar_A(M,k);
    C = montar_C(M, k);
    R = montar_R(M, k);

    int i, int j;

    while(j != -1 && i != -1){
        scanf("%d %d", &i, &j);
        if(R[i] == R[i+1]){
            imprimir_saida(i, j, 0);
        } else {
            for(int w=R[i]; w<R[i+1]; w++){
                if(C[w] == j){
                    imprimir_saida(i, j, A[w]);
                }
            }
        }
    }

    return 0;
}