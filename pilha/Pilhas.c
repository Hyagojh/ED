#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

/*O sistema de Pilhas funciona no sistema "last in, first out"
a última informação a entrar na lista, é a primeira sair. Esse código
é uma exemplificação disso, a função printSomething funciona exatamente
assim, as outras funções e métodos também funcionam no sistema de pilha.*/

void printSomething (char toPrint){
	printf ("%c\n", toPrint);
}

int fatorial (int number){
	if (number == 1){
		return 1;
	}
	return number * fatorial (number);
}

int main(){
	char palavra [10] = "ABCABAOAOA";
	int i, resultado, numero;
	
	for (i = 0; i < 9; i++){
		printSomething(palavra[i]);
	}

	printf ("Informe um número:\n");
	scanf ("%d", &numero);
	resultado = fatorial (numero);
	printf ("\n%d", resultado);
}