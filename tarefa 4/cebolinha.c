#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA 50

int comprimento_str(char string[]) {
    int comprimento = 0;
    while (string[comprimento] != '\0') {
        comprimento += 1;
    }
    return comprimento;
}

void cebolinhar(char palavra[], char palavla[]) {
    int i, j, contador;
    i = comprimento_str(palavra) - 1;  
    j = 0;   
    contador = 0;                          
    for(j=0; j<=i; j++){
        if (palavra[j] == 'R'){
            if (j==0 || palavra[j-1] != 'R'){
                palavla[contador] = 'L';
                contador += 1;
            }
        }
        else if (palavra[j] != 'R'){
            palavla[contador] = palavra[j];
            contador+=1;
        }
    }
    palavla[contador] = '\0';
}

int main() {
    char palavra[MAX_PALAVRA];
    char palavla[MAX_PALAVRA];

    scanf("%s", palavra);

    cebolinhar(palavra, palavla);

    printf("%s\n", palavla);
}