#include <stdio.h>
#include <stdlib.h>

#define MAX_TAILLE 100

void lireTableau(int T[], int *dim, char nom);
void fusionnerTableaux(int A[], int N, int B[], int M);
void afficherTableau(int T[], int dim, char nom);
void afficherErreurTaille();
void verifierEtFusionner(int A[], int N, int B[], int M);
void executerApplication();

int main()
{
    executerApplication();
    return 0;
}

void executerApplication()
{
    int A[MAX_TAILLE];
    int B[MAX_TAILLE];
    int N, M;

    lireTableau(A, &N, 'A');
    lireTableau(B, &M, 'B');

    verifierEtFusionner(A, N, B, M);
}

void verifierEtFusionner(int A[], int N, int B[], int M)
{
    if (N + M > MAX_TAILLE)
    {
        afficherErreurTaille();
    }
    else
    {
        fusionnerTableaux(A, N, B, M);
        afficherTableau(A, N + M, 'A');
    }
}

void lireTableau(int T[], int *dim, char nom)
{
    printf("--- Saisie du tableau %c ---\n", nom);
    do
    {
        printf("Entrez la dimension du tableau %c (max %d) : ", nom, MAX_TAILLE / 2);
        scanf("%d", dim);
    } while (*dim <= 0 || *dim > MAX_TAILLE / 2);

    printf("Entrez les %d éléments du tableau %c :\n", *dim, nom);
    for (int i = 0; i < *dim; i++)
    {
        printf("%c[%d] = ", nom, i);
        scanf("%d", &T[i]);
    }
    printf("\n");
}

void fusionnerTableaux(int A[], int N, int B[], int M)
{
    for (int i = 0; i < M; i++)
    {
        A[N + i] = B[i];
    }
}

void afficherTableau(int T[], int dim, char nom)
{
    printf("--- Résultat du tableau %c après ajout ---\n", nom);
    printf("Tableau %c : [ ", nom);
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}

void afficherErreurTaille()
{
    printf("\nErreur : La taille combinée des deux tableaux dépasse la capacité maximale autorisée (%d).\n", MAX_TAILLE);
}