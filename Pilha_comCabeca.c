#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Celula {
    int conteudo;
    struct Celula *proximo;
} celula;

celula *top = NULL;

void push(int cont){
    
    struct Celula* novo = (struct Celula*)malloc(sizeof(struct Celula));
    
    novo -> conteudo = cont;
    novo -> proximo = top;
    top = novo;
    
}


void pop() {

    if (top == NULL) {
        printf("\nLista vazia!\n");
        
    } else {
        celula *aux;
        aux = top;
        top = top -> proximo;
        free(aux);
    }


}

void imprimir(){
    celula *aux;
    aux = top;
    int contador = 0;
    while(aux!=NULL){
        printf("%d->", aux -> conteudo);
        contador++;
        aux = aux-> proximo;
    }
    
}

int main (){
    push(1);
    push(2);
    push(3);
    imprimir();
    printf("\n");
    pop();
    pop();
    imprimir();
    printf("\n");
    push(5);
    push(8);
    imprimir();
    
}









