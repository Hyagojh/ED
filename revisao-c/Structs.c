#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	/*Exercício de revisão geral*/

	typedef struct horario {
	    int hora;
	    int minuto;
	    int segundo;
	};

	void receberHorarios (struct horario lista [5]){
	    int i;
	    for (i = 0; i < 5; i++){
	        printf ("Digite o %i horário (hh:mm:ss):", i + 1);
	        scanf ("%i: %i:  %i", &lista[i].hora,
	                                        &lista[i].minuto,
	                                        &lista[i].segundo);
	    }
	}

	void printHorarios (struct horario lista [5]){
	    int i;
	    for (i = 0; i < 5; i++){

	        printf ("O %i horário é = %i: %i:  %i \n",
	                                        i+1,
	                                        lista[i].hora,
	                                        lista[i].minuto,
	                                        lista[i].segundo);
	    }
	}

int main (){
	/*
	 * Crie um programa que possuí uma função que recebe como argumento um vetor de tamanho
	 * 5 de tipo estrutura sendo que essa estrutura deve armazenar um determinado horário no formato
	 * hh:mm:ss, peça para que o usuário digite 5 horários diversos que deverão ser armazenados
	 * no argumento recebido. Crie uma segunda função que receberá este mesmo vetor estrutura
	 * mas dessa vez a função deverá apenas ter os valores armazenados no vetor estrutura mostrando
	 * uma mensagem apropriada.
	*/

    struct horario listaHorarios [5];

    receberHorarios (listaHorarios);

    printHorarios (listaHorarios);


	/*Declaração de uma estrutura e seus 'atributos', structs são como classes
	com seus atributos, porém, sem métodos internos e visibilidade*/
	struct nametype {
		char first [10];
		char midnit [10];
		char last [20];
	};
 
	/*A utilização de uma struct dentro de outra é válido desde que declarada anteriormente*/
	struct person {
		struct nametype name;
		int 			birthday [2];
		struct nametype parents [2];
		int 			income;
		int				numChildren;
		char			address [20];
		char 			city [10];
		char			state [2];
	};	
 
 	/*Exemplo para um cadastro para 100 pessoas: criação de um array de 100 posições do tipo person*/
 	struct person pessoas [100];

 	/*Exemplo de cadastro de alunos e notas com structs*/
 	struct notas{
 		float nota1;
 		float nota2;
 		float nota3;
 	};

 	struct aluno{
 		char nome [100];
 		struct notas notas;
 	};

 	struct aluno alunos [72];


	void main (){
		/*Preenchimento da struct alunos*/
		strcpy(alunos[0].nome, "José");
		alunos[0].notas.nota1 = 10;
		alunos[0].notas.nota2 = 7;
		alunos[0].notas.nota3 = 7;

		/*Nome dos 10 primeiros alunos*/
		int i;
		for (i = 0; i < 10; i++){
			printf("type some name: \n");
			scanf ("%s", &pessoas[i].name.first[i]);
		}

		for (i = 0; i < 10; ++i){
			printf ("Aluno %d - nome: %s - nota1: %f - nota2 = %f - nota3 = %f \n", i, alunos[i].nome,
			alunos[i].notas.nota1, alunos[i].notas.nota2, alunos[i].notas.nota3);
		}
		
	}

	/*Structs com funções*/

	struct horario{	
		char letraInicial;
		int horas;
		int minutos;
		int segundos;
	};

	/*struct horario significa que ela retorna uma 
	estrutura do tipo horário e a função tem nome teste*/
	struct horario teste(struct horario x){
		    x.horas = 100;
			x.minutos = 100;
			x.segundos = 100;
			
		return x;
	}

	int main(){
	/*declara a função*/	
	struct horario teste(struct horario x);
	
	/*agora irei criar uma estrutura de tipo horário*/
	struct horario agora; 
	
	/*nome da estrutura, e atributos de dentro da estrutura matriz*/	
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;

	printf("%i:%i:%i \n", agora.horas, agora.minutos, agora.segundos );
	/*chamando a função e passando uma estrutura como parâmetro,
	agora a função que retorna uma estrutura jogará os atributos
	da estrutura 'teste' para dentro da estrutura horario proxima*/
	struct horario proxima;
	proxima = teste(agora);
	printf("%i:%i:%i\n", proxima.horas, proxima.minutos, proxima.segundos);

	struct horario depois;
	/*a variável horas dentro da estrutura 'depois' vai ser igual a = 15 + 10; Demonstrando
	a relação possível entre estruturas*/
	depois.horas = agora.horas + 10;
	depois.minutos = agora.minutos;
	depois.letraInicial = 'H';

	printf("%c, %i:%i \n", depois.letraInicial, depois.horas, depois.minutos);



	return 0;
}