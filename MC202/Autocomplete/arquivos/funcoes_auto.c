#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "funcoes_auto.h"



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
int df_insert(dicionario** head, char x[1000], long f) {
    dicionario** apoio = head;

    while (*apoio != NULL) {
        int cmp = strcmp(x, (*apoio)->palavra);

        if (cmp == 0) {
            (*apoio)->frequencia = f;
            return 1;
        }
        else if (cmp > 0) {
            apoio = &(*apoio)->right;
        }
        else {
            apoio = &(*apoio)->left;
        }
    }

    dicionario* novo = malloc(sizeof(dicionario));
    if (novo == NULL) return 0;
    novo->palavra = malloc(strlen(x) + 1);
    if (novo->palavra == NULL) {
        free(novo);
        return 0;
    }
    strcpy(novo->palavra, x);
    novo->frequencia = f;
    novo->right = NULL;
    novo->left = NULL;
    *apoio = novo;
    return 1;
}

/*Imprime a palavra x e sua frequência. Se não houver a 
palavra no dicionário, imprime uma mensagem de erro.*/
int df_search(dicionario* head, char x[1000]) {
    dicionario* suporte = head;

    while (suporte != NULL) {
        int cmp = strcmp(x, suporte->palavra);

        if (cmp == 0) {
            printf("%s %ld\n", x, suporte->frequencia);
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
void ordenar_matriz(char* V[], int U[], int n){
    for (int i = 1; i < n; i++) {
        char* palavra_atual = V[i];
        int freq_atual = U[i];
        int j = i - 1;

        while (j >= 0 && U[j] < freq_atual) {
            V[j + 1] = V[j];
            U[j + 1] = U[j];
            j--;
        }
        V[j + 1] = palavra_atual;
        U[j + 1] = freq_atual;
    }
}

/*
Percorre a árvore e armazena em V (palavras) e U (frequências),
nos mesmos índices, todas as palavras com o prefixo x.
*/
void apoio_complete(dicionario* head, char x[1000], char* V[], int U[], int* controle){
    if (head == NULL) return;

    int cmp = strncmp(x, head->palavra, strlen(x));

    if (cmp == 0) {
        apoio_complete(head->left, x, V, U, controle);
        if (*controle < 1000) {
            U[*controle] = head->frequencia;
            V[*controle] = head->palavra;
            (*controle)++;
        }
        apoio_complete(head->right, x, V, U, controle);
    }
    else if (cmp > 0) {
        apoio_complete(head->right, x, V, U, controle);
    }
    else {
        apoio_complete(head->left, x, V, U, controle);
    }
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
    char* V[1000];
    int U[1000];
    int controle = 0;

    apoio_complete(head, x, V, U, &controle);

    if (controle > 0) {
        ordenar_matriz(V, U, controle);
        for (int i = 0; i < controle && i < k; i++) {
            printf("(%s,%d) ", V[i], U[i]);
        }
        printf("\n");
        return 1;
    }

    printf("nothing for %s.\n", x);
    return 0;
}

int df_delete(dicionario** head, char x[1000]){
    dicionario** suporte = head;

    while (*suporte != NULL) {
        int cmp = strcmp(x, (*suporte)->palavra);

        if (cmp == 0) {
            dicionario* removido = *suporte;
            dicionario* substituto;

            if (removido->right == NULL) {
                substituto = removido->left;
            } else {
                substituto = removido->right;
                dicionario* suporte_extra = substituto;
                while (suporte_extra->left != NULL) {
                    suporte_extra = suporte_extra->left;
                }
                suporte_extra->left = removido->left;
            }

            *suporte = substituto;
            free(removido->palavra);
            free(removido);
            return 1;
        }
        else if (cmp > 0) {
            suporte = &(*suporte)->right;
        }
        else {
            suporte = &(*suporte)->left;
        }
    }
    return 0;
}

/*Imprime as palavras no dicionário em ordem lexicográfica, 
em uma única linha.*/
void df_print(dicionario* head, int k){
    if (head == NULL){
        if(k==0){
            printf("the dictionary is empty.");
        }
        return ;
    } 
    k++;
    df_print(head->left, k);
    printf("%s ", head->palavra);
    df_print(head->right, k);
}