#include <stdio.h>

int main() {
    // Déclaration des variables
    int n;              // Nombre de termes à générer
    int u0, u1, un;     // Termes de la suite de Fibonacci
    int i;              // Variable pour la boucle
    
    // Demander à l'utilisateur le nombre de termes
    printf("=== SUITE DE FIBONACCI ===\n\n");
    printf("Entrez le nombre de termes à générer (n) : ");
    scanf("%d", &n);
    
    // Vérification que n est positif
    if (n < 0) {
        printf("Erreur : n doit être un nombre positif ou nul.\n");
        return 1;
    }
    
    printf("\nSuite de Fibonacci jusqu'à U%d :\n", n);
    
    // Cas particuliers
    if (n == 0) {
        printf("U0 = 0\n");
        return 0;
    }
    
    // Initialisation des deux premiers termes
    u0 = 0;  // U0 = 0
    u1 = 1;  // U1 = 1
    
    // Affichage de U0
    printf("U0 = %d\n", u0);
    
    if (n >= 1) {
        // Affichage de U1
        printf("U1 = %d\n", u1);
    }
    
    // Calcul et affichage des termes suivants
    for (i = 2; i <= n; i++) {
        // Formule : Un = Un-1 + Un-2
        un = u1 + u0;
        
        printf("U%d = %d\n", i, un);
        
        // Mise à jour des valeurs pour le prochain calcul
        u0 = u1;  // L'ancien U1 devient le nouveau U0
        u1 = un;  // L'actuel Un devient le nouveau U1
    }
    
    printf("\n=== Affichage compact ===\n");
    printf("Suite : ");
    
    // Réinitialisation pour affichage compact
    u0 = 0;
    u1 = 1;
    printf("%d", u0);
    
    if (n >= 1) {
        printf(", %d", u1);
    }
    
    for (i = 2; i <= n; i++) {
        un = u1 + u0;
        printf(", %d", un);
        u0 = u1;
        u1 = un;
    }
    
    printf("\n\n=== GÉNÉRATION TERMINÉE ===\n");
    
    // Informations supplémentaires
    printf("\nInformations :\n");
    printf("- Formule : Un = Un-1 + Un-2\n");
    printf("- U0 = 0 (par définition)\n");
    printf("- U1 = 1 (par définition)\n");
    printf("- Nombre de termes générés : %d\n", n + 1);
    
    // Afficher quelques propriétés mathématiques
    if (n >= 2) {
        printf("\nPropriétés observées :\n");
        printf("- Chaque terme est la somme des deux termes précédents\n");
        printf("- Cette suite apparaît dans de nombreux phénomènes naturels\n");
        printf("- Le rapport entre deux termes consécutifs tend vers le nombre d'or (φ ≈ 1.618)\n");
    }
    
    return 0;
}
