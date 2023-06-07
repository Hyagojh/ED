#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

void insertElement (AvlNode* root){
	int valor;
	printf("informe um valor:\n");
	scanf ("%i", &valor);
	insertInTree (root, valor);
}

void menu(){
	AvlNode* root = NULL;
	int opcao = 1;
	while (opcao != 0){
		printf ("(1) Inserir elemento na árvore\n");
		printf ("(2) Inserir elemento na árvore\n");
		printf ("(3) Inserir elemento na árvore\n");
		printf ("(0) sair\n");
		scanf ("%i", &opcao);

		switch (opcao){
			case 1: insertElement(root) break;
			case 2: removeElement(); break;
			case 3: printTree(); 	 break;
		}
	}
}

int int main(int argc, char const *argv[]){

	menu();

	return 0;
}