#include<stdio.h>

int descobrir_digitos(n){
    ...
}

void imprimir_dados(variaveis aqui){
    
}

int main(void){
    char c;
    int n, f;

    /*Lê todas as triplas e encontra o maior n, para
    que seja possível alinhá-las conforme é feito nos
    exemplos de saída.*/

    /*Descobre quantos dígitos tem o maior n*/
    
    /*Imprime os dados*/
    while(scanf(" (%d,%d,%c)", &n, &f, &c) == 3){
        printf("%d | ", n);
        for(int i = 0; i<f; i++){
            putchar(c);
        }
        printf(" %d\n", f);
    }
    return 0;
}