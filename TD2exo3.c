#include <stdio.h>
#define MAX_TAILLE 100

void lireTableau(int T[], int *n);
void afficherTableau(const int T[], int n);
int supprimerZeros(int T[], int n);

int main()
{
    int T[MAX_TAILLE];
    int taille;

    printf("--- Suppression des 0 dans un tableau ---\n\n");

    // 1. Saisie du tableau
    lireTableau(T, &taille);

    printf("\nTableau initial :\n");
    afficherTableau(T, taille);

    // 2. Suppression et tassement
    taille = supprimerZeros(T, taille);

    // 3. Affichage du résultat

    printf("\nTableau resultat après suppression des 0 et tassement :\n");
    afficherTableau(T, taille);

    return 0;
}

void lireTableau(int T[], int *n)
{
    do
    {
        printf("Entrez la taille du tableau (max %d) : ", MAX_TAILLE);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_TAILLE);

    printf("Entrez les %d elements du tableau :\n", *n);
    for (int i = 0; i < *n; i++)
    {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
}

void afficherTableau(const int T[], int n)
{
    if (n == 0)
    {
        printf("[ Tableau Vide ]\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}

int supprimerZeros(int T[], int n)
{
    int curseurEcriture = 0;
    for (int curseurLecture = 0; curseurLecture < n; curseurLecture++)
    {
        if (T[curseurLecture] != 0)
        {
            T[curseurEcriture] = T[curseurLecture];
            curseurEcriture++;
        }
    }
    return curseurEcriture;
}