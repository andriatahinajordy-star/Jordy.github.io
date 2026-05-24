#include <stdio.h>
void recup(int *n);
void saisirVecteur(int T[], int n);
int produitScalaire(int U[], int V[], int n);
void afficherResultat(int resultat);

int main()
{
    int n, ps;

    recup(&n);

    int U[n], V[n];

    saisirVecteur(U, n);
    saisirVecteur(V, n);

    ps = produitScalaire(U, V, n);

    afficherResultat(ps);

    return 0;
}

void recup(int *n)
{
    printf("Entrez la dimension de deux vecteurs : \n");
    scanf("%d", n);
}
void saisirVecteur(int T[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
    }
}

int produitScalaire(int U[], int V[], int n)
{
    int i, somme = 0;

    for (i = 0; i < n; i++)
    {
        somme = somme + (U[i] * V[i]);
    }

    return somme;
}

void afficherResultat(int resultat)
{
    printf("Le produit scalaire est : %d\n", resultat);
}