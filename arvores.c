#include <stdio.h>
#include <stdlib.h>

struct No {
    int matricula;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(int matricula) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->matricula = matricula;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

struct No* inserir(struct No* raiz, int matricula) {
    if (raiz == NULL) {
        return criarNo(matricula);
    }
    if (matricula < raiz->matricula) {
        raiz->esquerda = inserir(raiz->esquerda, matricula);
    } else if (matricula > raiz->matricula) {
        raiz->direita = inserir(raiz->direita, matricula);
    }
    return raiz;
}

struct No* buscar(struct No* raiz, int matricula) {
    if (raiz == NULL || raiz->matricula == matricula) {
        return raiz;
    }
    if (matricula < raiz->matricula) {
        return buscar(raiz->esquerda, matricula);
    }
    return buscar(raiz->direita, matricula);
}

struct No* encontrarMenorNo(struct No* no) {
    struct No* atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

struct No* remover(struct No* raiz) {
    if (raiz == NULL) {
        return raiz;
    }
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
    raiz->matricula = temp->matricula;
    raiz->direita = remover(raiz->direita);

    return raiz;
}


void imprimirEmOrdem(struct No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->matricula);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct No* raiz = NULL;

    raiz = inserir(raiz, 5582);
    inserir(raiz, 3125);
    inserir(raiz, 8952);
    inserir(raiz, 1123);
    inserir(raiz, 4502);

    printf("Matriculas em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    int matriculaBusca = 3125;
    struct No* resultadoBusca = buscar(raiz, matriculaBusca);

    if (resultadoBusca != NULL) {
        printf("Matricula %d encontrado na arvore.\n", matriculaBusca);
    } else {
        printf("Matricula %d nao encontrado na arvore.\n", matriculaBusca);
    }

    int matriculaRemover = 3125;
    remover(buscar(raiz, matriculaRemover));

    printf("Arvore apos a remocao da matricula %d em ordem: ", matriculaRemover);
    imprimirEmOrdem(raiz);
    printf("\n");


    return 0;
}
