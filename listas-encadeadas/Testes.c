#include <stdio.h>
#include <stdlib.h>
#include "Listas1.h"

int main (){
	/*Criação do ponteiro para o primeiro nó da lista, onde cada
	elemento saberá seu próximo.Basicamente é a criação da lista
	em si. Criando um ponteiro para o primeiro elemento 'nó', o null seria uma
	boa prática dizendo que a lista em um primeiro momento não aponta para nenhum
	elemento da lista*/

	/*Lista vazia criada*/
	Node* list = NULL;

	/*Primeiro nó da lista criado e associado*/
	list = (Node *) malloc(sizeof(Node));
	if (list == NULL){
		return 1;
	}

	list -> info = 1;
	list -> proximo = NULL;

	/*Criação de um novo nó*/
	Node* node1 = malloc(sizeof(Node));
	node1 -> info = 10;
	node1 -> proximo = NULL;

	/*Faz com que o ponteiro que dá início a lista (head pointer)
	aponte para o primeiro elemento da lista*/
	list -> proximo = node1;

	/*A criação de um novo nó*/



	/*Percorrer a lista e ponteiro percorredor*/

	Node* current = list; /*Ele começa da head da lista*/

	while (current != NULL){
		printf("Valo: %d\n", current -> info);
		current = proximo; /*Vai para o próximo elemento da lita*/
	}

}
