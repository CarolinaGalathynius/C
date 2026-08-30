#include<stdio.h>
#include<stdbool.h>

/*Quado percorrer a frase, vai encontrando dígitos grudados.
Depois de encontrar todos os dígitos grudados (até cinco), 
é preciso transformá-los de char para int. Essa função faz isso
e retorna um inteiro.*/
int converter_int(char v[], int tamanho){
     int numero = 0;
     for(int i=0; i<tamanho; i++){
          numero = (numero*10)+(v[i]-'0'); //Tirando o 0, obtenho exatamente o número na tabela ASCII
     }
     return numero;
}

/*Verifica se o caractere é um dígito*/
bool operador_in_num(char a){
     char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
     for(int i=0; i<10; i++){
          if(a==numeros[i]){
               return true;
          }
     }
     return false;
}

/*Verifica se o caractere é um caractere especial*/
bool operador_in_esp(char a){
     char char_especiais[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~'};
     for(int i=0; i<32; i++){
          if(a==char_especiais[i]){
               return true;
          }
     }
     return false;
}

/*Verifica se o caractere é uma vogal*/
bool operador_in_vogais(char a){
     char vogais[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
     for(int i=0; i<10; i++){
          if(a==vogais[i]){
               return true;
          }
     }
     return false;
}

int main(void){
     int numero = 0, indice = 0, indice1 = 0, indice2 = 0;
     int indice_leitura = 0;
     char frase[100001];
     char novo_numero[5], nova_palavra[2500], palavra_apoio[2500];
     int apoio_num = 0, apoio_palavra = 0;
     char nova_frase[500000];

     while(scanf("%c", &frase[indice_leitura]) != EOF){

          if(frase[indice_leitura] != '\n'){
               indice_leitura++;
          }
          else{
               frase[indice_leitura] = '\0';

               indice = 0;

               while(frase[indice] != '\0'){
                    if(operador_in_num(frase[indice])==true){
                         while(operador_in_num(frase[indice])==true){
                              novo_numero[apoio_num] = frase[indice];
                              indice++;
                              apoio_num++;
                         }
                         numero = numero + converter_int(novo_numero, apoio_num);
                         apoio_num = 0;
                    }
                    else if(operador_in_esp(frase[indice])==true){
                         indice++;
                    }
                    else if(frase[indice]==' ' && frase[indice] != '\0'){
                         indice++;
                    }
                    else if(operador_in_vogais(frase[indice])==true){
                         while(frase[indice]!=' ' && frase[indice] != '\0'){
                              if(operador_in_num(frase[indice])==true){
                                   while(operador_in_num(frase[indice])==true){
                                        novo_numero[apoio_num] = frase[indice];
                                        indice++;
                                        apoio_num++;
                                   }
                                   numero = numero + converter_int(novo_numero, apoio_num);
                                   apoio_num = 0;
                              }
                              else if(operador_in_esp(frase[indice])==true){
                                   indice++;
                              }
                              else{
                                   nova_palavra[apoio_palavra] = frase[indice];
                                   indice++;
                                   apoio_palavra++;
                              }
                         }

                         if(apoio_palavra>0){
                              if(indice1>0){
                                   nova_frase[indice1] = ' ';
                                   indice1++;
                              }

                              nova_palavra[apoio_palavra] = 'm';
                              nova_palavra[apoio_palavra+1] = 'a';

                              for(int k=0; k<apoio_palavra; k++){
                                   nova_palavra[apoio_palavra+2+k] = 'a';
                              }

                              for(int k=0; k<(2*apoio_palavra+2); k++){
                                   nova_frase[indice1] = nova_palavra[k];
                                   indice1++;
                              }
                         }

                         apoio_palavra = 0;
                    }
                    else{
                         while(frase[indice]!=' ' && frase[indice] != '\0'){
                              if(operador_in_num(frase[indice])==true){
                                   while(operador_in_num(frase[indice])==true){
                                        novo_numero[apoio_num] = frase[indice];
                                        indice++;
                                        apoio_num++;
                                   }
                                   numero = numero + converter_int(novo_numero, apoio_num);
                                   apoio_num = 0;
                              }
                              else if(operador_in_esp(frase[indice])==true){
                                   indice++;
                              }
                              else{
                                   nova_palavra[apoio_palavra] = frase[indice];
                                   indice++;
                                   apoio_palavra++;
                              }
                         }

                         if(apoio_palavra>0){
                              if(indice1>0){
                                   nova_frase[indice1] = ' ';
                                   indice1++;
                              }

                              for(int k = 1; k < apoio_palavra; k++){
                                   palavra_apoio[k - 1] = nova_palavra[k];
                              }

                              palavra_apoio[apoio_palavra - 1] = nova_palavra[0];
                              palavra_apoio[apoio_palavra] = 'm';
                              palavra_apoio[apoio_palavra+1] = 'a';

                              for(int k=0; k<apoio_palavra; k++){
                                   palavra_apoio[apoio_palavra+2+k] = 'a';
                              }

                              for(int k=0; k<(2*apoio_palavra+2); k++){
                                   nova_frase[indice1] = palavra_apoio[k];
                                   indice1++;
                              }
                         }

                         apoio_palavra = 0;    
                    }
               }

               nova_frase[indice1] = '\0';

               if(numero==1){
                    printf("%d goat says:", numero);
               }
               else{
                    printf("%d goats say:", numero);
               }

               if(nova_frase[0]!='\0'){
                    printf(" ");
               }

               indice2 = 0;

               while(nova_frase[indice2]!='\0'){
                    printf("%c", nova_frase[indice2]);
                    indice2++;
               }

               printf("\n");

               numero = 0;
               indice = 0;
               indice1 = 0;
               indice2 = 0;
               indice_leitura = 0;
               apoio_num = 0;
               apoio_palavra = 0;
          }
     }

     return 0;
}