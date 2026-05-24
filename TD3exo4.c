#include <stdio.h>

#define MAX1 50
#define MAX2 100

void saisir_tableau(int tab[], int *taille, int max, char nom[]);
int verifier_sous_tableau(int t1[], int n1, int t2[], int n2);
void supprimer_sous_tableau(int t1[], int *n1, int debut, int n2);
void afficher_tableau(int tab[], int taille);

int main()
{
    int t1[MAX1], t2[MAX2];
    int n1, n2;

    saisir_tableau(t1, &n1, MAX1, "T1");
    saisir_tableau(t2, &n2, MAX2, "T2");

    printf("\nT1 : ");
    afficher_tableau(t1, n1);
    printf("T2 : ");
    afficher_tableau(t2, n2);

    int pos = verifier_sous_tableau(t1, n1, t2, n2);

    if (pos != -1)
    {
        printf("\nT2 existe dans T1 a partir de l'indice %d.\n", pos);
        supprimer_sous_tableau(t1, &n1, pos, n2);
        printf("T1 apres suppression : ");
        afficher_tableau(t1, n1);
    }
    else
    {
        printf("\nT2 n'existe pas dans T1.\n");
    }

    return 0;
}

void saisir_tableau(int tab[], int *taille, int max, char nom[])
{
    printf("Entrez la taille de %s (max %d) : ", nom, max);
    scanf("%d", taille);
    for (int i = 0; i < *taille; i++)
    {
        printf("  %s[%d] = ", nom, i);
        scanf("%d", &tab[i]);
    }
}

void afficher_tableau(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int verifier_sous_tableau(int t1[], int n1, int t2[], int n2)
{
    int i, j;
    for (i = 0; i <= n1 - n2; i++)
    {
        int trouve = 1;
        for (j = 0; j < n2; j++)
        {
            if (t1[i + j] != t2[j])
            {
                trouve = 0;
                break;
            }
        }
        if (trouve)
            return i;
    }
    return -1;
}

void supprimer_sous_tableau(int t1[], int *n1, int debut, int n2)
{
    int i;
    for (i = debut; i < *n1 - n2; i++)
    {
        t1[i] = t1[i + n2];
    }
    *n1 -= n2;
}
