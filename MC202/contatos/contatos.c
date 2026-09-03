#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*Cria uma struct chamadad "Contato" que 
armazena nome, endereco, telefone e
aniversario de alguém.*/
typedef struct{
    char nome[51];
    char endereco[101];
    long long telefone;
    char aniversario[9];
} Contato;

// Função para inserir um novo contato no vetor
void inserir(char nome[51], char endereco[101], long long telefone, char aniversario[9], Contato contatos[1001], int tamanho){
    strcpy(contatos[tamanho].nome, nome);
    strcpy(contatos[tamanho].endereco, endereco);
    contatos[tamanho].telefone = telefone;
    strcpy(contatos[tamanho].aniversario, aniversario);
    printf("Contato para %s inserido.\n\n", nome);
}

// Função para remover contatos no vetor
int remover(char nome[51], int tamanho, Contato contatos[1001]){
    int contador = 0;
    int i = 0;
    for(int k=0; k < tamanho; k++){
        if(strcmp(contatos[k].nome, nome) == 0){
            contador++;
        }
        else{
            contatos[i] = contatos[k];
            i++;
        }
    }
    printf("Contatos de %s removidos: %d.\n\n", nome, contador);
    return contador;
}

// Função para buscar contatos no vetor
void busca(char nome[51], int tamanho, Contato contatos[1001]){
    printf("Resultado da busca:\n");
    bool encontrado = false;
    int numero;
    for(int i = 0; i < tamanho; i++){
        numero = i + 1;
        if(strstr(contatos[i].nome, nome) != NULL){
            printf("(%d) %s\t%s\t%lld\t%s\n\n", numero, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].aniversario);
            encontrado = true;
        }
    }
    if(encontrado == false){
        printf("Nenhum contato.\n\n");
    }
}

// Imprime todos os contatos do vetor
void impressao(int tamanho, Contato contatos[1001]){
    int numero;
    printf("Listagem:\n");
    for(int i =0; i < tamanho; i++){
        numero = i + 1;
        printf("(%d) %s\t%s\t%lld\t%s\n\n", numero, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].aniversario);
    }
}

int main(void){
    Contato contatos[1001];
    char nome[51], endereco[101], aniversario[9], operacao;
    long long telefone;
    int i = 0; 
    int excluidos = 0;

    while(scanf(" %c", &operacao) == 1){
        if(operacao == 'i'){
            scanf(" %50[^\n]", nome);
            scanf(" %100[^\n]", endereco);
            scanf(" %lld", &telefone); 
            scanf(" %8[^\n]", aniversario);
            inserir(nome, endereco, telefone, aniversario, contatos, i);
            i++;
        }
        else if(operacao == 'r'){
            scanf(" %50[^\n]", nome);
            excluidos = remover(nome, i, contatos);
            i -= excluidos;
        }
        else if(operacao == 'b'){
            scanf(" %50[^\n]", nome);
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