

def ordenacao_shell(idades):
    divisao = len(idades) // 2
    while divisao > 0:
        for i in range(divisao, len(idades)):
            temp = idades[i]
            j = i
            while j >= divisao and idades[j - divisao] > temp:
                idades[j] = idades[j - divisao]
                j -= divisao
            idades[j] = temp
        divisao //= 2


if __name__ == "__main__":

    idades = [60,30,20,10,40,70,50,80]
    ordenacao_shell(idades)
    print(idades)

