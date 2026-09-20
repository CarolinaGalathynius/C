#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct numeros{
    int numero;
    struct numeros* next;
};

typedef numeros numeros;

struct conjunto{
    int nome;
    numeros* numero;
    struct conjunto* prox;
};

typedef conjunto conjunto;

void criar_conjunto_vazio(int i, conjunto** p){
    conjunto* novo = malloc(sizeof(conjunto));
    novo -> nome = i;
    novo->prox = *p;
    *p = novo;
}

void encontrar_nome(char V[], int x){
    V[0] = 'C';
    sprintf(&V[1], "%d", x);
}

void remover_elementos(){

}

void computar_uniao(){

}

void atribuir_uniao(){
    
}

void computar_intersecao(){

}

void atribuir_intersecao(){
    
}

void computar_diferenca(){

}

void atribuir_diferenca(){
    
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

bool in_lista_encadeada(conjunto *L1, int number){
    // AQUI POSSO TER UM PROBLEMA
    // NÃO SEI SE ESTOU ACESSANDO CORRETAMENTE A LISTA ENCADEADA DE NÚMEROS DO CONJUNTO
    int num;
    num = L1 -> numero -> numero;
    numeros* apoio = L1 -> numero -> next;
    while(num != NULL){
        if(num == number){
            return true;
        }
        apoio = apoio -> next;
        num = apoio -> numero;
    }
    return false;
}

void imprimir_conjunto(){
    char nome[5];
}

int main(void){
    char caractere;
    scanf("%c", &caractere);
    while(caractere =! 't'){
        if(caractere == 'c'){

        } else if(caractere == 'i'){
            
        } else if(caractere == 'r'){
            // Remove elementos do conjunto j
            
        } else if(caractere == 'u'){
            // Atribui uma união a um conjunto
            
        } else if(caractere == 'n'){
            // Atribui uma interseção a um conjunto
            
        } else if(caractere == 'm'){
            // Atribui uma diferença a um conjunto
            
        } else if(caractere == 'e'){
            // Imprime se um elemento está em um conjunto
            
        } else{
            // Imprime os elementos de um conjunto em ordem crescente

        }
        scanf("%c", &caractere);
    }
    return 0;
}