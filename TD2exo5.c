#include <stdio.h>

void inverserTableau(int T[], int taille);
void afficherTableauResultat(int T[], int taille);

int main()
{
    int T[] = {12, 45, 7, 89, 23, 64, 10};
    int taille = sizeof(T) / sizeof(T[0]);

    printf("Tableau d'origine :\n");
    afficherTableau(T, taille);

    inverserTableauResultat(T, taille);

    printf("\nTableau inverse :\n");
    afficherTableau(T, taille);

    return 0;
}

void inverserTableau(int T[], int taille)
{
    int debut = 0;
    int fin = taille - 1;
    int temporaire;

    while (debut < fin)
    {
        temporaire = T[debut];
        T[debut] = T[fin];
        T[fin] = temporaire;

        debut++;
        fin--;
    }
}

void afficherTableauResultat(int T[], int taille)
{
    printf("[ ");

    for (int i = 0; i < taille; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}