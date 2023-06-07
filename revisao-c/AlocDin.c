#include <stdio.h>
#include <stdlib.h>

/*A alocação de memória dinâmica só se torna conhecida durante
a execução do programa, ao contrário da memória estática que já
é alocada antes mesmo do programa entrar em execução.*/

/*A função Malloc (memory allocation) aloca espaço para um bloco
de bytes consecutivos na memória RAM e devolve o endereço desse bloco.*/

typedef struct {
	int dia, mes, ano;
} data; /*A definição da estrutura se dá entre os parênteses o 'data' significa
como essa estrutura será chamada.*/

/*Exercício de conversão, onde a função recebe um char e retorna um ponteiro tipo char (string)*/
char* converte (char c){
	/*Digo que o ponteiro 'retorno' aponta para um tamanho alocado, no caso 'c * 2'
	e atribuo ao ponteiro  o endereço de c*/
	char* retorno;
	retorno = malloc(sizeof(c * 2));
	retorno [0] = c;
	//retorno [1] = '\O'; /*Strings em C precisam terminar com /0 para determinar o fim do array*/
	return retorno;
}

/*Devolvendo números primos com ponteiros*/
int* primos(void){
		int* v;
		v = malloc(3 * sizeof(*v));
		v [0] = 1009;
		v [1] = 1013;
		v [2] = 1019;
		return v;
	}




int main (){
	data data1; /*Exemplo de alocação e declaração estática*/
	data1.dia = 10;
	data1.mes = 10;
	data1.ano = 2010;

	printf ("Data 1 está em: %p\n", &data1);

	/*A função Malloc (memory allocation) aloca espaço para um bloco
	de bytes consecutivos na memória RAM e devolve o endereço desse bloco.*/
	
	/*Foi criado um ponteiro que aponta para a estrutura data2.
	Apenas o ponteiro foi declarado, em seguida eu solicito uma alocação
	do tamanho de uma estrutura data.*/

	/*tu ta fazendo o ponteiro apontar para uma alocação de memória aleatória.
	aleatório = o tamanho que tu definir*/

	data* data2;
	data2 = malloc(sizeof(data)); /*Sizeof é um operador para indicar o tamaho a ser alocado*/

	printf ("Data 2 está em: %p\n", data2);

	/*Exercício conversão*/
	char charDeTeste = 'A';

	char nome [10] = "Alessandro";

	char* RetornoDaFuncao = converte (charDeTeste);

	printf ("A função de conversão retornou: %s\n", RetornoDaFuncao);	

	/*A função free serve para desalocar uma porção de memória por uma função malloc,
	liberando a partir de um ponteiro, que indica a partir de onde um bloco de bytes
	está disponível para reciclagem. Não devendo ser aplicado apenas em parte do bloco
	e sim em um bloco todo de malloc.*/

	/*Exemplo de algo errado

	int* v;
	v = malloc(100 * sizeof(int));
	v[0] = 999;
	free (v+1); /*Caso o ponteiro 'v' aponte para a posição de memória '1' com o incremento
	eu estou mandando limpar da posição 2 (ou 5, visto que int ocupa 4b) em diante*/ 

	/*Devolvendo números primos com ponteiros*/


	int* TresPrimeirosPrimosMaioresQue1000 = primos();
	printf("O primeiro número primo maior que 1000 é: %i\n", TresPrimeirosPrimosMaioresQue1000[0]);

	/*Exemplo de como um array pode ser alocado e desalocado durante a execução de um programa*/
	int *v;
	int  n;

	scanf ("%d",&n);

	v = malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i){
		scanf ("%d", &v[i]);
	}
	free(v);

	/*Criação com ponteiros de uma matriz alocada dinâmicamente*/

	int ** matriz; /*Dois ponteiros*/
	int tamanho;	

	printf ("Informe o tamanho da matriz quadrada: \n");
	scanf ("%d", &tamanho);

	matriz = malloc(tamanho * sizeof(int)); /*Alocando a primeira dimensão da matriz
	exemplo matriz [3][3], essa linha alocou apenas uma dimensão [*p1][*p2][*p3] com ponteiros dentro*/
	for (int i = 0; i < tamanho; ++i){
		matriz[i] = malloc(tamanho * sizeof (int)); /*Já nessa linha o [*pn] receberá 3 posições de int
		e alocará as 3 primeiras linhas (ou primeira coluna) e assim sucessivamente até formar matriz de
		3 por 3 de ponteiros.*/
		/*Para desalocar seria: */
		//free (matriz[i]);
	}

	/*Teste*/
	matriz [0][0] = 5;
	matriz [1][1] = 10;
	matriz [2][2] = 15;

	for (int linha = 0; linha < 3; ++linha){
		for (int coluna = 0; coluna < 3; ++coluna){
			printf("%i\n", matriz[linha][coluna]);
		}
	}

	/*As vezes é necessário realocar um determinado bloco de bytes que foi alocado por malloc
	e para isso existe a função realloc, isso acontece por exemplo na leitura de um dado que se
	mostra maior que o alocado previamente.*/
	/*A função realloc vai receber o endereço de um bloco e o número de bytes que o bloco realocado
	deve ter, a função aloca um novo bloco e copia para dentro o conteúdo do bloco anterior.
	Caso o bloco seja uma extensão, o endereço será o mesmo do original. Caso contrário o realloc
	copia o conteúdo original e com a função free libera o espaço do bloco original.*/

	/*Exercício: faça um programa receba uma sequencia indeterminada de valores inteiros.
	Escreva uma função para que imprima esses valores de ordem inversa. A dificuldade é
	alocar o espaço para uma quantidade de números que só será conhecida posteriormente.*/

	

}	