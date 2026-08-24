#include <stdio.h>
#include <math.h>

void soma(int S[], int R[], int i, int j, int r) {
    int s = 0;
    float jota, iii, erre;
    int indice_maior, indice_menor;
    jota = j;
    iii = i;
    erre = r;

    indice_maior = ceil(jota / erre)-1;
    indice_menor = floor(iii / erre)+1;

    if(indice_maior!=indice_menor){
        for (int k = indice_menor; k <= indice_maior; k++) {
            s = s + R[k];
        }

        for (int k=i; k < indice_menor*5; k++) {
            s = s + S[k];
        }

        for (int k = (indice_maior+1)*5; k <= j; k++) {
            s = s + S[k];
        }
    }
    else{
        for(int k=i; k<=j; k++){
            s = s + S[k];
        }
    }
    printf("%d\n", s);
}

void substituicao(int S[], int R[], int i, int x, int n, int r) {
    R[i / r] = R[i / r] - S[i] + x;
    S[i] = x;
}

int main(void) {
    int n;

    scanf("%d", &n);
    float num;
    num = n;

    int S[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int r;
    float rrr;

    r = ceil(sqrt(n));

    rrr = r;

    int R[r], contador = 0, total = 0, extra = 0, treco;

    treco = ceil(num/rrr);
    for (int i = 0; i < n; i++) {
        if (contador < treco) {
            total = total + S[i];
            contador++;
            if(i==(n-1)){
                R[extra] = total;
            }
        }
        else {
            R[extra] = total;
            extra++;
            total = S[i];
            contador = 1;
            if(i==(n-1)){
                R[extra] = total;
            }
        }
    }

    char letra;
    int i, k;

    while (scanf(" %c %d %d", &letra, &i, &k) != EOF) {

        if (letra == 'a') {
            substituicao(S, R, i, k, n, r);
        }
        else {
            soma(S, R, i, k, r);
        }
    }

    return 0;
}