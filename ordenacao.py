def ordenacao_selecao_livros(lista_livros):
    for i in range(len(lista_livros)):
        menor = i
        for j in range(i + 1, len(lista_livros)):
            if lista_livros[j] < lista_livros[menor]:
                menor = j

        lista_livros[i], lista_livros[menor] = lista_livros[menor], lista_livros[i]


def ordenacao_insercao_livros(lista_livros):
    for i in range(1, len(lista_livros)):
        livro_atual = lista_livros[i]
        j = i - 1
        while j >= 0 and livro_atual < lista_livros[j]:
            lista_livros[j + 1] = lista_livros[j]
            j -= 1
        lista_livros[j + 1] = livro_atual


def ordenacao_shell(arr):
    divisao = len(arr) // 2
    while divisao > 0:
        for i in range(divisao, len(arr)):
            temp = arr[i]
            j = i
            while j >= divisao and arr[j - divisao] > temp:
                arr[j] = arr[j - divisao]
                j -= divisao
            arr[j] = temp
        divisao //= 2




if __name__ == "__main__":
    nomes = ["A Bela e a Fera", "Harry Potter", "Dom Quixote", "1984", "A Máquina do Tempo"]
    
    print("Lista de livros não ordenada:")
    for livro in nomes:
        print(livro)

    ordenacao_selecao_livros(nomes)

    print("\nLista de livros ordenada por seleção:")
    for livro in nomes:
        print(livro)


    nomes = ["A Bela e a Fera", "Harry Potter", "Dom Quixote", "1984", "A Máquina do Tempo"]

    ordenacao_insercao_livros(nomes)

    print("\nLista de livros ordenada por inserção:")
    for livro in nomes:
        print(livro)


    nomes = ["A Bela e a Fera", "Harry Potter", "Dom Quixote", "1984", "A Máquina do Tempo"]
    ordenacao_shell(nomes)
    for livro in nomes:
        print(livro)



