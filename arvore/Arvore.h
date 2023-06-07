#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct node{
	struct node* esq;
	int valor;
	struct node* dir;
} Node;

Node* criar (int novoValor);

Node* inserir (Node*, int novoValor);

void buscar (int valorBuscado);

void remover (int valorSolicitado);

void inOrder (Node* raiz);

#endif // AROVRE_H_INCLUDED