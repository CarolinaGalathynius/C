#include <stdio.h>
#include <math.h>

void soma(int S[], int R[], int i, int j, int r) {
    int s = 0;
    int indice_maior, indice_menor;

    indice_maior = floor((j / r) - 1);
    indice_menor = ceil((i / r) - 1);

    for (int k = indice_menor; k <= indice_maior; k++) {
        s = s + R[k];
    }

    for (i; i < indice_menor; i++) {
        s = s + S[i];
    }

    for (indice_maior++; indice_maior <= j; indice_maior++) {
        s = s + S[indice_maior];
    }

    printf("%d\n", s);
}

void substituicao(int S[], int R[], int i, int x, int n, int r) {
    R[n / r] = R[n / r] - S[i] + x;
    S[i] = x;
}

int main(void) {
    int n;

    scanf("%d", &n);

    int S[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int r, a;

    r = sqrt(n);
    a = n / r + 1;

    int R[a], contador = 0, total = 0, extra = 0;

    for (int i = 0; i < n; i++) {
        if (contador < r) {
            total = total + S[i];
            contador++;
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