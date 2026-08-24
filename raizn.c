#include <stdio.h>
#include <math.h>

/*Soma os elementos de S do índice i ao j, usando o vetor R
para diminuir o número de acessos e operações necessárias.*/
void soma(int S[], int R[], int i, int j, int r) {
    /*Descobre onde começar a acessar R*/
    int indice_menor, indice_maior;
    if(i%r==0){
        indice_menor = i/r;
    }
    else{
        float apoio_i, apoio_r;
        apoio_i = i;
        apoio_r = r;
        indice_menor = floor(apoio_i/apoio_r) + 1;
    }
    if((j+1)%r==0){
        indice_maior = ((j+1)/r) - 1;
    }
    else{
        float apoio_j, apoio_r;
        apoio_j = j;
        apoio_r = r;
        indice_maior = floor(apoio_j/apoio_r)-1;
    }
    int s = 0;
    /*Se for possível acessar R para deixar mais rápido, faz isso
    e obtém a soma.*/
    if(indice_maior>indice_menor){
        for (int k = indice_menor; k <= indice_maior; k++) {
            s = s + R[k];
        }

        for (int k=i; k < indice_menor*r; k++) {
            s = s + S[k];
        }

        for (int k = (indice_maior+1)*r; k <= j; k++) {
            s = s + S[k];
        }
    }
    /*Se não for possível, soma elemento a elemento de S*/
    else{
        for(int k=i; k<=j; k++){
            s = s + S[k];
        }
    }
    
    printf("%d\n", s);
}

/*Troca o valor de S no índice i por um x indicado e faz as alterações
necessárias em R.*/
void substituicao(int S[], int R[], int i, int x, int r) {
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
    float rrr;

    r = ceil(sqrt(n));

    rrr = r;
    int tamanho;

    tamanho = ceil(n/rrr);

    int R[tamanho], contador = 0, total = 0, extra = 0;

    for (int i = 0; i < n; i++) {
        if (contador < tamanho) {
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
            substituicao(S, R, i, k, r);
        }
        else {
            soma(S, R, i, k, r);
        }
    }

    return 0;
}