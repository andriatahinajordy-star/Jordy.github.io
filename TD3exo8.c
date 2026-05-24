#include <stdio.h>
#include <string.h>

#define MAX 200

void saisir_chaine(char chaine[], char msg[]);
int compter_bigramme(char chaine[], char bigramme[]);

int main()
{
    char chaine[MAX];
    char bigramme[3];

    saisir_chaine(chaine, "Entrez la chaine de caracteres : ");
    saisir_chaine(bigramme, "Entrez le bigramme (2 lettres) : ");

    int nb = compter_bigramme(chaine, bigramme);

    printf("\nLe bigramme \"%s\" apparait %d fois dans \"%s\".\n",
           bigramme, nb, chaine);

    return 0;
}

void saisir_chaine(char chaine[], char msg[])
{
    printf("%s", msg);
    scanf("%s", chaine);
}

int compter_bigramme(char chaine[], char bigramme[])
{
    int int count = 0;
    int len = strlen(chaine);

    for (i = 0; i < len - 1; i++)
    {
        if (chaine[i] == bigramme[0] && chaine[i + 1] == bigramme[1])
        {
            count++;
        }
    }
    return count;
}