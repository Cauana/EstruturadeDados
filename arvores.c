#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

struct No* buscar(struct No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    return buscar(raiz->direita, valor);
}

struct No* encontrarMenorNo(struct No* no) {
    struct No* atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

struct No* remover(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Nó com um filho ou nenhum filho
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct No* temp = encontrarMenorNo(raiz->direita);

        raiz->valor = temp->valor;

        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

void imprimirEmOrdem(struct No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct No* raiz = NULL;

    raiz = inserir(raiz, 5);
    inserir(raiz, 3);
    inserir(raiz, 8);
    inserir(raiz, 1);
    inserir(raiz, 4);

    printf("Arvore em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    int valorBusca = 4;
    struct No* resultadoBusca = buscar(raiz, valorBusca);

    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na arvore.\n", valorBusca);
    } else {
        printf("Elemento %d nao encontrado na arvore.\n", valorBusca);
    }

    int valorRemover = 3;
    raiz = remover(raiz, valorRemover);

    printf("Arvore apos a remocao do elemento %d em ordem: ", valorRemover);
    imprimirEmOrdem(raiz);
    printf("\n");


    return 0;
}
