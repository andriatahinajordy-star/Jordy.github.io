#include <stdio.h>

void recup(int *degre);
void construire_pascal(int triangle[][20], int degre);
void afficher_pascal(int triangle[][20], int degre);

int main()
{
    int triangle[20][20];
    recup(&degre);
    construire_pascal(triangle, degre);
    afficher_pascal(triangle, degre);
    return 0;
}

void recup(int *degre)
{
    printf("Entrez le degre N du triangle : ");
    scanf("%d", degre);
}
void construire_pascal(int triangle[][20], int degre)
{
    int i, j;
    for (i = 0; i <= degre; i++)
    {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

void afficher_pascal(int triangle[][20], int degre)
{
    int i, j, k;
    printf("\nTriangle de Pascal de degre %d :\n\n", degre);
    for (i = 0; i <= degre; i++)
    {
        for (k = 0; k < degre - i; k++)
            printf("  ");
        for (j = 0; j <= i; j++)
        {
            printf("%4d", triangle[i][j]);
        }
        printf("\n");
    }
}
