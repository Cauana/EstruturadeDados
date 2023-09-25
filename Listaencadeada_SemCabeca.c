
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Celula {
    int conteudo;
    struct Celula *proximo;
}celula;

void inserirInicio(celula **lst, int cont){
    
    celula* novo = (celula*)malloc(sizeof(celula));
    novo -> conteudo = cont;
    
    if (*lst == NULL){
        novo -> proximo = NULL;
        *lst = novo;
    }else{  
        novo -> proximo = *lst;
        *lst = novo;
    }
    
}

void imprimir_contar(celula *lst){
    celula *aux;
    aux = lst;
    int contador = 0;
    while(aux!=NULL){
        printf("%d->", aux -> conteudo);
        contador++;
        aux = aux-> proximo;
    }
    printf("\nNumero de itens na lista: %d", contador);
    
}

celula *localizar(celula *lst, int x){
    celula *aux = lst;

    while (aux!=NULL){
        if (aux -> conteudo == x){
            return aux;
        }
        aux = aux -> proximo;
    }
    
    return NULL;
}

void remover(celula **lst, int x) {

    celula *remove = localizar(*lst, x);

    if (remove == NULL) {
        printf("Elemento %d não encontrado na lista.\n", x);
        return;
    }
    if (*lst == remove) {
        *lst = remove->proximo;
    } else {
        celula *anterior = *lst;
        while (anterior->proximo != remove) {
            anterior = anterior->proximo;
        }
        anterior->proximo = remove->proximo;
    }

    free(remove);

    printf("\n Elemento %d removido da lista.\n", x);
}

int main (){

    celula *lst = NULL;

    inserirInicio(&lst, 1);
    inserirInicio(&lst, 2);
    inserirInicio(&lst, 3);
    imprimir_contar(lst);
    localizar(lst, 2);
    remover(&lst,1);
    imprimir_contar(lst);
    
}





