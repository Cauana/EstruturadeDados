def ordenacao_insercao_livros(lista_livros):
    for i in range(1, len(lista_livros)):
        livro_atual = lista_livros[i]
        j = i - 1
        while j >= 0 and livro_atual < lista_livros[j]:
            lista_livros[j + 1] = lista_livros[j]
            j -= 1
        lista_livros[j + 1] = livro_atual




if __name__ == "__main__":

    nomes = ["A Bela e a Fera", "Hidadesy Potter", "Dom Quixote", "1984", "A Máquina do Tempo"]

    ordenacao_insercao_livros(nomes)

    print("\nLista de livros ordenada por inserção:")
    for livro in nomes:
        print(livro)
