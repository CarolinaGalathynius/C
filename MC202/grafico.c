#include<stdio.h>

int descobrir_digitos(int n){
    int contador = 0;
    if(n==0){
        return 1;
    }
    while(n>0){
        n = n/10;
        contador++;
    }
    return contador;
}

void imprimir_dados(int n[], int f[], char c[], int controle, int digitos){
    for(int i=0; i<controle; i++){
        /*Colocar um asterisco no d define a largura do campo dinamicamente
        a partir de uma variável que, nesse caso, é o número de dígitos do 
        maior n.*/
        printf("%*d |", digitos, n[i]);
        for(int k=0; k<f[i]; k++){
            putchar(c[i]);
        }
        printf(" %d\n", f[i]);
    }    
}

int main(void){
    char c[100];
    int n[100], f[100], controle = 0, max_n = 0;

    /*Lê todas as triplas e encontra o maior n, para
    que seja possível alinhá-las conforme é feito nos
    exemplos de saída.*/
    while(scanf(" (%d,%d,%c)", &n[controle], &f[controle], &c[controle]) == 3){
        if(n[controle]>max_n){
            max_n = n[controle];
        }
        controle++;
    }
    
    /*Descobre quantos dígitos tem o maior n*/
    int digitos;
    digitos = descobrir_digitos(max_n);

    /*Imprime os dados*/
    imprimir_dados(n, f, c, controle, digitos);

    return 0;
}