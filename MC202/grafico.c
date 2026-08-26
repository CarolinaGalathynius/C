#include<stdio.h>

void imprimir_dados(int n[], int f[], char c[], int controle){
    for(int i=0; i<controle; i++){
        /*Colocar um asterisco no d define a largura do campo dinamicamente
        a partir de uma variável que, nesse caso, é o número de dígitos do 
        maior n.*/
        printf("%4d |", n[i]);
        for(int k=0; k<f[i]; k++){
            putchar(c[i]);
        }
        printf(" %d\n", f[i]);
    }    
}

int main(void){
    char c[1000];
    int n[1000], f[1000], controle = 0, max_n = 0;

    /*Lê todas as triplas e encontra o maior n, para
    que seja possível alinhá-las conforme é feito nos
    exemplos de saída.*/
    while(scanf(" (%d,%d, %c)", &n[controle], &f[controle], &c[controle]) == 3){
        if(n[controle]>max_n){
            max_n = n[controle];
        }
        controle++;
    }
    
    /*Imprime os dados*/
    imprimir_dados(n, f, c, controle);

    return 0;
}