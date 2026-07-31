def main():
    palavra = input()
    palavla = ""
    for i in range(len(palavra)):
        if palavra[i] == "R":
            if i==0 or palavra[i-1] != "R":
                palavla = palavla + "L"
        elif palavra[i] != "R":
            palavla = palavla + palavra[i]
    print(palavla)
main()