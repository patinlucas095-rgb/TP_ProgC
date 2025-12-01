#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100
#define VALEUR_MIN 1
#define VALEUR_MAX 1000

int main() {
    int tableau[TAILLE];
    int plus_grand, plus_petit;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("========================================\n");
    printf("RECHERCHE DU PLUS GRAND ET PLUS PETIT\n");
    printf("========================================\n\n");
    
    // Remplissage du tableau avec des valeurs aléatoires
    printf("Génération de %d valeurs aléatoires entre %d et %d...\n\n", 
           TAILLE, VALEUR_MIN, VALEUR_MAX);
    
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % VALEUR_MAX + VALEUR_MIN;
    }
    
    // Affichage des 10 premières valeurs du tableau
    printf("Aperçu des 10 premières valeurs du tableau :\n");
    for (int i = 0; i < 10; i++) {
        printf("%d", tableau[i]);
        if (i < 9) printf(", ");
    }
    printf(", ...\n\n");
    
    // Initialisation avec la première valeur du tableau
    plus_grand = tableau[0];
    plus_petit = tableau[0];
    
    // Parcours du tableau pour trouver le plus grand et le plus petit
    for (int i = 1; i < TAILLE; i++) {
        if (tableau[i] > plus_grand) {
            plus_grand = tableau[i];
        }
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }
    
    // Affichage des résultats
    printf("========================================\n");
    printf("RÉSULTATS\n");
    printf("========================================\n\n");
    printf("Le numéro le plus grand est : %d\n", plus_grand);
    printf("Le numéro le plus petit est : %d\n\n", plus_petit);
    
    // Informations supplémentaires
    printf("Différence entre le plus grand et le plus petit : %d\n", 
           plus_grand - plus_petit);
    printf("========================================\n");
    
    return 0;
}
