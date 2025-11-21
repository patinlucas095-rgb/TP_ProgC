#include <stdio.h>

int main() {
    // Déclaration et initialisation des variables
    int a = 16;
    int b = 3;
    
    printf("=== Test des opérateurs arithmétiques et logiques ===\n\n");
    printf("Valeurs initiales :\n");
    printf("a = %d\n", a);
    printf("b = %d\n\n", b);
    
    // 1. Addition
    printf("1. Addition :\n");
    int somme = a + b;
    printf("   a + b = %d + %d = %d\n\n", a, b, somme);
    
    // 2. Soustraction
    printf("2. Soustraction :\n");
    int difference = a - b;
    printf("   a - b = %d - %d = %d\n\n", a, b, difference);
    
    // 3. Multiplication
    printf("3. Multiplication :\n");
    int produit = a * b;
    printf("   a * b = %d * %d = %d\n\n", a, b, produit);
    
    // 4. Division
    printf("4. Division :\n");
    int quotient = a / b;
    float division_reelle = (float)a / b;
    printf("   a / b = %d / %d = %d (division entière)\n", a, b, quotient);
    printf("   a / b = %.2f (division réelle)\n\n", division_reelle);
    
    // 5. Modulo
    printf("5. Modulo (reste de la division) :\n");
    int reste = a % b;
    printf("   a %% b = %d %% %d = %d\n\n", a, b, reste);
    
    // 6. Égalité
    printf("6. Test d'égalité (a == b) :\n");
    int est_egal = (a == b);
    printf("   a == b : %d (0 = faux, 1 = vrai)\n", est_egal);
    if (est_egal) {
        printf("   Résultat : a est égal à b\n\n");
    } else {
        printf("   Résultat : a n'est pas égal à b\n\n");
    }
    
    // 7. Supériorité
    printf("7. Test de supériorité (a > b) :\n");
    int est_superieur = (a > b);
    printf("   a > b : %d (0 = faux, 1 = vrai)\n", est_superieur);
    if (est_superieur) {
        printf("   Résultat : a est supérieur à b\n\n");
    } else {
        printf("   Résultat : a n'est pas supérieur à b\n\n");
    }
    
    // Bonus : autres opérateurs de comparaison
    printf("=== Opérateurs de comparaison supplémentaires ===\n");
    printf("   a != b (différent)        : %d\n", a != b);
    printf("   a < b (inférieur)         : %d\n", a < b);
    printf("   a >= b (supérieur ou égal): %d\n", a >= b);
    printf("   a <= b (inférieur ou égal): %d\n\n", a <= b);
    
    // Bonus : opérateurs logiques
    printf("=== Opérateurs logiques ===\n");
    printf("   (a > 10) && (b < 5) (ET)  : %d\n", (a > 10) && (b < 5));
    printf("   (a < 10) || (b < 5) (OU)  : %d\n", (a < 10) || (b < 5));
    printf("   !(a == b) (NON)           : %d\n\n", !(a == b));
    
    printf("=== Programme terminé avec succès ===\n");
    
    return 0;
}
