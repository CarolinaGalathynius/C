/**
    Declarações para uma palavra de um dicionário armazenada 
    em um vetor dinâmico.
**/


#ifndef DICIONARIO_H
#define DICIONARIO_H

typedef struct dicionario{

    char *palavra;  // vetor de caracteres que será a minha palavra.
    long frequencia;  // a frequência da palavra.
    dicionario* left; // vem antes na ordem alfabética.
    dicionario* right; // vem depois na ordem alfabética


} dicionario;

dicionario* df_alloc(palavra, frequencia);
void df_free(dicionario* D);

long df_frequencia(dicionario* D);

int df_search(dicionario* D, char x[1000]);
void autocomplete(dicionario* D, char x[1000], long k);

int df_insert(dicionario* D, char x[1000], long f);
int df_delete(dicionario* D, char x[1000]);

void df_print(dicionario* D);

#endif
