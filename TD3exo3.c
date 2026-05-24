#include <stdio.h>
void recup(int *taille, int *x);
void saisir_tableau(int tab[], int *taille);
int supprimer_element(int tab[], int *taille, int x);
void afficher_tableau(int tab[], int taille);

int main()
{
    int tab[taille];
    int taille, x;
    recup(&taille, &x);
    printf("=== Suppression d'un element ===\n\n");

    saisir_tableau(tab, &taille);

    printf("Tableau actuel : ");
    afficher_tableau(tab, taille);

    if (supprimer_element(tab, &taille, x))
    {
        printf("Tableau apres suppression de %d : ", x);
        afficher_tableau(tab, taille);
    }
    else
    {
        printf("Element %d non trouve dans le tableau.\n", x);
    }

    return 0;
}

void recup(int *taille, int *x)
{
    printf("Entrez la taille du tableau : ");
    scanf("%d", taille);
    printf("Entrez l'element X a supprimer : ");
    scanf("%d", x);
}
void saisir_tableau(int tab[], int taille)
{
    int i;

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

int supprimer_element(int tab[], int *taille, int x)
{
    int pos = -1;
    int i;

    /* Chercher la position de X */
    for (i = 0; i < *taille; i++)
    {
        if (tab[i] == x)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return 0;

    /* Décaler les éléments vers la gauche */
    for (i = pos; i < *taille - 1; i++)
    {
        tab[i] = tab[i + 1];
    }
    (*taille)--;
    return 1;
}
