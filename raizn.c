#include <stdio.h>
#include <math.h>

void soma(int S[], int R[], int i, int j, int r) {
    int s = 0;
    int indice_maior, indice_menor;

    indice_maior = ceil((j / r))-1;
    indice_menor = ceil((i / r)+1);

    for (int k = indice_menor; k <= indice_maior; k++) {
        s = s + R[k];
    }

    for (int k=i; k < indice_menor*5; k++) {
        s = s + S[k];
    }

    for (int k = (indice_maior+1)*5; k <= j; k++) {
        s = s + S[k];
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

    int S[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int r;

    r = ceil(sqrt(n));

    int R[r], contador = 0, total = 0, extra = 0;

    for (int i = 0; i < n; i++) {
        if (contador < r) {
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