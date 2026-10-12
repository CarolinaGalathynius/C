#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "funcoes_index.h"



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

/*
Obtém a altura de um nó. Usada para evitar receber NULL
ao tentar acessar diretamente a altura de um nó.
*/
int altura(dicionario* palavra) {
    return palavra == NULL ? 0 : palavra->altura;
}

/*
Para facilitar a leitura quando for determinar o
máximo entre dois números.
*/
int max(int a, int b) {
    return a > b ? a : b;
}

/*
Atualizando a altura de um nó
*/
void atualizar(dicionario* palavra) {
    palavra->altura = 1 + max(altura(palavra->left), altura(palavra->right));
}

/*
Calcula o fator de desbalanceamento de um nó
*/
int fator(dicionario* palavra) {
    return altura(palavra->left) - altura(palavra->right);
}

/*
Rotações para a esquerda
*/
dicionario* rot_esq(dicionario* palavra1){
    dicionario* palavra2 = palavra1->right;
    palavra1->right = palavra2->left;
    palavra2->left = palavra1;
    atualizar(palavra1);  
    atualizar(palavra2);
    return palavra2;
}

/*
Rotações para a direita
*/
dicionario* rot_dir(dicionario* palavra1){
    dicionario* palavra2 = palavra1->left;
    palavra1->left = palavra2->right;
    palavra2->right = palavra1;
    atualizar(palavra1);  
    atualizar(palavra2);
    return palavra2;
}

/*
Balanceia o dicionário
*/
dicionario* balancear(dicionario* no) {
    atualizar(no);
    int f = fator(no);

    if (f > 1) {                          
        if (fator(no->left) < 0)          
            no->left = rot_esq(no->left);
        return rot_dir(no);
    }

    if (f < -1) {                       
        if (fator(no->right) > 0)        
            no->right = rot_dir(no->right);
        return rot_esq(no);
    }

    return no;                         
}

/**
Adiciona a palavra w com frequência f a sua devida posição no dicionário.
**/
int df_insert(dicionario** head, char x[10000], long f) {
    if (*head == NULL) {
        dicionario* novo = malloc(sizeof(dicionario));
        if (novo == NULL) return 0;
        novo->palavra = malloc(strlen(x) + 1);
        if (novo->palavra == NULL) {
            free(novo);
            return 0;
        }
        strcpy(novo->palavra, x);
        novo->frequencia = f;
        novo->left = NULL;
        novo->right = NULL;
        novo->altura = 1;
        *head = novo;
        return 1;
    }

    int cmp = strcmp(x, (*head)->palavra);
    if (cmp == 0) {
        (*head)->frequencia = f;
        return 1;
    }

    int r;
    if (cmp < 0) r = df_insert(&(*head)->left, x, f);
    else         r = df_insert(&(*head)->right, x, f);

    *head = balancear(*head);
    return r;
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
Apoio para o qsort
*/
int comparar(const void* a, const void* b) {
    const dicionario* x = *(dicionario* const*) a;
    const dicionario* y = *(dicionario* const*) b;

    if (x->frequencia != y->frequencia) {
        return (y->frequencia > x->frequencia) - (y->frequencia < x->frequencia);
    }
    return strcmp(x->palavra, y->palavra);
}

/*
Percorre a árvore e armazena em V os structs dicionário cuja palavra
tem o prefixo x que está sendo procurado.
*/
void apoio_complete(dicionario* head, char* x, dicionario** V, int* controle) {
    if (head == NULL) return;

    int cmp = strncmp(x, head->palavra, strlen(x));

    if (cmp == 0) {
        apoio_complete(head->left, x, V, controle);
        if (V != NULL) V[*controle] = head;
        (*controle)++;
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
    int n = 0;
    apoio_complete(head, x, NULL, &n);

    if (n == 0) {
        printf("nothing for %s.\n", x);
        return 0;
    }

    dicionario** V = malloc(n * sizeof(dicionario*));
    if (V == NULL) return 0;

    n = 0;
    apoio_complete(head, x, V, &n);

    qsort(V, n, sizeof(dicionario*), comparar);
    for (int i = 0; i < n && i < k; i++)
        printf("(%s,%ld) ", V[i]->palavra, V[i]->frequencia);
    printf("\n");

    free(V);
    return 1;
}

int df_delete(dicionario** head, char x[10000]) {
    if (*head == NULL) return 0;

    dicionario* apoio = *head;
    int cmp = strcmp(x, apoio->palavra);
    int r;

    if (cmp < 0) {
        r = df_delete(&apoio->left, x);
    }
    else if (cmp > 0) {
        r = df_delete(&apoio->right, x);
    }
    else if (apoio->left == NULL || apoio->right == NULL) {
        *head = (apoio->left != NULL) ? apoio->left : apoio->right;
        free(apoio->palavra);
        free(apoio);
        return 1;
    }
    else {
        dicionario* suc = apoio->right;
        while (suc->left != NULL) suc = suc->left;

        char* copia = malloc(strlen(suc->palavra) + 1);
        if (copia == NULL) return 0;
        strcpy(copia, suc->palavra);
        long freq = suc->frequencia;

        r = df_delete(&apoio->right, copia);

        free(apoio->palavra);
        apoio->palavra = copia;
        apoio->frequencia = freq;
    }

    *head = balancear(*head);
    return r;
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