#include <stdio.h>
#include <string.h>

#define MAX 500

void saisir_phrase(char phrase[]);
int est_voyelle(char c);
int est_lettre(char c);
void decrypter(char phrase[], char resultat[]);
void afficher(char phrase[], char decrypte[])

    int main()
{
    char phrase[MAX];
    char decrypte[MAX];
    saisir_phrase(phrase);
    decrypter(phrase, decrypte);
    afficher(phrase, decrypte);
    return 0;
}

void saisir_phrase(char phrase[])
{
    printf("Entrez la phrase cryptee : ");
    fgets(phrase, MAX, stdin);
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
    {
        if (c == voyelles[i])
        {
            return 1;
        }
    }
    return 0;
}

int est_lettre(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void decrypter(char phrase[], char resultat[])
{
    int i;
    int j = 0;
    int len = strlen(phrase);

    for (i = 0; i < len; i++)
    {
        if (phrase[i] == 'I' && i + 1 < len && phrase[i + 1] == 'T' && j > 0 && est_lettre(resultat[j - 1]) && !est_voyelle(resultat[j - 1]) && i + 2 < len && est_voyelle(phrase[i + 2]))
        {
            i++;
        }
        else
        {
            resultat[j++] = phrase[i];
        }
    }
    resultat[j] = '\0';
}

void afficher(char phrase[], char decrypte[])
{
    printf("Phrase cryptee   : \"%s\"\n", phrase);
    printf("Phrase decryptee : \"%s\"\n", decrypte);
}