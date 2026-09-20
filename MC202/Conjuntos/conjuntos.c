#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct numeros{
    int numero;
    struct numeros* next;
};

typedef struct numeros numeros;

struct conjunto{
    int nome;
    numeros* numero;
    struct conjunto* prox;
};

typedef struct conjunto conjunto;

bool in_lista_encadeada(conjunto *L1, int number){
    numeros* apoio = L1 -> numero;
    while(apoio != NULL){
        if(apoio -> numero == number){
            return true;
        }
        apoio = apoio -> next;
    }
    return false;
}

conjunto* encontrar_apontador(conjunto* p, int i){
    conjunto* apontador = p;
    while(apontador != NULL && apontador->nome != i){
        apontador = apontador -> prox;
    }
    return apontador;
}

void preencher_conjunto(conjunto* c, int V[], int tamanho){
    numeros* apoio = c->numero;
    while(apoio != NULL){
        numeros* prox = apoio->next;
        free(apoio);
        apoio = prox;
    }
    c->numero = NULL;
    for(int b=tamanho-1; b>=0; b--){
        numeros* novo = malloc(sizeof(numeros));
        novo->numero = V[b];
        novo->next = c->numero;
        c->numero = novo;
    }
}

int ordenar_vetor_int(const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}

void criar_conjunto_vazio(int i, conjunto** p){
    conjunto* existente = encontrar_apontador(*p, i);
    if(existente != NULL){
        preencher_conjunto(existente, NULL, 0);
        return;
    }
    conjunto* novo = malloc(sizeof(conjunto));
    novo -> nome = i;
    novo -> numero = NULL;
    novo->prox = *p;
    *p = novo;
}

void encontrar_nome(char V[], int x){
    V[0] = 'C';
    sprintf(&V[1], "%d", x);
}

void inserir_elementos(conjunto* p, int x){
    // Insere elementos em numeros já em ordem crescente
    bool ja_esta = in_lista_encadeada(p, x);
    if(ja_esta == false){
        numeros* apoio1 = p->numero;
        numeros* apoio2 = NULL;
        while(apoio1 != NULL && apoio1->numero < x){
            apoio2 = apoio1;
            apoio1 = apoio1 -> next;
        }
        numeros* novo = malloc(sizeof(numeros));
        novo -> numero = x;
        novo -> next = apoio1;
        if(apoio2 == NULL){
            p->numero = novo;
        } else {
            apoio2 -> next = novo;
        }
    }
}

void remover_elementos(conjunto* p, int x){
    bool ja_esta = in_lista_encadeada(p, x);
    if(ja_esta == true){
        numeros* apoio1 = p->numero;
        numeros* apoio2 = NULL;
        while(apoio1->numero < x){
            apoio2 = apoio1;
            apoio1 = apoio1 -> next;
        }
        if(apoio2 == NULL){
            p->numero = apoio1 -> next;
        } else {
            apoio2 -> next = apoio1 -> next;
        }
        free(apoio1);
    }
}

int computar_uniao(conjunto* P, int j, int k, int V[]){
    int tamanho = 0;
    conjunto *a, *b;
    a = encontrar_apontador(P, j);
    b = encontrar_apontador(P, k);
    numeros *A, *B;
    A = a -> numero;
    B = b -> numero;
    while(A != NULL || B != NULL){
        if(A != NULL && B != NULL){
    conjunto* apontador = P;
            if(A->numero == B->numero){
                V[tamanho] = A->numero;
                tamanho++;
                A = A -> next;
                B = B -> next;
            } else if(A->numero<B->numero){
                V[tamanho] = A->numero;
                tamanho++;
                A = A -> next;
            } else {
                V[tamanho] = B->numero;
                tamanho++;
                B = B -> next;
            }
        } else if(B != NULL){
            V[tamanho] = B->numero;
            tamanho++;
            B = B->next;
        } else{
            V[tamanho] = A->numero;
            tamanho++;
            A = A->next;
        }
    }
    return tamanho;
}

void atribuir_uniao(conjunto* P, int i, int j, int k){
    int *V;
    int tamanho;
    conjunto* con_i;
    V = malloc(10000*sizeof(int));
    con_i = encontrar_apontador(P, i);
    tamanho = computar_uniao(P, j, k, V);
    qsort(V, tamanho, sizeof(int), ordenar_vetor_int);
    preencher_conjunto(con_i, V, tamanho);
    free(V);
}

int computar_intersecao(conjunto* P, int j, int k, int V[]){
    int tamanho = 0;
    conjunto *a, *b;
    a = encontrar_apontador(P, j);
    b = encontrar_apontador(P, k);
    numeros *A, *B;
    A = a -> numero;
    B = b -> numero;
    while(A != NULL && B != NULL){
        if(A->numero == B ->numero){
            V[tamanho] = A->numero;
            tamanho++;
            A = A -> next;
            B = B -> next;
        }else if(A->numero>B->numero){
            B = B->next;
        } else{
            A = A->next;
        }
    }
    return tamanho;
}

