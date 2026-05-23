#include <stdio.h>

#define DIM_MAX 50

void recup(int *N);
void remplir_tableau(int T[], int N);
void afficher_tableau(int T[], int N);
int calcular_somme(int T[], int N);
void afficher(int somme);

int main()
{
    int T[DIM_MAX];
    int N;
    int somme;

    recup(&N);

    remplir_tableau(T, N);

    afficher_tableau(T, N);

    somme = calcular_somme(T, N);

    afficher(somme);

    return 0;
}

void recup(int *N)
{
    do
    {
        printf("Entrez la dimension du tableau (entre 1 et %d) : ", DIM_MAX);
        scanf("%d", N);

        if (*N <= 0 || *N > DIM_MAX)
        {
            printf("Erreur : La dimension doit etre comprise entre 1 et %d.\n", DIM_MAX);
        }
    } while (*N <= 0 || *N > DIM_MAX);
}

void remplir_tableau(int T[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Entrez l'element T[%d] : ", i);
        scanf("%d", &T[i]);
    }
}

void afficher_tableau(int T[], int N)
{
    printf("[ ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}

int calcular_somme(int T[], int N)
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        s += T[i];
    }
    return s;
}
void afficher(int somme)
{
    printf("\nLa somme des elements du tableau est : %d\n", somme);
}