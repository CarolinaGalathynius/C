'''
Vou escrever aqui como foi a primeira ideia que surgiu,
só para esse problema não terminar o dia em branco. 

Primeiro, vou criar uma função que procura por letras.
Suas entradas são a palavra completa que está sendo
procurada, o índice da letra que está sendo analisada no
momentoe o lugar na matriz que ela está. Essa é uma função 
recursiva que vai analisando todas as letras até a última
da palavra (não sei se é mais fácil fazer isso com um looping
ou uma recursão). Se der certo e de fato a palavra for 
encontrada, há uma segunda função para criar uma matriz do mesmo 
tamanho da original, mas com pontinhos no lugar de letras para 
todas as posições que não contém a palavra procurada.
'''
def ler_matriz(m):
    matriz = []
    for i in range(m):
        linha = input().split()
        matriz.append(linha.copy())
    return matriz

def construir_matriz_pontos(matriz, posicao, palavra, m, n):
    pass

def imprimir_matriz(matriz, m, n):
    for i in range(m):
        print(*matriz[i])

def main():
    m, n = input().split()
    m = int(m)
    n = int(n)
    matriz = ler_matriz(m)
    num_palavras = int(input())
    palavra = input()
    matriz_nova = construir_matriz_pontos(matriz, posicao, palavra, m, n)
    imprimir_matriz(matriz_nova, m, n)
main()