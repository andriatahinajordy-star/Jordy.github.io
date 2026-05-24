#include <stdio.h>
#include <math.h>

#define MAX 100

void recup(int *taille);
void saisir_tableau(int tab[], int taille);
double calculer_moyenne(int tab[], int taille);
int element_proche_moyenne(int tab[], int taille, double moyenne);
void afficher_tableau(int tab[], int taille);
void afficherMoyenne(float moy);

int main()
{
    int tab[MAX];
    int taille;
    recup(&taille);
    saisir_tableau(tab, taille);
    printf("Tableau : ");
    afficher_tableau(tab, taille);
    double moy = calculer_moyenne(tab, taille);
    int proche = element_proche_moyenne(tab, taille, moy);
    afficherMoyenne(moy, proche);
    return 0;
}

void recup(int *taille)
{
    printf("Entrez la taille du tableau : ");
    scanf("%d", taille);
}
void saisir_tableau(int tab[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("  tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
}

void afficher_tableau(int tab[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

double calculer_moyenne(int tab[], int taille)
{
    int i;
    double somme = 0;
    for (i = 0; i < taille; i++)
    {
        somme += tab[i];
    }
    return somme / taille;
}

int element_proche_moyenne(int tab[], int taille, double moyenne)
{
    int plus_proche = tab[0];
    double diff_min = fabs(tab[0] - moyenne);

    for (int i = 1; i < taille; i++)
    {
        double diff = fabs(tab[i] - moyenne);
        if (diff < diff_min)
        {
            diff_min = diff;
            plus_proche = tab[i];
        }
    }
    return plus_proche;
}
void afficher(float moy, int proche)
{
    printf("Moyenne = %.2f\n", moy);
    printf("Element le plus proche de la moyenne : %d\n", proche);
}