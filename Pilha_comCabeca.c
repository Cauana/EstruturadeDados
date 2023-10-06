#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Celula {
    int conteudo;
    struct Celula *proximo;
} celula;


void push(int cont, celula *p){
    
    struct Celula* novo = (struct Celula*)malloc(sizeof(struct Celula));
    
    novo -> conteudo = cont;
    novo -> proximo = p -> proximo;
    p -> proximo = novo;
    
}


int pop( celula *p) {
    
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
    
    
    push(1, p);
    push(2, p);
    push(3, p);
    imprimir(p);
    printf("\n");
    pop(p);
    pop(p);
    imprimir(p);
    printf("\n");
    push(5, p);
    push(8, p);
    imprimir(p);
    
}




