#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "funcoes_auto.h"


/**
Coloca uma nova folha na árvore.
**/
/*
dicionario* df_alloc(char palavra[], long frequencia) {
    dicionario* D = (dicionario*)malloc(sizeof(dicionario));
    if(D == NULL){
        return NULL;
    }
    strcpy(D -> palavra, palavra);

    D -> frequencia = frequencia;

    D -> left = NULL;
    D -> right = NULL;

    return D;
}
*/



/**
Libera a memória alocada dinamicamente para o dicionário.
**/
void df_free(dicionario* D){
    if (D == NULL){
        return;
    }

    df_free(D->left);
    df_free(D->right);

    if (D->palavra != NULL){
        free(D->palavra);
    }
    free(D);
}


/**
    Adiciona a palavra w com frequência f a sua devida posição no dicionário.
**/
int df_insert(dicionario* head, char x[1000], long f) {
    bool aqui = false;
    int k = 0;
    dicionario* novo;
    dicionario* apoio = head;
    while(aqui == false){
        int a = apoio->palavra[k];
        int b = x[k];
        while(b==a && k<=strlen(apoio->palavra) && k<=strlen(x)){
            k++;
            int a = apoio->palavra[k];
            int b = x[k];
        }
        if(b>a || a==b && strlen(apoio->palavra)<strlen(x)){
            if(apoio->right!=NULL){
                apoio = apoio->right;
            } else {
                apoio -> right = novo;
                strcpy(novo -> palavra, x);
                novo -> frequencia = f;
                novo -> right = NULL;
                novo -> left = NULL;
                aqui = true;
            }
        } else if(a>b || a==b && strlen(apoio->palavra)>strlen(x)){
            if(apoio->left!=NULL){
                apoio = apoio->left;
            } else {
                apoio -> left = novo;
                strcpy(novo -> palavra, x);
                novo -> frequencia = f;
                novo -> right = NULL;
                novo -> left = NULL;
                aqui = true;
            }
        } else if(a==b && strlen(apoio->palavra)==strlen(x)){
            apoio -> frequencia = f;
            aqui = true;
        } 
    }
    return 1;
}

/*Imprime a palavra x e sua frequência. Se não houver a 
palavra no dicionário, imprime uma mensagem de erro.*/
int df_search(dicionario* head, char x[1000]) {
    dicionario* suporte = head;

    while (suporte != NULL) {
        int cmp = strcmp(x, suporte->palavra);

        if (cmp == 0) {
            printf("%s %d\n", x, suporte->frequencia);
            return 1;
        }
        else if (cmp > 0) {
            suporte = suporte->right;
        }
        else {
            suporte = suporte->left;
        }
    }

    printf("%s not found.\n", x);
    return 0;
}

/*
Dados dois vetores V e U (V com as palavras e U com
as frequências) ordena-os da maior para a menor
frequência, levando em conta que informações que
originalmente estavam em índices iguais nos dois vetores
devem permanecer em índices iguais.
*/
void ordenar_matriz(char V[], int U[]){

}

/*
Primeiro, procura todas as palavras no dicionário com o
prefixo x e as armazena em um vetor V, nos mesmos 
índices em que suas frequências serão armazenadas em U. 
Depois, usa a função ordenar_matriz para colocá-los na
ordem em que deverão ser impressos e, por fim, imprime a
saída.
*/
int df_autocomplete(dicionario* head, char x[1000], long k){
    // TERMINAR
    dicionario* suporte = head;
    char V[1000];
    int U[1000];

    while (suporte != NULL) {
        int cmp = strcmp(x, suporte->palavra);

        if (cmp == 0) {
            printf("%s %d\n", x, suporte->frequencia);
            return 1;
        }
        else if (cmp > 0) {
            suporte = suporte->right;
        }
        else {
            suporte = suporte->left;
        }
    }

    printf("nothing for %s.\n", x);
    return 0;
}

/*
Remover a palavra x do dicionário. Se x não estiver no 
dicionário então o programa não faz nada.
*/
int df_delete(dicionario* head, char x[1000]){
    dicionario* suporte = head;
    dicionario* suporte_atras = head;

    while (suporte != NULL) {
        int cmp = strcmp(x, suporte->palavra);

        if (cmp == 0) {
            // COLOCAR AQUI A REMOÇÃO
            return 1;
        }
        else if (cmp > 0) {
            suporte_atras = suporte;
            suporte = suporte->right;
        }
        else {
            suporte_atras = suporte;
            suporte = suporte->left;
        }
    }
    return 0;
}

/*Imprime as palavras no dicionário em ordem lexicográfica, 
em uma única linha.*/
void df_print(dicionario* head){
    dicionario* suporte = head;
    while(suporte->palavra!=NULL){
        df_print(suporte->left);
        printf("(%s, %d) ", &suporte->palavra, &suporte->frequencia);
        df_print(suporte->right);
    }
}