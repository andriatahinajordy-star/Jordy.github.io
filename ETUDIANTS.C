#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Etudiant
{
    int num_inscription;
    char nom[20];
    char prenom[50];
    char date_naissance[12];
    char lieu_naissance[50];
    char adresse[100];
    char niveau[20];
    char email[60];
    char telephone[20];
};

void recup(int *N);
void saisirTableau(Etudiant tab[], int taille);
void trierTableau(Etudiant tab[], int taille);
void afficherTableauEtudiants(Etudiant tab[], int taille);
void afficherEtudiant(Etudiant e);
void afficherListeTableau(Etudiant tab[], int taille);
void rechercherEtudiant(Etudiant tab[], int taille);
void supprimerEtudiant(Etudiant tab[], int *taille);

void recup(int *N)
{
    float r;
    do
    {
        printf("Entrez le nombre d'etudiants : ");
        if (scanf("%f", &r) != 1)
        {
            getchar();
            continue;
        }
        getchar();
        *N = (int)r;

        if (*N <= 0)
        {
            printf("Erreur : doit etre > 0. Recommencez.\n\n");
        }
    } while (*N <= 0);

    printf("Conversion : %.2f -> %d etudiant(s).\n", r, *N);
}

void saisirTableau(Etudiant tab[], int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("\n-- Etudiant n°%d --\n", i + 1);

        printf("Numero d'inscription : ");
        scanf("%d", &tab[i].num_inscription);
        getchar();

        printf("Nom          : ");
        fgets(tab[i].nom, 20, stdin);
        tab[i].nom[strcspn(tab[i].nom, "\n")] = '\0';

        printf("Prenom       : ");
        fgets(tab[i].prenom, 50, stdin);
        tab[i].prenom[strcspn(tab[i].prenom, "\n")] = '\0';

        printf("Date naissance  : ");
        fgets(tab[i].date_naissance, 12, stdin);
        tab[i].date_naissance[strcspn(tab[i].date_naissance, "\n")] = '\0';

        printf("Lieu naissance  : ");
        fgets(tab[i].lieu_naissance, 50, stdin);
        tab[i].lieu_naissance[strcspn(tab[i].lieu_naissance, "\n")] = '\0';

        printf("Adresse      : ");
        fgets(tab[i].adresse, 100, stdin);
        tab[i].adresse[strcspn(tab[i].adresse, "\n")] = '\0';

        printf("Niveau       : ");
        fgets(tab[i].niveau, 20, stdin);
        tab[i].niveau[strcspn(tab[i].niveau, "\n")] = '\0';

        printf("Email        : ");
        fgets(tab[i].email, 60, stdin);
        tab[i].email[strcspn(tab[i].email, "\n")] = '\0';

        printf("Telephone    : ");
        fgets(tab[i].telephone, 20, stdin);
        tab[i].telephone[strcspn(tab[i].telephone, "\n")] = '\0';
    }
}

void trierTableau(Etudiant tab[], int taille)
{
    int i, j;
    Etudiant temp;

    for (i = 0; i < taille - 1; i++)
    {
        for (j = 0; j < taille - i - 1; j++)
        {
            if (strcmp(tab[j].nom, tab[j + 1].nom) > 0)
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void afficherTableauEtudiants(Etudiant tab[], int taille)
{
    int i;
    printf("\n===== AFFICHAGE DETAILLE =====\n");
    for (i = 0; i < taille; i++)
    {
        afficherEtudiant(tab[i]);
    }
}

void afficherEtudiant(Etudiant e)
{
    printf("N° Inscription : %d\n", e.num_inscription);
    printf("Nom            : %s\n", e.nom);
    printf("Prenom         : %s\n", e.prenom);
    printf("Niveau         : %s\n", e.niveau);
    printf("Ne(e) le       : %s a %s\n", e.date_naissance, e.lieu_naissance);
    printf("Adresse        : %s\n", e.adresse);
    printf("Email          : %s\n", e.email);
    printf("Telephone      : %s\n", e.telephone);
    printf("-------------------------------------------------\n");
}

void afficherListeTableau(Etudiant tab[], int taille)
{
    int i;
    printf("\n===== AFFICHAGE DE LA LISTE DES ETUDIANTS EN TABLEAU =====\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-15s | %-15s | %-10s | %-15s |\n", "N°", "Nom", "Prenom", "Niveau", "Telephone");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < taille; i++)
    {
        printf("| %-5d | %-15s | %-15s | %-10s | %-15s |\n",
               tab[i].num_inscription,
               tab[i].nom,
               tab[i].prenom,
               tab[i].niveau,
               tab[i].telephone);
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");
}

void rechercherEtudiant(Etudiant tab[], int taille)
{
    int i, num;
    printf("\n--- RECHERCHE D'UN ETUDIANT ---\n");
    printf("Entrez le numero d'inscription de l'etudiant a rechercher : ");
    scanf("%d", &num);
    getchar();

    for (i = 0; i < taille; i++)
    {
        if (tab[i].num_inscription == num)
        {
            printf("\nEtudiant trouve (position %d) :\n", i + 1);
            afficherEtudiant(tab[i]);
            return;
        }
    }
    printf("\nAucun etudiant avec le numero %d.\n", num);
}

void supprimerEtudiant(Etudiant tab[], int *taille)
{
    int i, j, num;
    printf("\n--- SUPPRESSION D'UN ETUDIANT ---\n");
    printf("Entrez le numero d'inscription de l'etudiant a supprimer : ");
    scanf("%d", &num);
    getchar();

    for (i = 0; i < *taille; i++)
    {
        if (tab[i].num_inscription == num)
        {
            for (j = i; j < (*taille) - 1; j++)
            {
                tab[j] = tab[j + 1];
            }
            (*taille)--;
            printf("\nEtudiant %d supprime avec succes.\n", num);
            return;
        }
    }
    printf("\nImpossible de supprimer : numero %d introuvable.\n", num);
}

int main()
{
    int taille = 0;

    recup(&taille);

    Etudiant repertoire[taille];

    saisirTableau(repertoire, taille);

    trierTableau(repertoire, taille);

    afficherListeTableau(repertoire, taille);

    rechercherEtudiant(repertoire, taille);
    supprimerEtudiant(repertoire, &taille);

    trierTableau(repertoire, taille);
    afficherListeTableau(repertoire, taille);

    return 0;
}