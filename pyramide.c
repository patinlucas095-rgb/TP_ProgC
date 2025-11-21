#include <stdio.h>

int main() {
    // Déclaration des variables
    int n;      // Hauteur de la pyramide
    int i, j;   // Variables pour les boucles imbriquées
    
    // Initialisation de la hauteur de la pyramide
    printf("Entrez la hauteur de la pyramide : ");
    scanf("%d", &n);
    
    printf("\n=== GÉNÉRATION DE LA PYRAMIDE ===\n\n");
    
    // Boucle principale pour chaque niveau de la pyramide
    for (i = 1; i <= n; i++) {
        
        // Boucle pour afficher les espaces (centrer la pyramide)
        // Nombre d'espaces = n - i
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        
        // Boucle pour afficher les nombres croissants (1 à i)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Boucle pour afficher les nombres décroissants (i-1 à 1)
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        // Passer à la ligne suivante après chaque niveau
        printf("\n");
    }
    
    printf("\n=== GÉNÉRATION DE LA PYRAMIDE TERMINÉE ===\n");
    
    // Affichage d'informations supplémentaires
    printf("\nInformations sur la pyramide :\n");
    printf("- Hauteur : %d niveaux\n", n);
    printf("- Largeur maximale : %d caractères\n", 2 * n - 1);
    printf("- Nombre total de chiffres affichés : %d\n", n * n);
    
    return 0;
}
