#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*Quado percorrer a frase, vai encontrando dígitos grudados.
Depois de encontrar todos os dígitos grudados (até cinco), 
é preciso transformá-los de char para int. Essa função faz isso
e retorna um inteiro.*/
int converter_int(char v[]){
     int tamanho = sizeof(v)/sizeof(v[0]); //Número de bytes total do vetor pelo de um único elemento
     numero = 0;
     for(int i=0; i<tamanho; i++){
          numero = (numero*10)+(v[i]-'0') //Tirando o 0, obtenho exatamente o número na tabela ASCII
     }
     return numero;
}

bool operador_in(char v[], )

int main(void){
     int numero, indice = 0;
     char frase[20000];
     char numeros['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'], novo_numero[5];
     char char_especiais[]
     char nova_frase[30000];
     while(frase[indice] != '/0'){
          if(operador_in(char_especiais, frase[indice])==True){
               continue;
          }
          else{
               /*Aqui vamos separar no caso espaço, caso dígitos,
               caso começo de palavra com vogal, o com consoante e 
               tal*/
          }
          indice++;
     }
     if(numero!=1){
          printf("%d goat say: ", numero);
     }
     else{
          printf("%d goats say: ", numero);
     }

}