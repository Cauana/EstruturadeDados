def merge_sort_documentos(lista_documentos):
    if len(lista_documentos) > 1:
        meio = len(lista_documentos) // 2  
        metade_esquerda = lista_documentos[:meio] 
        metade_direita = lista_documentos[meio:]

        merge_sort_documentos(metade_esquerda) 
        merge_sort_documentos(metade_direita) 


        i = j = k = 0

        while i < len(metade_esquerda) and j < len(metade_direita):
            if metade_esquerda[i] < metade_direita[j]:
                lista_documentos[k] = metade_esquerda[i]
                i += 1
            else:
                lista_documentos[k] = metade_direita[j]
                j += 1
            k += 1

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


