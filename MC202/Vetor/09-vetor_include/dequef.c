#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"


/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef* df_alloc(long capacity, double factor) {
   dequef* D = (dequef*)malloc(sizeof(dequef));
   if(D == NULL){
      return NULL;
   }
   else{
      float* V = malloc(capacity * sizeof(float));
      if(V == NULL){
         free(D);
         return NULL;
      }
      D -> data = V;

      D -> first = 0;
      D -> size = 0;

      D -> cap = capacity;
      D -> mincap = capacity;

      D -> factor = factor;

      return D;
   }
}



/**
Release a dequef and its data.
**/
void df_free(dequef* D) {
   free(D -> data);
   free(D);
}



/**
   The size of the deque.
**/
long df_size(dequef* D) {
   long tamanho = D->size;
   return (tamanho);
}



/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x) {
   if(D -> size < D -> cap){
      (D -> data)[(D->first + D->size) % D->cap] = x;
      D -> size = D -> size + 1;
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
            apoio[i] = D->data[(D->first+i)%D->cap];
         }
         free(D->data);
         D -> data = apoio;
         D -> first = 0;
         D -> cap = novacap;
         (D -> data)[D->size] = x;
         D -> size = D -> size + 1;
         return 1;
      }
   }
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