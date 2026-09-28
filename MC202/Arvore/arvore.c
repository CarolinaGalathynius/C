#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
/*
O QUE É UMA ÁRVORE CARTESIANA CANÔNICA?
--> A raiz da árvore é a posição do mínimo no vetor A
--> O filho da esquerda da raiz é a árvore cartesiana de 
A[l...i-1] se i>l ou nulo, caso contrário,
O filho da direita da raiz é a árvore cartesiana de 
A[i+1 ... r] se i<r ou nulo, caso contrário.
--> A[i]<=A[j] ou A[i]=A[j] e i<=j
*/

/*
ANOTAÇÕES DO QUE DEVE SER FEITO
--> Na memória, cada nó deve conter um apontador para 
os filhos da direita e outro para os da esquerda (IDEIA
INICIAL: FAZER ISSO USANDO LISTAS ENCADEADAS).
Lembrando que a árvore é binária e, portanto, cada nó tem 
no máximo dois filhos.
*/

/*
ALGORITMO
Usando recursão
1) Inicialmente, CC tem apenas um nó rotulado 1 e l1 = 0
2) Suponha que CC já foi construída. Sejam v1 ...vk os nós com rótulos 
p1 ... pk no caminho mais à direitaa partir da raiz em CC
3) Por definição, o nó com rótilo i+1 deve ser posicionado de forma que 
ele esteja no fim do caminho mais à direita em CC (se A[1 ... i] não é 
o mínimo então ele está à direita do mínimo, se é mínimo então é a raiz. 
Essa observação pode ser aplicada recursivamente.)
*/

struct no{
    int no;
    struct no* esq;
    struct no* dir;
};

typedef struct no no;

int main(void){
    int n, apoio, min;
    scanf("%d", &n);
    while(n!=0){
        int *V = (int *)malloc(n*sizeof(int));
        bool primeiro = true;
        for(int i=0; i<n; i++){
            scanf("%d", &apoio);
            if(primeiro == true){
                min = apoio;
                primeiro = false;
            } else{
                if(apoio<min){
                    min = apoio;
                }
            }
            V[i] = apoio;
        }

        scanf("%d", &n);
        free(V);
    }
    return 0;
}