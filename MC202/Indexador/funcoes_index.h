/**
    Declarações para uma palavra de um dicionário armazenada 
    em um vetor dinâmico.
**/


#ifndef DICIONARIO_H
#define DICIONARIO_H

typedef struct index{
    long identificador; 
    char *visibilidade;  
    char *estado;  
    struct dicionario* left; 
    struct dicionario* right; 
} index;

void df_free(dicionario* D);

int df_search(dicionario* D, char x[10000]);
int df_autocomplete(dicionario* D, char x[10000], long k);

int df_insert(dicionario** head, char x[10000], long f);
int df_delete(dicionario** head, char x[10000]);

void df_print(dicionario* D, int k);

#endif