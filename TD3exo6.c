#include <stdio.h>
#include <string.h>

#define MAX 200

void saisir_chaine(char chaine[]);
int est_palindrome(char chaine[]);

int main()
{
    char chaine[MAX];

    saisir_chaine(chaine);

    if (est_palindrome(chaine))
    {
        printf("\"%s\" est un PALINDROME.\n", chaine);
    }
    else
    {
        printf("\"%s\" n'est PAS un palindrome.\n", chaine);
    }
    return 0;
}

void saisir_chaine(char chaine[])
{
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine);
}

int est_palindrome(char chaine[])
{
    int i;
    int len = strlen(chaine);
    for (i = 0; i < len / 2; i++)
    {
        if (chaine[i] != chaine[len - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}