def quicksort(idades, inicio, fim):
    if inicio < fim:

        pivot = idades[fim]
        i = inicio - 1

        for j in range(inicio, fim):
            if idades[j] <= pivot:
                i += 1
                idades[i], idades[j] = idades[j], idades[i]

        idades[i + 1], idades[fim] = idades[fim], idades[i + 1]
        p = i + 1

        print(f"\nPivô = {pivot}, Idades = {idades}")

        quicksort(idades, inicio, p - 1)
        quicksort(idades, p + 1, fim)


if __name__ == "__main__":

    lista = [100, 88, 15, 66, 55, 98, 36, 40, 65, 22, 71, 62]
    print("Idades Ínicio:", lista)
    quicksort(lista, 0, len(lista) - 1)
    print("\Idades Ordenadas:", lista)
