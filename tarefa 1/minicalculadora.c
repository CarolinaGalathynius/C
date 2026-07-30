#include <stdio.h>

int main() {
    float operando1, operando2;
    float resultado;
    int numero;
    int i = 0;
    char operador;

    scanf("%d", &numero);

    for(i==0; i<numero; i++){
    scanf("%f %c %f", &operando1, &operador, &operando2);
    if (operador == '/') {
        resultado = operando1 / operando2;
        printf("%f\n", resultado);
    } 
    else if (operador == '+') {
        resultado = operando1 + operando2;
        printf("%f\n", resultado);
    }else if (operador == '*') {
        resultado = operando1*operando2;
        printf("%f\n", resultado);
    }else if (operador == '-') {
        resultado = operando1 - operando2;
        printf("%f\n", resultado);
    }else {
        printf("Erro: operador não reconhecido\n");
    }
    }
}