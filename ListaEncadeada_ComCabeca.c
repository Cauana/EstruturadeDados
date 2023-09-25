#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Celula {
    int conteudo;
    struct Celula *proximo;
} celula;

void inserirInicio(celula *cabeca, int cont) {
    celula *novo = (celula *)malloc(sizeof(celula));
    novo->conteudo = cont;

    novo->proximo = cabeca->proximo;
    cabeca->proximo = novo;
}

void imprimir_contar(celula *cabeca) {
    celula *aux = cabeca->proximo;
    int contador = 0;
    while (aux != NULL) {
        printf("%d->", aux->conteudo);
        contador++;
        aux = aux->proximo;
    }
    printf("\nNº de itens na lista: %d\n", contador);
}

void localizar(celula *cabeca, int x) {
    celula *aux = cabeca->proximo;
    while (aux != NULL) {
        if (aux->conteudo == x) {
            printf("\nFoi encontrado o %d\n", aux->conteudo);
            return; 
        }
        aux = aux->proximo;
    }
    printf("\n%d não encontrado na lista.\n", x);
}

void remover(celula *cabeca, int x) {
    celula *atual = cabeca->proximo;
    celula *anterior = cabeca;

    while (atual != NULL && atual->conteudo != x) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", x);
        return;
    }
    anterior->proximo = atual->proximo;
    free(atual);
    printf("\nElemento %d removido da lista.\n", x);
}

int main() {
    celula cabeca;
    cabeca.proximo = NULL;
    inserirInicio(&cabeca, 1);
    inserirInicio(&cabeca, 2);
    inserirInicio(&cabeca, 3);
    imprimir_contar(&cabeca);
    localizar(&cabeca, 2);
    remover(&cabeca, 2);
    imprimir_contar(&cabeca);
    
    return 0;
}





