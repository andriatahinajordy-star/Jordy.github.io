#include <stdio.h>

int saisirTaille();
void remplir(int T[], int n);
void separer(int T[], int n, int TPOS[], int *pos, int TNEG[], int *neg);
void afficher(int TPOS[], int pos, int TNEG[], int neg);

int main()
{
    int n = saisirTaille();
    int T[n], TPOS[n], TNEG[n];
    int pos = 0, neg = 0;

    remplir(T, n);
    separer(T, n, TPOS, &pos, TNEG, &neg);
    afficher(TPOS, pos, TNEG, neg);

    return 0;
}

int saisirTaille()
{
    int n;
    printf("Taille : ");
    scanf("%d", &n);
    return n;
}

void remplir(int T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &T[i]);
    }
}

void separer(int T[], int n, int TPOS[], int *pos, int TNEG[], int *neg)
{
    for (int i = 0; i < n; i++)
    {
        if (T[i] > 0)
        {
            TPOS[*pos] = T[i];
            (*pos)++;
        }
        else if (T[i] < 0)
        {
            TNEG[*neg] = T[i];
            (*neg)++;
        }
    }
}

void afficher(int TPOS[], int pos, int TNEG[], int neg)
{
    printf("\nTPOS : ");
    for (int i = 0; i < pos; i++)
    {
        printf("%d ", TPOS[i]);
    }

    printf("\nTNEG : ");
    for (int i = 0; i < neg; i++)
    {
        printf("%d ", TNEG[i]);
        printf("\n");
    }
}