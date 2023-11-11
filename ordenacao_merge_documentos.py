def merge_sort_documentos(lista_documentos):
    if len(lista_documentos) > 1:
        meio = len(lista_documentos) // 2  # Encontrar o meio da lista
        metade_esquerda = lista_documentos[:meio]  # Dividir a lista em duas metades
        metade_direita = lista_documentos[meio:]

        merge_sort_documentos(metade_esquerda)  # Chamada recursiva para a metade esquerda
        merge_sort_documentos(metade_direita)  # Chamada recursiva para a metade direita

        # Inicializar índices para percorrer as duas metades e a lista original
        i = j = k = 0

        # Comparar e mesclar as duas metades
        while i < len(metade_esquerda) and j < len(metade_direita):
            if metade_esquerda[i] < metade_direita[j]:
                lista_documentos[k] = metade_esquerda[i]
                i += 1
            else:
                lista_documentos[k] = metade_direita[j]
                j += 1
            k += 1

        # Adicionar os elementos restantes, se houver, de ambas as metades
        while i < len(metade_esquerda):
            lista_documentos[k] = metade_esquerda[i]
            i += 1
            k += 1

        while j < len(metade_direita):
            lista_documentos[k] = metade_direita[j]
            j += 1
            k += 1


if __name__ == "__main__":

    documentos = ["RG", "CPF", "Cert. de Nascimento", "Ct. de Trabalho", "Título", "CNH", "Passaporte"]
    merge_sort_documentos(documentos)
    print(documentos)


