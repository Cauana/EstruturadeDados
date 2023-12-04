def merge_sort(inicio, fim, documentos):
    if inicio < fim - 1:
        meio = (inicio + fim) // 2
        merge_sort(inicio, meio, documentos)
        merge_sort(meio, fim, documentos)
        intercala(inicio, meio, fim, documentos)

def intercala(inicio, meio, fim, documentos):
    vet_temp = [0] * (fim - inicio)
    ind_esq = inicio
    ind_dir = meio
    ind_temp = 0

    while ind_esq < meio and ind_dir < fim:
        if documentos[ind_esq] <= documentos[ind_dir]:
            vet_temp[ind_temp] = documentos[ind_esq]
            ind_esq += 1
        else:
            vet_temp[ind_temp] = documentos[ind_dir]
            ind_dir += 1
        ind_temp += 1

    while ind_esq < meio:
        vet_temp[ind_temp] = documentos[ind_esq]
        ind_esq += 1
        ind_temp += 1

    while ind_dir < fim:
        vet_temp[ind_temp] = documentos[ind_dir]
        ind_dir += 1
        ind_temp += 1

    for i in range(len(vet_temp)):
        documentos[inicio + i] = vet_temp[i]






if __name__ == "__main__":

    documentos = ["RG", "CPF", "CERTIDÃO", "TÍTULO", "CNH", "PASSAPORTE"]
    merge_sort(0, len(documentos), documentos)
    print(documentos)



