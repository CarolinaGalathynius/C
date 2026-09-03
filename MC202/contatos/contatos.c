#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*Cria um vetor chamado "contatos"
no qual cada elemento é contém
o nome, o endereco, o telefone e o
aniversario de alguém.*/
typedef struct{
    char nome[50];
    char endereco[100];
    char telefone[15];
    char aniversario[8];
} Contato;

// Função para inserir um novo contato no vetor
void inserir(char nome[50], char endereco[100], char telefone[15], char aniversario[8], Contato contatos[1000], int tamanho){
    strcpy(contatos[tamanho].nome, nome);
    strcpy(contatos[tamanho].endereco, endereco);
    strcpy(contatos[tamanho].telefone, telefone);
    strcpy(contatos[tamanho].aniversario, aniversario);
    printf("Contato para %s inserido.\n\n", nome);
}

// Função para remover contatos no vetor
void remover(char nome[50], int tamanho, Contato contatos[1000]){
    int contador = 0;
    for(int i = 0; i < tamanho; i++){
        if(strcmp(contatos[i].nome, nome) == 0){
            contador++;
            for(int j = i; j < tamanho - 1; j++){
                contatos[j] = contatos[j + 1];
            }
            break;
        }
    }
    printf("Contatos de %s removidos: %d.\n\n", nome, contador);
}

// Verifica se o caractere procurado está contido no nome do contato
bool operador_in(char procurado, char nome[50]){
    for(int i = 0; i < strlen(nome); i++){
        if(procurado == nome[i]){
            return true;
        }
    }
    return false;
}

// Função para buscar contatos no vetor
void busca(char nome[50], int tamanho, Contato contatos[1000]){
    printf("Resultado da busca:\n");
    bool encontrado = false;
    int numero;
    for(int i = 0; i < tamanho; i++){
        numero = i + 1;
        if(operador_in(nome[0], contatos[i].nome)){
            printf("(%d) %s\t%s\t%s\t%s\n\n", numero, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].aniversario);
            encontrado = true;
        }
    }
    if(encontrado == false){
        printf("Nenhum contato.\n\n");
    }
}

// Imprime todos os contatos do vetor
void impressao(int tamanho, Contato contatos[1000]){
    int numero;
    printf("Listagem:\n");
    for(int i =0; i < tamanho; i++){
        numero = i + 1;
        printf("(%d) %s\t%s\t%s\t%s\n\n", numero, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].aniversario);
    }
}

int main(void){
    Contato contatos[1000];
    char nome[50], endereco[100], telefone[15], aniversario[8], operacao;
    int i = 0; 

    while(scanf("%c", &operacao)!=EOF){
        if(operacao == 'i'){
            scanf("%s", nome);
            scanf("%s", endereco);
            scanf("%s", telefone);
            scanf("%s", aniversario);
            inserir(nome, endereco, telefone, aniversario, contatos, i);
            i++;
        }
        else if(operacao == 'r'){
            scanf("%s", nome);
            remover(nome, i, contatos);
        }
        else if(operacao == 'b'){
            scanf("%s", nome);
            busca(nome, i, contatos);
        }
        else if(operacao == 'p'){
            impressao(i, contatos);
        }
        else if(operacao == 'f'){
            break;
        }
    }
    return 0;
}