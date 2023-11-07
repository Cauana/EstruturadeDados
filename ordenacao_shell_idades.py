

def ordenacao_shell(alturas):
    divisao = len(alturas) // 2
    while divisao > 0:
        for i in range(divisao, len(alturas)):
            temp = alturas[i]
            j = i
            while j >= divisao and alturas[j - divisao] > temp:
                alturas[j] = alturas[j - divisao]
                j -= divisao
            alturas[j] = temp
        divisao //= 2


if __name__ == "__main__":

    alturas = [1.50,1.45,2.0,1.65,1.70,1.80,1.43,1.58,1.90,1.75,1.83]
    ordenacao_shell(alturas)
    print(alturas)

