#include <stdio.h>
#include <stdlib.h>

#define lunghezza 30

typedef struct
{
    char *titolo;
    char *nome;
    short int minuti;
    short int secondi;
}   Canzone;

int main(void)
{
    Canzone *libreria = (Canzone *) malloc(sizeof(Canzone));
    Canzone *nuovaCanzone = malloc(sizeof(Canzone));
    int uscita = 0;
    char *input = NULL;
    while (uscita != 1)
    {
        printf("Inserici il titolo della canzone:\t");
        fgets(nuovaCanzone -> titolo, lunghezza, stdin);
        printf("Inserici il nome del cantante:\t");
        fgets(nuovaCanzone -> nome, lunghezza, stdin);
        printf("Inserici i minuti della canzone:\t");
        scanf("%d", nuovaCanzone -> minuti);
        printf("Inserici i secondi della canzone:\t");
        scanf("%d", nuovaCanzone -> secondi);

        printf("Vuoi inserire un'altra canzone? (Y/y, N/n)");
        fgets(input, 1, stdin);
        switch (*input)
        {
            case 'Y':
            case 'y':
                break;
            default:
                uscita = 1;
                break;
        }
    }


    free(libreria);
    libreria = NULL;
    return 0;
}