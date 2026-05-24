#include <stdio.h>

#define MAX 500

void saisir_texte(char texte[]);
int compter_caractere(char texte[], char c);
int compter_suite(char texte[], char suite[]);
void afficher(int nb_a, int nb_es);

int main()
{
    char texte[MAX];
    int nb_a, nb_es;
    saisir_texte(texte);

    nb_a = compter_caractere(texte, 'a');
    nb_es = compter_suite(texte, "es");
    afficher(nb_a, nb_es);

    return 0;
}

void saisir_texte(char texte[])
{
    printf("Entrez un texte (terminez par un point '.') :\n");
    int i = 0;
    char c;
    while ((c = getchar()) != '.' && c != '\n')
    {
        texte[i++] = c;
    }
    texte[i++] = '.';
    texte[i] = '\0';
    printf("Texte saisi : \"%s\"\n", texte);
}

int compter_caractere(char texte[], char c)
{
    int i;
    int count = 0;
    for (i = 0; texte[i] != '.' && texte[i] != '\0'; i++)
    {
        if (texte[i] == c)
        {
            count++;
        }
    }
    return count;
}

int compter_suite(char texte[], char suite[])
{
    int i;
    int count = 0;
    for (i = 0; texte[i] != '.' && texte[i + 1] != '\0'; i++)
    {
        if (texte[i] == suite[0] && texte[i + 1] == suite[1])
        {
            count++;
        }
    }
    return count;
}
