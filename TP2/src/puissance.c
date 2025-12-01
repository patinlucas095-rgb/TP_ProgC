#include <stdio.h>

int main() {
    // Déclaration et initialisation des variables
    int a = 2;      // Base
    int b = 3;      // Exposant
    int resultat = 1;  // Résultat de a^b (initialisé à 1)
    int i;          // Variable pour la boucle
    
    // Affichage des valeurs initiales
    printf("Calcul de %d élevé à la puissance %d\n\n", a, b);
    
    // Cas particuliers
    if (b == 0) {
        // Tout nombre élevé à la puissance 0 égale 1
        resultat = 1;
    } else if (b > 0) {
        // Calcul de la puissance avec une boucle for
        // On multiplie a par lui-même b fois
        for (i = 0; i < b; i++) {
            resultat = resultat * a;
        }
    } else {
        // Exposant négatif (pour information)
        printf("Note : Ce programme gère uniquement les exposants positifs ou nuls.\n");
        printf("Pour les exposants négatifs, le résultat serait un nombre décimal.\n");
        return 1;
    }
    
    // Affichage du résultat
    printf("Résultat : %d^%d = %d\n", a, b, resultat);
    
    printf("\n=== TESTS SUPPLÉMENTAIRES ===\n\n");
    
    // Test avec différentes valeurs
    int tests[][2] = {
        {2, 0},   // 2^0 = 1
        {2, 1},   // 2^1 = 2
        {2, 3},   // 2^3 = 8
        {3, 4},   // 3^4 = 81
        {5, 3},   // 5^3 = 125
        {10, 2},  // 10^2 = 100
        {7, 5}    // 7^5 = 16807
    };
    
    int nombreTests = sizeof(tests) / sizeof(tests[0]);
    
    for (int t = 0; t < nombreTests; t++) {
        int base = tests[t][0];
        int exposant = tests[t][1];
        int res = 1;
        
        // Calcul avec boucle while (méthode alternative)
        int compteur = 0;
        while (compteur < exposant) {
            res = res * base;
            compteur++;
        }
        
        printf("%d^%d = %d\n", base, exposant, res);
    }
    
    printf("\n=== CALCUL TERMINÉ ===\n");
    
    return 0;
}
