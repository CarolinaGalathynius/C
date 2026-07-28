def executar_operacao(expressao):
    if expressao[1] == "-":
        return float(expressao[0]) - float(expressao[2])
    elif expressao[1] == "+":
        return float(expressao[0]) + float(expressao[2])
    elif expressao[1] == "*":
        return float(expressao[0])*float(expressao[2])
    else:
        return float(expressao[0])/float(expressao[2])

def main():
    n = int(input())
    for i in range(n):
        expressao = input().split()
        resultado = executar_operacao(expressao)
        print(f"{resultado:0.1f}")
main()