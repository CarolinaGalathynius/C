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
int df_insert(dicionario** head, char x[10000], long f) {
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
int df_search(dicionario* head, char x[10000]) {
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
Devolve quantas palavras tem no dicionário
*/
int contar(dicionario* d) {
    return d == NULL ? 0 : 1 + contar(d->left) + contar(d->right);
}

/*
Apoio para o qsort
*/
int comparar(const void* a, const void* b) {
    const dicionario* p = *(dicionario* const*)a;
    const dicionario* q = *(dicionario* const*)b;

    if (p->frequencia != q->frequencia){
        return (p->frequencia < q->frequencia) ? 1 : -1;
    }

    return strcmp(p->palavra, q->palavra);
}

/*
Percorre a árvore e armazena em V os structs dicionário cuja palavra
tem o prefixo x que está sendo procurado.
*/
void apoio_complete(dicionario* head, char x[10000], dicionario* V[], int* controle) {
    if (head == NULL) return;

    int cmp = strncmp(x, head->palavra, strlen(x));

    if (cmp == 0) {
        apoio_complete(head->left, x, V, controle);
        V[(*controle)++] = head;
        apoio_complete(head->right, x, V, controle);
    }
    else if (cmp > 0) apoio_complete(head->right, x, V, controle);
    else apoio_complete(head->left, x, V, controle);
}

/*
Primeiro, procura todas as palavras no dicionário com o
prefixo x e armazena as structs que as contén em um vetor 
V. Depois, usa qsort para colocá-los na
ordem em que deverão ser impressos e, por fim, imprime a
saída.
*/
int df_autocomplete(dicionario* head, char x[10000], long k) {
    int total = contar(head);               
    dicionario** V = malloc((total > 0 ? total : 1) * sizeof(dicionario*));
    int controle = 0;

    apoio_complete(head, x, V, &controle);

    if (controle > 0) {
        qsort(V, controle, sizeof(dicionario*), comparar);
        for (int i = 0; i < controle && i < k; i++)
            printf("(%s,%ld) ", V[i]->palavra, V[i]->frequencia);
        printf("\n");
        free(V);
        return 1;
    }

    printf("nothing for %s.\n", x);
    free(V);
    return 0;
}

int df_delete(dicionario** head, char x[10000]){
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