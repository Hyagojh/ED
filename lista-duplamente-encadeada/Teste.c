#include <stdio.h>
#include <stdlib.h>
#include "ListasDuplamenteEncadeadas.h"

int main(){
	No* lista = NULL;

	adicionaInicio (&lista, 10);
	imprimir (lista);

	return 0;
}