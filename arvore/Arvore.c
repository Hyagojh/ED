#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

Node* criar (int novoValor){
	Node* temp = (Node*) malloc (sizeof(Node));
	temp->valor = novoValor;
	temp->esq = temp->dir = NULL;
	return temp;
}

Node* inserir(Node* raiz, int novoValor){
	if (raiz == NULL){
		return criar (novoValor);
	}
	if (novoValor < raiz->valor){
		raiz->esq = inserir (raiz->esq,novoValor);
	}
	if (novoValor > raiz->valor){
		raiz->dir = inserir (raiz->dir, novoValor);
	}
}

void inOrder (Node* raiz){
	//esq raiz dir
	if (raiz != NULL){
		inOrder (raiz->esq);
		printf("%i\n", raiz->valor);
		inOrder (raiz->dir);
	}
}

