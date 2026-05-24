#include <stdio.h>
void recup(int *n);
void saisirTableau(int A[], int n);
void rechercherMaxMin(int A[], int n, int *max, int *min, int *posMax, int *posMin);
void afficherResultat(int max, int min, int posMax, int posMin);

int main()
{
    int A[100], n;
    int max, min, posMax, posMin;

    saisirTableau(A, n);

    rechercherMaxMin(A, n, &max, &min, &posMax, &posMin);

    afficherResultat(max, min, posMax, posMin);

    return 0;
}

void recup(int *n)
{
    puts("Entrer la taille du tableau : ");
    scanf("%d", &n);
}
void saisirTableau(int A[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

void rechercherMaxMin(int A[], int n, int *max, int *min, int *posMax, int *posMin)
{
    int i;

    *max = A[0];
    *min = A[0];
    *posMax = 0;
    *posMin = 0;

    for (i = 1; i < n; i++)
    {
        if (A[i] > *max)
        {
            *max = A[i];
            *posMax = i;
        }

        if (A[i] < *min)
        {
            *min = A[i];
            *posMin = i;
        }
    }
}

void afficherResultat(int max, int min, int posMax, int posMin)
{
    printf("\nLe maximum est : %d\n", max);
    printf("Position du maximum : %d\n", posMax);

    printf("\nLe minimum est : %d\n", min);
    printf("Position du minimum : %d\n", posMin);
}