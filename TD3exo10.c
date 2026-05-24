#include <stdio.h>
#include <string.h>

void saisir_phrase(char phrase[]);
int est_voyelle(char c);
int est_lettre(char c);
void crypter(char phrase[], char resultat[]);
void afficher(char phrase[], char crypte[]);

int main()
{
    char phrase[500];
    char crypte[500];
    saisir_phrase(phrase);
    crypter(phrase, crypte);
    afficher(phrase, crypte);
    return 0;
}

void saisir_phrase(char phrase[])
{
    printf("Entrez une phrase (lettres uniquement) : ");
    fgets(phrase, 500, stdin);
    int len = strlen(phrase);
    if (phrase[len - 1] == '\n')
    {
        phrase[len - 1] = '\0';
    }
}

int est_voyelle(char c)
{
    int i;
    char voyelles[] = "aeiouAEIOUyY";
    for (i = 0; voyelles[i] != '\0'; i++)
        if (c == voyelles[i])
            return 1;
    return 0;
}

int est_lettre(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void crypter(char phrase[], char resultat[])
{
    int i;
    int j = 0;
    int len = strlen(phrase);

    for (i = 0; i < len; i++)
    {
        resultat[j++] = phrase[i];

        if (est_lettre(phrase[i]) && !est_voyelle(phrase[i]) && i + 1 < len && est_voyelle(phrase[i + 1]))
        {
            resultat[j++] = 'I';
            resultat[j++] = 'T';
        }
    }
    resultat[j] = '\0';
}

void afficher(char phrase[], char crypte[])
{
    printf("Phrase originale : \"%s\"\n", phrase);
    printf("Phrase cryptee   : \"%s\"\n", crypte);
}