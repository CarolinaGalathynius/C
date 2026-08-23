#include<stdio.h>
#include<math.h>

/*Dados os vetores R e S, os índices i e j, que indicam, 
respectivamente, onde a soma em S começa e termina, 
utiliza todas as somas possíveis de elementos de R e, em
 seguida, completa o que falta com os elementos 
 correspondentes de S.*/
void soma(S, R, i, j, r){
    int s=0;
    int indice_maior, indice_menor;
    indice_maior = floor((j/r)-1);
    indice_menor = ceil((i/r)-1);
    for(int k=indice_menor; k<=indice_maior; k++){
        s = s + R[k];
    }
    for(i, i<indice_menor, i++){
        s = s + S[k];
    }
    for(indice_maior+1, indice_maior<=j, indice_maior++){
        s = s + S[indice_maior];
    }
    printf("%d", s);   
}

/*Substitue um elemento em S e depois atualiza a soma
da qual ele participava em R.*/
void substituicao(S, R, i, x, n, r){
    R[int(n/r)] = R[int(n/r)] - S[i] + x;
    S[i] = x;
}

int main(void){
    int n;
    scanf("%d", &n);
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d", &S[i]);
    }
    int r;
    r = sqrt(n);
    int R[int(n/r)+1];
    while (scanf("%s %d %d", &letra, &i, &k) != EOF) {
        if(letra=='a'){
            substituicao(S, R, i, k, n, r)
        }
        else{
            soma(S, R, i, j, r)   
        }
    }
}