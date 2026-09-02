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
void inserir(char nome[50], char endereco[100], char telefone[15], char aniversario[8], Contato contatos[1000]){

}

// Função para remover contatos no vetor
void remover(char nome[50]){

}

// Função para buscar contatos no vetor
void busca(char nome[50]){

}

// Imprime todos os contatos do vetor
void impressao(){

}

void main(){
    Contato contatos[1000];
    char nome[50], endereco[100], telefone[15], aniversario[8], operacao;
    int i = 0;

    while(scanf("%c", &operacao)!=EOF){
        if(operacao == 'i'){
            scanf("%s", nome);
            scanf("%s", endereco);
            scanf("%s", telefone);
            scanf("%s", aniversario);
            inserir(nome, endereco, telefone, aniversario, contatos);
        }
        else if(operacao == 'r'){
            scanf("%s", nome);
            remover(nome);
        }
        else if(operacao == 'b'){
            scanf("%s", nome);
            busca(nome);
        }
        else if(operacao == 'p'){
            impressao();
        }
        else if(operacao == 'f'){
            break;
        }
    }
}