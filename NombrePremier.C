#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void afficher_premiers(int n);
void divisible_par_trois(int n);
void remplacer_5_par_V(int n);
void inverse_de_nombre_premier(int n);

int main()
{
    FILE *fichier;
    int n;
    fichier = fopen("fichier test.txt", "a");
    if (fichier == NULL)
    {
        printf("Erreur d'ouverture");
        exit(0);
    }
    fscanf(fichier, "%d", &n);
    fclose(fichier);

    afficher_premiers(n);
    divisible_par_trois(n);
    remplacer_5_par_V(n);
    inverse_de_nombre_premier(n);

    return 0;
}

void afficher_premiers(int n)
{
    printf("Nombres premiers: ");
    for (int i = 2; i <= n; i++)
    {
        int premier = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                premier = 0;
                break;
            }
        }
        if (premier)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void divisible_par_trois(int n)
{
    printf("Divisible par 3: ");
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void remplacer_5_par_V(int n)
{
    printf("Remplacer 5 par V: ");
    for (int i = 1; i <= n; i++)
    {
        if (i == 5)
        {
            printf("V");
        }
        else
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void inverse_de_nombre_premier(int n)
{
    int inv = 0;
    while (n != 0)
    {
        inv = inv * 10 + (n % 10);
        n /= 10;
    }
    printf("l'inverse de nombre premier est:%d\n", inv);
}