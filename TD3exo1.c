#include <stdio.h>

void saisir_tableau(int tab[], int taille);
void afficher_pairs_avant_impairs(int tab[], int taille);
void afficher_tableau(int tab[], int taille);

int main()
{
    int tab[taille];

    saisir_tableau(tab, taille);
    afficher_tableau(tab, taille);
    afficher_pairs_avant_impairs(tab, taille);

    return 0;
}

void saisir_tableau(int tab[], int taille)
{
    int i;
    printf("Entrez %d entiers :\n", taille);
    for (i = 0; i < taille; i++)
    {
        printf("  tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
}

void afficher_tableau(int tab[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void afficher_pairs_avant_impairs(int tab[], int taille)
{
    int i;
    /* Affiche d'abord tous les pairs */
    for (i = 0; i < taille; i++)
    {
        if (tab[i] % 2 == 0)
        {
            printf("%d ", tab[i]);
        }
    }
    /* Afficher d'abord les impairs*/
    for (i = 0; i < taille; i++)
    {
        if (tab[i] % 2 != 0)
        {
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
}
