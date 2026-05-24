#include <stdio.h>

void recup(int *n);
void saisir_carre(int carre[][10], int n);
void afficher_carre(int carre[][10], int n);
int est_magique(int carre[][10], int n);

int main()
{
    int carre[10][10];
    int n;
    recup(&n);
    saisir_carre(carre, n);

    printf("\nCarre saisi :\n");
    afficher_carre(carre, n);

    if (est_magique(carre, n))
    {
        printf("\nCe carre est MAGIQUE.\n");
    }
    else
    {
        printf("\nCe carre n'est PAS magique.\n");
    }
    return 0;
}

void recup(int *n)
{
    printf("Entrez la taille n du carre (n x n) : ");
    scanf("%d", n);
}

void saisir_carre(int carre[][10], int n)
{
    int i, j;
    printf("Entrez les %d x %d elements :\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("  carre[%d][%d] = ", i, j);
            scanf("%d", &carre[i][j]);
        }
    }
}

void afficher_carre(int carre[][NMAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%4d", carre[i][j]);
        }
        printf("\n");
    }
}

int est_magique(int carre[][NMAX], int n)
{
    int somme_ref = 0;
    for (int j = 0; j < n; j++)
    {
        somme_ref += carre[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        int somme = 0;
        for (int j = 0; j < n; j++)
            somme += carre[i][j];
        if (somme != somme_ref)
            return 0;
    }
    for (int j = 0; j < n; j++)
    {
        int somme = 0;
        for (int i = 0; i < n; i++)
        {
            somme += carre[i][j];
        }
        if (somme != somme_ref)
        {
            return 0;
        }
    }

    return 1;
}
