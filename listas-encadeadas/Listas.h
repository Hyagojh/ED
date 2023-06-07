/*Listas são estruturas de dados dinâmicas, de maneira análoga a vetores
elas também armazenam elementos, porém, ela faz isso dinâmicamente.
Um exemplo são as listas encadeadas*/

/*Em listas encadeadas (linked lists) cada elemento da lista é chamado de 'nó'
e dentro desse nó existe dois campos: a informação e um ponteiro para o próximo elemento até
o último elemento que será caracterizado por não apontar para nada, um NULL.
O primeiro elemento da lista é um ponteiro para o primeiro nó e o resto dos nós se comunicam
através dos ponteiros internos. */

#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

/*Definição de um nó*/

typedef struct node {
	int info; 				/*4 Bytes*/
	struct node* proximo; 	/*4 Bytes e Aponta para a próxima estrutura da lista*/
} Node;

Node* criar ();

void adicionarAoInicio (Node* list, Node* node);

void adicionarAoFinal(Node* list, int value);

int removeDoFinal (Node* list);

void imprimir(Node* list);

#endif // NODE_H_INCLUDED