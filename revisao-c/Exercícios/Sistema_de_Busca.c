#include <stdio.h>
#include <stdlib.h>

// --- funções auxiliares ---
int check (char *s);
void take_component ();

char databank [] [40] = { //--- matriz de componentes do banco de dados ---
                                                "Pivo", "Componente de suspensão",
                                                "Amortecedor", "Componente de suspensão",
                                                "Barra estabilizadora", "Componente de suspensão",
                                                "Pastilha", "Componente de freio",
                                                "Disco", "Componente de freio",
                                                "Junta", "Componente de motor",
                                                "Cabeçote", "Componente de motor",
                                                "Biela", "Componente de Motor",
                                                "Filtro de ar", "Componente de alimentação",
                                                "Vela", "Componente de ignição",
                                            };

char input [80];                                    //Matriz para entrada de dados (componente em pesquisa)
char component [80];                                //Matriz passada como parâmetro para função check
char *point;


int main (){

    int indice;                                            //Armazena o índice do componente
    char option;                                           //Armazena a opção escolhida

    do {

        printf ("Informe o componente que deseja pesquisar: ");
        gets (input);
        point = input;

        printf ("Características do componente pesquisado: ");
        take_component ();

        do {

            indice = check (component);

            if (indice != -1) printf ("%s", databank [indice+1]);
            else printf ("Sem registro no banco de dados \n");

            take_component();

        } while (*component);                        //Repete até encontrar uma string nula

        printf ("\n");

        printf ("Pesquisar mais? s- sim | n - nao \n");
        scanf ("%c", &option);
        getchar ();

    } while (option == 's' || option == "S");

    system ("PAUSE");

    return 0;
}

int check (char *s){                                 //Retorna a localização de uma correspondência entre a string

    int i;

    for (i = 0; *databank [i]; i++){
        if (!strcmp (databank [i], s)) break;
    }

    if (*databank[i]) return i;              	     //Retorna o índice correspondente se houver;
    else return (-1);
}

void take_component (){
     //ponteiro auxiliar
    char *q;

    //Recarrega o endereço do componente toda vez que a função é chamada
    q = component;

    //pega  o próximo componente
    while (*point && *point != ' '){         //Shift no endereço dos índices da matriz databank
        *q = *point;
        point++;
        q++;
    };

    if (*point == ' ') point ++;

    *q = '\0';                                               //terminador nulo
}


