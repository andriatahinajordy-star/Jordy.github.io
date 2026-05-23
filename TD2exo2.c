#include <stdio.h>

void recup(int *N);
void remplirTableau(intN);
int trouverMax(int T[], int N, int *position);
void afficher(int valeurMax, int posMax);

int main()
{
    int N;
    int T[N] recup(&N);
    remplirTableau(N);
    int posMax = 0;
    int valeurMax = trouverMax(T, n, &posMax);
    afficher(valeurMax, posMax);
    return 0;
}

void recup(int *N)
{
    printf("Entrez la taille du tableau : ");
    scanf("%d", *N);
}

void remplirTableau(int N)
{
    printf("Entrez les %d elements du tableau :\n", N);
    for (int i = 0; i < n; i++)
    {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
}

int trouverMax(int T[], int N, int *position)
{
    int max = T[0];
    *position = 0;

    for (int i = 1; i < N; i++)
    {
        if (T[i] > max)
        {
            max = T[i];
            *position = i;
        }
    }

    return max;
}

void afficher(int valeurMax, int posMax)
{
    printf("\n--- Resultat ---\n");
    printf("La valeur maximale est : %d\n", valeurMax);
    printf("Elle se trouve a la position (indice) : %d\n", posMax);
}