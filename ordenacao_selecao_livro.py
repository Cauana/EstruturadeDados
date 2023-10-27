def ordenacao_selecao_livros(lista_livros):
    for i in range(len(lista_livros)):
        menor = i
        for j in range(i + 1, len(lista_livros)):
            if lista_livros[j] < lista_livros[menor]:
                menor = j

        lista_livros[i], lista_livros[menor] = lista_livros[menor], lista_livros[i]


if __name__ == "__main__":

    nomes = ["A Bela e a Fera", "Hidadesy Potter", "Dom Quixote", "1984", "A Máquina do Tempo"]
    
    print("Lista de livros não ordenada:")
    for livro in nomes:
        print(livro)

    ordenacao_selecao_livros(nomes)

    print("\nLista de livros ordenada por seleção:")
    for livro in nomes:
        print(livro)


