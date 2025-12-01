#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100
#define VALEUR_MIN -50
#define VALEUR_MAX 50

// Fonction pour afficher le tableau
void afficher_tableau(int *tableau, int taille, int elements_par_ligne) {
    for (int i = 0; i < taille; i++) {
        printf("%4d", tableau[i]);
        if ((i + 1) % elements_par_ligne == 0) {
            printf("\n");
        } else if (i < taille - 1) {
            printf(" ");
        }
    }
    if (taille % elements_par_ligne != 0) {
        printf("\n");
    }
}

// Fonction de recherche linéaire
int rechercher_entier(int *tableau, int taille, int valeur) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            return i;  // Retourne l'indice où l'entier est trouvé
        }
    }
    return -1;  // Retourne -1 si l'entier n'est pas trouvé
}

// Fonction pour compter le nombre d'occurrences
int compter_occurrences(int *tableau, int taille, int valeur) {
    int compteur = 0;
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            compteur++;
        }
    }
    return compteur;
}

// Fonction pour afficher toutes les positions
void afficher_positions(int *tableau, int taille, int valeur) {
    printf("Positions trouvées : ");
    int premiere = 1;
    for (int i = 0; i < taille; i++) {
        if (tableau[i] == valeur) {
            if (!premiere) {
                printf(", ");
            }
            printf("%d", i);
            premiere = 0;
        }
    }
    printf("\n");
}

int main() {
    int tableau[TAILLE];
    int valeur_recherchee;
    int resultat;
    int occurrences;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("========================================\n");
    printf("PROGRAMME DE RECHERCHE DANS UN TABLEAU\n");
    printf("========================================\n\n");
    
    // Remplissage du tableau avec des valeurs aléatoires
    printf("Génération de %d valeurs aléatoires entre %d et %d...\n\n", 
           TAILLE, VALEUR_MIN, VALEUR_MAX);
    
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % (VALEUR_MAX - VALEUR_MIN + 1) + VALEUR_MIN;
    }
    
    // Affichage du tableau
    printf("========================================\n");
    printf("TABLEAU :\n");
    printf("========================================\n");
    afficher_tableau(tableau, TAILLE, 10);
    printf("\n");
    
    // Demande à l'utilisateur d'entrer l'entier à rechercher
    printf("========================================\n");
    printf("Entrez l'entier que vous souhaitez chercher : ");
    
    if (scanf("%d", &valeur_recherchee) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }
    printf("\n");
    
    // Recherche de l'entier dans le tableau
    resultat = rechercher_entier(tableau, TAILLE, valeur_recherchee);
    
    // Affichage du résultat
    printf("========================================\n");
    printf("RÉSULTAT :\n");
    printf("========================================\n");
    
    if (resultat != -1) {
        printf("Résultat : entier présent\n\n");
        
        // Informations supplémentaires
        occurrences = compter_occurrences(tableau, TAILLE, valeur_recherchee);
        printf("Informations détaillées :\n");
        printf("- Première position trouvée : %d\n", resultat);
        printf("- Nombre d'occurrences : %d\n", occurrences);
        
        if (occurrences > 1) {
            printf("- ");
            afficher_positions(tableau, TAILLE, valeur_recherchee);
        }
    } else {
        printf("Résultat : entier absent\n");
    }
    
    printf("========================================\n");
    
    return 0;
}
