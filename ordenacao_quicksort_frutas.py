def quicksort_frutas_por_quantidade(frutas):
    if len(frutas) <= 1:
        return frutas
    else:
        pivot = frutas[0]  # Escolher o primeiro elemento como pivô
        menores = [fruta for fruta in frutas[1:] if fruta[1] <= pivot[1]]
        maiores = [fruta for fruta in frutas[1:] if fruta[1] > pivot[1]]

        return quicksort_frutas_por_quantidade(menores) + [pivot] + quicksort_frutas_por_quantidade(maiores)

if __name__ == "__main__":

    frutas = [("Maçã", 10), ("Banana", 5), ("Uva", 20), ("Abacaxi", 15), ("Pera", 8)]
    frutas_ordenadas = quicksort_frutas_por_quantidade(frutas)
    print("Frutas ordenadas por quantidade:", frutas_ordenadas)
