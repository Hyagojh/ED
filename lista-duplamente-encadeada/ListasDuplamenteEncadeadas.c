#include <stdio.h>
#include <stdlib.h>
#include "ListasDuplamenteEncadeadas.h"

void cria (LDE* lista){
	lista -> inicio = NULL;
	lista -> fim = NULL;
}

void adicionaInicio(No** lista, int valor){
	No* novoNo = (No*) malloc (sizeof(No));
	novoNo -> valor = valor;

	if (*lista == NULL){
		novoNo -> anterior = NULL;
		novoNo -> proximo = NULL;
	} else {
		novoNo -> proximo = *lista;
		novoNo -> anterior = NULL;
		(*lista) -> anterior = novoNo;
	}
}
	*lista = novoNo;

void imprimir(No* lista){
	No* atual = lista;
	if (lista != NULL){
		No* atual = lista;
		printf("\n Lista está assim: \n");
		while (atual != NULL){
			printf ("Valor: %d\n", atual -> valor);
			atual = atual -> proximo;
		}
	}	
}
