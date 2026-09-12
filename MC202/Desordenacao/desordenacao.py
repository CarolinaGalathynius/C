
def medir_desordenacao(cadeia):
    desordenacao = 0
    for i in range(len(cadeia)):
        for k in range(i+1, len(cadeia)):
            if cadeia[i]>cadeia[k]:
                desordenacao += 1
    return desordenacao 

def ordenar(cadeia):
    cadeia_ordenada = sorted(cadeia)
    return cadeia_ordenada

def main():
    c = int(input())
    for i in range(c):
        desordenacoes = []
        espaco = input()
        j, k = map(int, input().split())
        cadeias = [None] * k
        for a in range(k):
            cadeias[a] = input().strip()
            desordenacao = medir_desordenacao(cadeias[a])
            desordenacoes.append(desordenacao)
        des_ordenadas = sorted(desordenacoes)
        visitei = [0] * k
        for a in range(k):
            b = 0
            while desordenacoes[b] != des_ordenadas[a] or visitei[b]==1:
                b+=1
            visitei[b] = 1
            print(f"{cadeias[b]}")
        print()
main()