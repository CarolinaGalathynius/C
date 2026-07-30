def encontrar_tempo(velocidade):
    '''
    Encontra o tempo que a lesma corre, dada
    sua velocidade.
    '''
    if velocidade<=10:
        return 3
    elif velocidade<=20:
        return 2
    elif velocidade<=100:
        return 1
    else:
        return 0

def encontrar_maxima(duracao, lista_lesmas):
    '''
    Encontra a lesma mais rápida que pode competir em uma maratona
    de certa duração.
    '''
    quantidade_lesmas = len(lista_lesmas)
    lesma_rapida = 0
    for i in range(quantidade_lesmas):
        tempo_controle = encontrar_tempo(lista_lesmas[i])
        if tempo_controle>=duracao and lista_lesmas[i]>lesma_rapida:
            lesma_rapida = lista_lesmas[i]
    return lesma_rapida

def main():
    n = int(input())

    lista_lesmas = []
    for i in range(n):
        lista_lesmas.append(int(input()))

    duracao = int(input())

    velocidade_maxima = encontrar_maxima(duracao, lista_lesmas)

    print(int(velocidade_maxima))
main()