void atribuir_intersecao(conjunto* P, int i, int j, int k){
    int *V;
    int tamanho;
    conjunto* con_i;
    V = malloc(10000*sizeof(int));
    con_i = encontrar_apontador(P, i);
    tamanho = computar_intersecao(P, j, k, V);
    qsort(V, tamanho, sizeof(int), ordenar_vetor_int);
    preencher_conjunto(con_i, V, tamanho);
    free(V);
}

int computar_diferenca(conjunto* P, int j, int k, int V[]){
    int tamanho = 0;
    conjunto *a, *b;
    a = encontrar_apontador(P, j);
    b = encontrar_apontador(P, k);
    numeros *A, *B;
    A = a -> numero;
    B = b -> numero;
    while(A != NULL){
        if(B == NULL || B->numero>A->numero){
            V[tamanho] = A->numero;
            tamanho++;
            A = A->next;
        } else if(B->numero==A->numero){
            B = B->next;
            A = A->next;
        } else {
            B = B->next;
        }
    }
    return tamanho;
}

void atribuir_diferenca(conjunto* P, int i, int j, int k){
    int *V;
    int tamanho;
    conjunto* con_i;
    V = malloc(10000*sizeof(int));
    con_i = encontrar_apontador(P, i);
    tamanho = computar_diferenca(P, j, k, V);
    qsort(V, tamanho, sizeof(int), ordenar_vetor_int);
    preencher_conjunto(con_i, V, tamanho);
    free(V);
}

void imprimir_esta(conjunto* L1, int num, int x){
    conjunto* p = L1;
    int nome_c;
    bool encontrado = false;
    char nome[5];
    while(p != NULL){
        nome_c = p->nome;
        if(num == nome_c){
            // Encontramos o conjunto! Agora é verificar se x está dentro dele
            encontrado = in_lista_encadeada(p, x);
            break;
        } else {
            p = p->prox;
        }
    }
    if(encontrado == false){
        printf("%d nao esta em ", x);
        encontrar_nome(nome, num);
        printf("%s\n", nome);
    } else {
        printf("%d esta em ", x);
        encontrar_nome(nome, num);
        printf("%s\n", nome);
    }
}

void imprimir_conjunto(conjunto* P, int x){
    char nome[5];
    conjunto* pointer1;
    encontrar_nome(nome, x);
    pointer1 = encontrar_apontador(P, x);
    printf("%s = {", nome);
    numeros* pointer2;
    pointer2 = pointer1->numero;
    if(pointer2 != NULL){
        while(pointer2 -> next != NULL){
            printf("%d, ", pointer2->numero);
            pointer2 = pointer2->next;
        }
        printf("%d", pointer2->numero);
    }
    printf("}\n");
}

int main(void){
    char caractere;
    scanf(" %c", &caractere);
    conjunto* P = NULL;
    while(caractere != 't'){
        if(caractere == 'c'){
            // Cria o conjunto i vazio
            int i;
            scanf("%d", &i);
            criar_conjunto_vazio(i, &P);
        } else if(caractere == 'i'){
            // Insere elementos no conjunto j
            int j, t;
            conjunto* pointer;
            scanf("%d %d", &j, &t);
            pointer = encontrar_apontador(P, j);
            for(int apoio=0; apoio<t; apoio++){
                int x;
                scanf("%d", &x);
                inserir_elementos(pointer, x);
            }
        } else if(caractere == 'r'){
            // Remove elementos do conjunto j
            int j, t;
            conjunto* pointer;
            scanf("%d %d", &j, &t);
            pointer = encontrar_apontador(P, j);
            for(int apoio=0; apoio<t; apoio++){
                int x;
                scanf("%d", &x);
                remover_elementos(pointer, x);
            }
        } else if(caractere == 'u'){
            // Atribui uma união a um conjunto
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            if(encontrar_apontador(P, i) == NULL) criar_conjunto_vazio(i, &P);
            atribuir_uniao(P, i, j, k);
        } else if(caractere == 'n'){
            // Atribui uma interseção a um conjunto
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            if(encontrar_apontador(P, i) == NULL) criar_conjunto_vazio(i, &P);
            atribuir_intersecao(P, i, j, k);
        } else if(caractere == 'm'){
            // Atribui uma diferença a um conjunto
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            if(encontrar_apontador(P, i) == NULL) criar_conjunto_vazio(i, &P);
            atribuir_diferenca(P, i, j, k);
        } else if(caractere == 'e'){
            // Imprime se um elemento está em um conjunto
            int i, x;
            scanf("%d %d", &i, &x);
            imprimir_esta(P, i, x);
        } else{
            // Imprime os elementos de um conjunto em ordem crescente
            int i;
            scanf("%d", &i);
            imprimir_conjunto(P, i);
        }
        scanf(" %c", &caractere);
    }
    
    while(P != NULL){
        conjunto* prox = P->prox;
        preencher_conjunto(P, NULL, 0);
        free(P);
        P = prox;
    }
    return 0;
}