

def ordenacao_shell(alturas):
    divisao = len(alturas) // 2
    print(divisao)
    while divisao > 0:
        for i in range(divisao, len(alturas)):
            temp = alturas[i]
            j = i
            while j >= divisao and alturas[j - divisao] > temp:
                alturas[j] = alturas[j - divisao]
                j -= divisao
                # print(alturas)
            alturas[j] = temp
            print(alturas)
        divisao //= 2
        print(divisao)


if __name__ == "__main__":

    alturas = [1.50,1.45,2.0,1.65,1.70,1.80,1.43]
    ordenacao_shell(alturas)
    print(alturas)

