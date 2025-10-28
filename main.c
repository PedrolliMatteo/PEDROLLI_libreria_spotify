#include <stdio.h>
#include <stdlib.h>

#define lunghezza 30

typedef struct
{
    char titolo[lunghezza*lunghezza];
    char nome[lunghezza*lunghezza];
    int minuti;
    int secondi;
}   Canzone;

void pulisciArray(char array[])
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        array[i] = 0;
    }
}

int aggiungiCanzone(Canzone *nuovaCanzone, Canzone *libreria, int i)
{
    char prova[lunghezza];
    pulisciArray(prova);
    printf("Inserici il titolo della canzone:\t");
    fgets(prova, lunghezza, stdin);
    int j = 0;
    for (j = 0; prova[j] != '\0' && prova[j] != '\n'; j++)
    {
        nuovaCanzone -> titolo[j] = prova[j];
    }
    nuovaCanzone -> titolo[j] = '\0';

    printf("Inserici il nome del cantante:\t");
    fgets(prova, lunghezza, stdin);
    for (j = 0; prova[j] != '\0' && prova[j] != '\n'; j++)
    {
        nuovaCanzone -> nome[j] = prova[j];
    }
    nuovaCanzone -> nome[j] = '\0';

    //giusti
    printf("Inserici i minuti della canzone:\t");
    fgets(prova, 10, stdin);
    nuovaCanzone -> minuti = strtol(prova, 0, 10);
    printf("Inserici i secondi della canzone:\t");
    fgets(prova, 10, stdin);
    nuovaCanzone -> secondi = strtol(prova, 0, 10);

    //inserimento della canzone in libreria
    libreria[i] = *nuovaCanzone;
    i ++;
    return i;
}

int main(void)
{
    int grandezza = 1;
            /*non cambia nulla perhé lo fa in automatico
                              |
                              V                         */
    Canzone *libreria = /*(Canzone *)*/ malloc(sizeof(Canzone) * grandezza);
    Canzone *nuovaCanzone = malloc(sizeof(Canzone));
    int uscita = 0, i = 0;
    char input;
    while (uscita != 1)
    {
        input = 0;
        printf("Buongiorno e benvenuto su Spotify!\nCosa vuole fare oggi?"
               "\n1. Aggiungere una canzone"
               "\n2. Visualizzare la libreria delle canzoni"
               "\n3. Uscire (premere qualsiasi tasto che non sia 1 o 2)\n");

        scanf("%c", &input);
        while (getchar() != '\n');

        switch (input)
        {
            case '1':
                if (i >= grandezza)
                {
                    grandezza *= 2;
                    Canzone *temporaneo = realloc(libreria, sizeof(Canzone) * grandezza);
                    libreria = temporaneo;
                }
                i = aggiungiCanzone(nuovaCanzone, libreria, i);
                break;
            case '2':
                for (int j = 0; j < i; j ++)
                {
                    printf("Canzone n %d\n", j);
                    printf("Titolo:\t%s\nNome:\t%s\nDurata:\t%d:%d\n\n",
                        libreria[j].titolo, libreria[j].nome,
                        libreria[j].minuti, libreria[j].secondi );
                }
                break;
            default:
                printf("Have a nice day!");
                uscita = 1;
                break;
        }
    }


    free(libreria);
    free(nuovaCanzone);
    libreria = NULL;
    nuovaCanzone = NULL;
    return 0;
}