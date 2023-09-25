#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SenhaAtendimento {
    int senha;
    struct SenhaAtendimento *proximo;
} SenhaAtendimento;

void inserir(SenhaAtendimento **comeco, SenhaAtendimento **fim, int cont) {
    SenhaAtendimento *novo = (SenhaAtendimento*)malloc(sizeof(SenhaAtendimento));

    novo->senha = cont;
    novo->proximo = NULL;

    if (*comeco == NULL) {
        *comeco = novo;
        *fim = novo;
    } else {
        (*fim)->proximo = novo;
        *fim = novo;
    }
}

void remover(SenhaAtendimento **comeco) {
    SenhaAtendimento *remover = *comeco;

    if (remover != NULL) {
        *comeco = remover->proximo;
        free(remover);
    } else {
        printf("Lista vazia!\n");
    }
}

void imprimir(SenhaAtendimento **comeco) {
    SenhaAtendimento *aux = *comeco;

    if (aux == NULL) {
        printf("Lista vazia\n");
        return;
    }

    while (aux != NULL) {
        printf("%d->", aux->senha);
        aux = aux->proximo;
    }
    printf("\n");
}

int main() {
    SenhaAtendimento *comeco = NULL;
    SenhaAtendimento *fim = NULL;

    inserir(&comeco, &fim, 1);
    inserir(&comeco, &fim, 2);
    inserir(&comeco, &fim, 3);
    inserir(&comeco, &fim, 4);
    imprimir(&comeco);

    remover(&comeco);
    remover(&comeco);
    imprimir(&comeco);
    remover(&comeco);
    remover(&comeco);
    imprimir(&comeco);

    inserir(&comeco, &fim, 5);
    inserir(&comeco, &fim, 6);
    inserir(&comeco, &fim, 7);
    inserir(&comeco, &fim, 8);
    imprimir(&comeco);

    return 0;
}
