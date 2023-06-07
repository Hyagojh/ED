#include <stdio.h>
#include <stdlib.h>

// --- fun��es auxiliares ---
int check (char *s);
void take_component ();

char databank [] [40] = { //--- matriz de componentes do banco de dados ---
                                                "Pivo", "Componente de suspens�o",
                                                "Amortecedor", "Componente de suspens�o",
                                                "Barra estabilizadora", "Componente de suspens�o",
                                                "Pastilha", "Componente de freio",
                                                "Disco", "Componente de freio",
                                                "Junta", "Componente de motor",
                                                "Cabe�ote", "Componente de motor",
                                                "Biela", "Componente de Motor",
                                                "Filtro de ar", "Componente de alimenta��o",
                                                "Vela", "Componente de igni��o",
                                            };

char input [80];                                    //Matriz para entrada de dados (componente em pesquisa)
char component [80];                                //Matriz passada como par�metro para fun��o check
char *point;


int main (){

    int indice;                                            //Armazena o �ndice do componente
    char option;                                           //Armazena a op��o escolhida

    do {

        printf ("Informe o componente que deseja pesquisar: ");
        gets (input);
        point = input;

        printf ("Caracter�sticas do componente pesquisado: ");
        take_component ();

        do {

            indice = check (component);

            if (indice != -1) printf ("%s", databank [indice+1]);
            else printf ("Sem registro no banco de dados \n");

            take_component();

        } while (*component);                        //Repete at� encontrar uma string nula

        printf ("\n");

        printf ("Pesquisar mais? s- sim | n - nao \n");
        scanf ("%c", &option);
        getchar ();

    } while (option == 's' || option == "S");

    system ("PAUSE");

    return 0;
}

int check (char *s){                                 //Retorna a localiza��o de uma correspond�ncia entre a string

    int i;

    for (i = 0; *databank [i]; i++){
        if (!strcmp (databank [i], s)) break;
    }

    if (*databank[i]) return i;              	     //Retorna o �ndice correspondente se houver;
    else return (-1);
}

void take_component (){
     //ponteiro auxiliar
    char *q;

    //Recarrega o endere�o do componente toda vez que a fun��o � chamada
    q = component;

    //pega  o pr�ximo componente
    while (*point && *point != ' '){         //Shift no endere�o dos �ndices da matriz databank
        *q = *point;
        point++;
        q++;
    };

    if (*point == ' ') point ++;

    *q = '\0';                                               //terminador nulo
}


