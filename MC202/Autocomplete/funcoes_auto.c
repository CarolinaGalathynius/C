#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "funcoes_auto.h"


/**
Coloca uma nova folha na árvore.
**/
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



/**
Libera a memória alocada dinamicamente para o dicionário.
**/
void df_free(dicionario* D){
    free(D->palavra);
    free(D);
}


/**
    Adiciona a palavra w com frequência f a sua devida posição no dicionário.
**/
int df_insert(dicionario* head, char x[1000], long f) {
    // FALTA VERIFICAR SE DÁ CERTO CASO X ESTEJA CONTIDO EM 
    // PALAVRA E VICE VERSA.
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
        if(b>a){
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
        } else if(a>b){
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



/**
   Remove a float from the end of D and return it.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   It returns the float removed from D.
   What happens if D is empty before the call?
**/
float df_pop(dequef* D) {
   float retorno;
   retorno = D->data[(D->first + D->size - 1) % D->cap];
   D->size = D->size - 1;

   if (D->size <= D->cap/((D->factor)*(D->factor)) && D->cap > D->mincap){
      long novacap;
      if(D->cap/D->factor>=D->mincap){
         novacap = (long)(D->cap/D->factor);
      } else {
         novacap = D->mincap;
      }
      float* apoio = (float *)malloc(novacap*sizeof(float));
      if(apoio != NULL){
         for(long i=0; i<(D->size); i++){
            apoio[i] = D->data[(D->first+i)%D->cap];
         }
         free(D->data);
         D -> data = apoio;
         D -> first = 0;
         D -> cap = novacap;
      }
   }
   return retorno;
}



/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef* D, float x) {
   // Como o vetor dinâmico é circularizado, first recua uma posição (dando a volta se preciso)
   if(D->size<D->cap){
      D->first = (D->first - 1 + D->cap) % D->cap;
      D->data[D->first] = x;
      D->size = D->size + 1;
      return 1;
   }
   else {
      long novacap = (long)((D -> cap)*(D->factor));
      if(novacap <= D -> cap){
         novacap = D -> cap + 1;
      }
      // Apontador temporário para não perder dados em caso de falha
      float* apoio = (float *)malloc(novacap*sizeof(float));
      if(apoio == NULL){
         return 0;
      } else {
         for(long i=0; i<(D->size); i++){
            apoio[i+1] = D->data[(D->first+i)%D->cap];
         }
         free(D->data);
         D -> data = apoio;
         D -> first = 0;
         D -> cap = novacap;
         D -> size = D -> size + 1;
         (D -> data)[0] = x;
         return 1;
      }
   }
}



/**
   Remove a float from the beginning of D and return it.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   It returns the float removed from D.
   What happens if D is empty before the call?
**/
float df_eject(dequef* D) {
   float retorno;

   retorno = D->data[D->first];
   D->first = (D->first + 1) % D->cap;
   D->size = D->size - 1;

   if (D->size <= D->cap/((D->factor)*(D->factor)) && D->cap > D->mincap){
      long novacap;
      if(D->cap/D->factor>=D->mincap){
         novacap = (long)(D->cap/D->factor);
      } else {
         novacap = D->mincap;
      }
      float* apoio = (float *)malloc(novacap*sizeof(float));
      if (apoio != NULL){
         for(long i=0; i<(D->size); i++){
            apoio[i] = D->data[(D->first+i)%D->cap];
         }
         free(D->data);
         D -> data = apoio;
         D -> first = 0;
         D -> cap = novacap;
      }
   }
   return retorno;
}



/**
   Return D[i].

   If i is not in [0,|D|-1]] what happens then?
**/
float df_get(dequef* D, long i) {
   float valor = 0.0;
   if(i >= 0 && i < D->size){
      valor = D->data[(D->first + i) % D->cap];
   }
   return valor;
}



/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] what happens then?
**/
void df_set(dequef* D, long i, float x) {
   // Muda D[i] para x.
   if(i >= 0 && i < D->size){
      D->data[(D->first + i) % D->cap] = x;
   }
}



/**
   Print the elements of D in a single line.
**/
void df_print(dequef* D) {
   printf("deque (%ld):", D->size);
   for(long i=0; i<D->size; i++){
      printf(" %.1f", D->data[(D->first + i) % D->cap]);
   }
   printf(" \n");
}