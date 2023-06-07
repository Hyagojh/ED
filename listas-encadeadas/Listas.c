#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Node* cria() {
    Node* list = NULL;
    list = (Node*) malloc(sizeof(Node));
    if (list == NULL) {
        return 1;
    }
    return cabeca;
}

void adicionaAoInicio(Node* list, int valor) {
    // CRIA NOVO NÓ
    Node* novoNodo = cria();
    novoNodo->info = valor;
    novoNodo->proximo = list;

    list = novoNodo;
}

void adicionaAoFinal(Node* list, int valor) {
    // PERCORRE ATÉ O FINAL
    Node* atual = list;
    while( atual->proximo != NULL){
        atual = atual->proximo;
    }

    // CRIA NOVO NÓ
    Node* novoNodo = cria();
    novoNodo->info = valor;
    novoNodo->proximo = NULL;

    // SETA O NOVO NÓ COMO ÚLTIMO
    atual->proximo = novoNodo;
}

int removeDoFinal(Node* cabeca){
    int valorRemovido = 0;
    // VERIFICA SE TEM ALGO NA LISTA
    if (list->proximo == NULL) {
        printf("o proximo de cabeca eh %p\n", list->proximo);
        valorRemovido = cabeca->info;
        list = NULL;
        free(list);
        return valorRemovido;
    }

    // PERCORRE ATÉ O FINAL
    Node* atual = list;
    while( atual->proximo->proximo != NULL){
        atual = atual->proximo;
    }

    valorRemovido = atual->proximo->info;
    free(atual->proximo);
    atual->proximo = NULL;
    return valorRemovido;
}


void imprimir(Node* list){
    Node* atual = list;
    if (atual != NULL)
        printf("\nNossa Lista estah assim:\n");
    while( atual != NULL){
        printf("valor: %d\n", atual->info);
        atual = atual->proximo;
    }
}
