#define NODE_H_INCLUDED

/*Listas duplamente encadeadas, são como listas comuns, porém, agora utilizando também
um ponteiro para o item anterior da lista, o que permite algumas funcionalidades*/

typedef struct no {
	int valor;
	struct no* anterior; 
	struct no* proximo;
} No;

typedef struct listaDuplamenteEncadeada {
	No* inicio;
	No* fim;
} LDE;

void cria(LDE *lista);

void adicionaInicio(No**  lista, int valor);

void adicionaFinal(No* cabeca, int valor);

int removeFinal(No* cabeca);

void imprimir(No* lista);