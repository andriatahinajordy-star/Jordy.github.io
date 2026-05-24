#include <stdio.h>

void recup(int *taille, int *x);
void saisir_tableau_trie(int tab[], int taille);
int inserer_element(int tab[], int *taille, int x);
void afficher_tableau(int tab[], int taille);
void afficher(int x);

int main()
{
    int tab[taille];
    int taille, x;
    recup(&taille, &x);
    saisir_tableau_trie(tab, taille);
    afficher_tableau(tab, taille);
    inserer_element(tab, &taille, x);
    afficher_tableau(x);
    return 0;
}

void recup(int *taille)
{
    printf("Entrez la taille du tableau : ");
    scanf("%d", taille);
    printf("Entrez l'element X a inserer : ");
    scanf("%d", x);
}

void saisir_tableau_trie(int tab[], int taille)
{
    int i;
    printf("Entrez les elements dans l'ordre croissant :\n");
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

int inserer_element(int tab[], int *taille, int x)
{
    int pos = *taille;
    int i;

    /* Trouver la position d'insertion */
    for (i = 0; i < *taille; i++)
    {
        if (x < tab[i])
        {
            pos = i;
            break;
        }
    }
    /* Décaler les éléments vers la droite */
    for (i = *taille; i > pos; i--)
    {
        tab[i] = tab[i - 1];
    }
    tab[pos] = x;
    (*taille)++;
    return pos;
}

void afficher(int x)
{
    printf("Tableau apres insertion de %d : ", x);
}