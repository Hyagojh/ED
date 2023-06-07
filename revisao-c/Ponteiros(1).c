#include <stdio.h>

int main (void){

	int x; /*Solicitamos um espaço para armazenar um valor inteiro*/

	x = 10; /*E nesse espaço da memória eu quero armazenar 10*/

	printf("%p \n", &x ); /*O & me indica o endereço de memória da variáevl X
	e não o valor contido na mesma. Percent P é usado para mostrar endereço*/

	int* ponteiro; /*O tipo primitivo indica a que tipo de data o meu ponteiro 
	apontará e o '*' indica ao compilador que a variável não armazenará um 
	um valor e sim apontará um endereço*/

	ponteiro = &x; /*Inicialmente o ponteiro não aponta pra ninguém, agora
	apontará para o endereço da variável X.*/

	printf ("%i \n", *ponteiro); /*Agora o '*' transforma-se em operador
	unário e devolverá o valor que está armazenado na variável que o ponteiro
	aponta, caso não tenha o '*' será printado apenas o endereço da memória
	em si. */

	int y = 20;
	*ponteiro = y;
	/*O ponteiro apontava inicialmente para o endereço de X, que tem o
	valor 10, agora o '*' indica que o ponteiro alterará o valor contido na
	diretamente na variável x pelo valor de y.*/



	/*Ponteiros e vetores*/

	int vetor [3] = {1, 2, 3};

	int *ponteiro1 = vetor; /*O ponteiro não precisa especificar o tamanho
	de si mesmo, o & é dispensado por que o vetor alterará o endereço de 
	memória constantemente, nesse caso de 4 em 4 bytes e inicialmente o ponteiro apontará para a posição 1 do vetor
	isso podendos ser alterado com um " = &vetor = [0];*/

	printf("%i \n", *ponteiro1); /*O valor que está contido na primeira posição do vetor*/

	ponteiro1++;	

	printf("%i \n", *ponteiro1);
	/*Exemplo de incremento de ponteiro, o endereço pula de 4 em 4 bytes, (isso no incremento do ponteiro
	do tipo inteiro) então coincide com os saltos nos endereços de memória do vetor, consequentemente 
	mostrará o valor da segunda posição do vetor*/

	/*Exemplo clássico com estrutura de repetição, varrendo uma matriz*/

	char str [30], *p;
	p = str; /*ponteiro p aponta para a posição 0 do array str*/

	printf("Esse programa demonstra a varredura sequencial de uma matriz com ponteiros\n");
	printf("Digite um nome:\n");
	gets (str);

	printf("O nome digitado foi:\n");

	/*O ponteiro P é testado até atingir o delimitador de memória /O*/
	while(*p){
		printf ("%c", *p++); /*O ponteiro P é incrementado e passa a apontar para a próxima posição da string*/
		printf("\n\n");
	}


	/*Exemplo de matriz com ponteiros*/

	//como seria normalmente

	float mat[50][50];
	int i, j, count;

	for (int i = 0; i < 50; ++i){
		for (int j = 0; j < 50; ++j){
					mat[i][j] = count;
					count++;
				}		
	}
	for (int i = 0; i < 50; ++i){
		for (int j = 0; j < 50; ++j){
					printf ("%f \n", mat[i][j]);
				}
	}

	//com ponteiros

	int matriz[2500];
	int *p;

	p = matriz;

	for (i = 0; i < 2500; ++i){
		*p = i;
		++p;
	}

	for (i = 0; i < 2500; ++i){
		printf ("%i \n", *p);
		++p;
	}


	/*Comparação de ponteiros: perguntar se um ponteiro é maior que o outro significa perguntar
	se um ponteiro está a frente da memória que o outro*/

	int x = 10, y = 10;

	int *p1, *p2;

	p1 = &x;
	p2 = &y;

	if (p1 > p2){
		printf("A variável x está armazenada em um endereço de memória acima da variável y\n");
	}

	/*Falta o último exemplo*/


	return 0;
}