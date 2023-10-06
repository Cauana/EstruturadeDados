#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Celula {
    int conteudo;
    struct Celula *proximo;
} celula;


void executa_acao(int cont, celula *p){
    struct Celula* novo = (struct Celula*)malloc(sizeof(struct Celula));
    novo -> conteudo = cont;
    novo -> proximo = p -> proximo;
    p -> proximo = novo;
    
}


int controlz( celula *p) {
    int x;
    celula *aux;
    aux = p -> proximo;
    x = aux -> conteudo;
    p -> proximo = aux -> proximo;
    free (aux);
    return x;
}

void imprimir(celula *p){
    celula *aux;
    aux = p -> proximo;
    int contador = 0;
    while(aux!=NULL){
        printf("%d->", aux -> conteudo);
        contador++;
        aux = aux-> proximo;
    }
    
}

int main (){
    
    celula top;
    celula *p;
    p = &top;
    p -> proximo = NULL;
    
    
    executa_acao(1, p);
    executa_acao(2, p);
    executa_acao(3, p);
    imprimir(p);
    printf("\n");
    controlz(p);
    controlz(p);
    imprimir(p);
    printf("\n");
    executa_acao(5, p);
    executa_acao(8, p);
    imprimir(p);
    
}




