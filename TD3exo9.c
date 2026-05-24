#include <stdio.h>
#include <string.h>

#define MAX 200

void saisir_chaine(char chaine[]);
int est_carre(char chaine[]);

int main()
{
    char chaine[MAX];

    saisir_chaine(chaine);

    if (est_carre(chaine))
    {
        printf("\"%s\" est une chaine CARREE.\n", chaine);
    }
    else
    {
        printf("\"%s\" n'est PAS une chaine carree.\n", chaine);
    }
    return 0;
}

void saisir_chaine(char chaine[])
{
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine);
}

int est_carre(char chaine[])
{
    int i;
    int len = strlen(chaine);

    if (len % 2 != 0)
    {
        return 0;
    }
    int moitie = len / 2;

    for (i = 0; i < moitie; i++)
    {
        if (chaine[i] != chaine[i + moitie])
        {
            return 0;
        }
    }
    return 1;
}