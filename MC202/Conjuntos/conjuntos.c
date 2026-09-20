#include<stdio.h>
#include<stdlib.h>

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

void imprimir_esta(){
    
}

void imprimir_conjunto(){
    
}

int main(void){
    char caractere;
    scanf("%c", &caractere);
    while(caractere =! 't'){
        if(caractere == 'c'){

        } else if(caractere == 'i'){
            // Cria o conjunto vazio i

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