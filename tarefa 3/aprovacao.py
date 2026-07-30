def montar_medias(quantidade, n):
    lista_medias = []
    for i in range(n):
        notas = input().split()
        media = 0
        for k in range(quantidade):
            media += float(notas[k])
        media = (media/3)
        lista_medias.append(media)
    return lista_medias

def montar_finais(praticas_final, teoricas_final, n):
    notas_finais = []
    for k in range(n):
        media = (praticas_final[k] + teoricas_final[k])/2
        notas_finais.append(media)
    return notas_finais

def mostrar_resultados(notas_finais, praticas_final, teoricas_final, n):
    for i in range(n):
        print(f"{notas_finais[i]:0.1f}")
    print(f"Max P: {max(praticas_final):0.1f}")
    print(f"Max T: {max(teoricas_final):0.1f}")
    soma_p = 0
    soma_t = 0
    for i in range(n):
        soma_p += praticas_final[i]
        soma_t += teoricas_final[i]
    media_praticas = soma_p/n
    media_teoricas = soma_t/n
    print(f"Media P: {media_praticas:0.1f}")
    print(f"Media T: {media_teoricas:0.1f}")

def main():
    n = int(input())
    medias_praticas = montar_medias(3, n)
    medias_teoricas = montar_medias(2, n)
    
    praticas_final = [x*1.1 for x in medias_praticas]

    maximo = max(medias_teoricas)

    teoricas_final = [x*10/maximo for x in medias_teoricas]

    notas_finais = montar_finais(praticas_final, teoricas_final, n)

    mostrar_resultados(notas_finais, praticas_final, teoricas_final, n)

main()