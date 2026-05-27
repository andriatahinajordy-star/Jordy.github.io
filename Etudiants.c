#include <stdio.h>
#include <string.h>

struct etudiant
{
    char nom[50];
    char prenom[60];
    char date_naissance[12];
    char lieu_naissance[15];
    char adresse[20];
    char email[50];
    char num_inscription[20];
};

void DemanderNombreEtudiants(int *n);
void saisirTableauEtudiants(struct etudiant t[], int n);
void afficherEtudiants(struct etudiant t[], int n);
void trierTableauEtudiants(struct etudiant t[], int n);
void afficherListeTableauEtudiants(struct etudiant t[], int n);
void rechercherEtudiants(struct etudiant t[], int n);
void supprimerEtudiants(struct etudiant t[], int *n);

int main()
{
    int n;
    DemanderNombreEtudiants(&n);
    struct etudiant t[n];

    saisirTableauEtudiants(t, n);

    printf("\n--- AVANT TRI ---");
    afficherEtudiants(t, n);

    trierTableauEtudiants(t, n);

    printf("\n--- APRES TRI (Par Nom) ---");
    afficherListeTableauEtudiants(t, n);

    rechercherEtudiants(t, n);

    supprimerEtudiants(t, &n);

    printf("\n--- APRES SUPPRESSION ---");
    afficherListeTableauEtudiants(t, n);

    return 0;
}

void DemanderNombreEtudiants(int *n)
{
    printf("Entrez le nombre d'etudiants a inscrire : ");
    scanf("%d", n);

    while (*n <= 0)
    {
        printf("Nombre invalide. Recommencez : ");
        scanf("%d", n);
    }
}

void saisirTableauEtudiants(struct etudiant t[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n-- SAISIE DE L'ETUDIANT %d --\n", i + 1);

        printf("Nom : ");
        scanf("%s", t[i].nom);

        printf("Prenom : ");
        scanf("%s", t[i].prenom);

        printf("Date de naissance (JJ/MM/AAAA) : ");
        scanf("%s", t[i].date_naissance);

        printf("Lieu de naissance : ");
        scanf("%s", t[i].lieu_naissance);

        printf("Adresse : ");
        scanf("%s", t[i].adresse);

        printf("Email : ");
        scanf("%s", t[i].email);

        printf("Numero d'inscription : ");
        scanf("%s", t[i].num_inscription);
    }
}

void afficherEtudiants(struct etudiant t[], int n)
{
    int i;
    printf("\n ==== LISTE DES ETUDIANTS ====\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEtudiant %d :\n", i + 1);
        printf("  Nom : %s\n", t[i].nom);
        printf("  Prenom : %s\n", t[i].prenom);
        printf("  Date de naissance : %s\n", t[i].date_naissance);
        printf("  Lieu de naissance : %s\n", t[i].lieu_naissance);
        printf("  Adresse : %s\n", t[i].adresse);
        printf("  Email : %s\n", t[i].email);
        printf("  Numero d'inscription : %s\n", t[i].num_inscription);
    }
}

void trierTableauEtudiants(struct etudiant t[], int n)
{
    int i, j;
    struct etudiant temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(t[j].nom, t[j + 1].nom) > 0)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

void afficherListeTableauEtudiants(struct etudiant t[], int n)
{
    int i;
    printf("\n===== AFFICHAGE DE LA LISTE DES ETUDIANTS EN TABLEAU =====\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-15s | %-20s | %-15s |\n", "N° Inscription", "Nom", "Prenom", "Email", "Lieu nais.");
    printf("---------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("| %-14s | %-15s | %-15s | %-20s | %-15s |\n",
               t[i].num_inscription,
               t[i].nom,
               t[i].prenom,
               t[i].email,
               t[i].lieu_naissance);
    }
    printf("---------------------------------------------------------------------------------------------------\n");
}

void rechercherEtudiants(struct etudiant t[], int n)
{
    int i;
    char num_recherche[20];
    printf("\n--- RECHERCHE D'UN ETUDIANT ---\n");
    printf("Entrez le numero d'inscription de l'etudiant a rechercher : ");
    scanf("%s", num_recherche);

    for (i = 0; i < n; i++)
    {
        if (strcmp(t[i].num_inscription, num_recherche) == 0)
        {
            printf("\n[+] Etudiant trouve (position %d) :\n", i + 1);
            printf("Nom: %s, Prenom: %s, Email: %s\n", t[i].nom, t[i].prenom, t[i].email);
            return;
        }
    }
    printf("\n[-] Aucun etudiant avec le numero %s.\n", num_recherche);
}

void supprimerEtudiants(struct etudiant t[], int *n)
{
    int i, j;
    char num_suppr[20];
    printf("\n--- SUPPRESSION D'UN ETUDIANT ---\n");
    printf("Entrez le numero d'inscription de l'etudiant a supprimer : ");
    scanf("%s", num_suppr);

    for (i = 0; i < *n; i++)
    {
        if (strcmp(t[i].num_inscription, num_suppr) == 0)
        {
            for (j = i; j < (*n) - 1; j++)
            {
                t[j] = t[j + 1];
            }
            (*n)--;
            printf("\n[+] Etudiant %s supprime avec succes.\n", num_suppr);
            return;
        }
    }
    printf("\n[-] Impossible de supprimer : numero %s introuvable.\n", num_suppr);
}