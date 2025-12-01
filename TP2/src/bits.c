#include <stdio.h>

int main() {
    // Déclaration et initialisation de la variable
    int d = 0x08100000;  // Exemple : bits 4 et 20 de gauche sont à 1
    
    // Variables pour stocker les bits extraits
    int bit4;    // 4ème bit de gauche
    int bit20;   // 20ème bit de gauche
    int resultat;
    
    // Nombre total de bits dans un int (32 bits)
    int nombreBits = sizeof(int) * 8;
    
    // Affichage de la valeur en différents formats
    printf("=== VÉRIFICATION DES BITS ===\n\n");
    printf("Valeur de d (décimal) : %d\n", d);
    printf("Valeur de d (hexadécimal) : 0x%X\n", d);
    printf("Valeur de d (binaire) : ");
    
    // Affichage en binaire pour visualisation
    for (int i = nombreBits - 1; i >= 0; i--) {
        printf("%d", (d >> i) & 1);
        if (i > 0 && i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n\n");
    
    // Extraction du 4ème bit de gauche
    // Le 4ème bit de gauche correspond au bit à la position (32 - 4) = 28
    // On décale d de 28 positions vers la droite et on applique un masque avec 1
    bit4 = (d >> (nombreBits - 4)) & 1;
    
    // Extraction du 20ème bit de gauche
    // Le 20ème bit de gauche correspond au bit à la position (32 - 20) = 12
    // On décale d de 12 positions vers la droite et on applique un masque avec 1
    bit20 = (d >> (nombreBits - 20)) & 1;
    
    // Affichage des bits extraits
    printf("4ème bit de gauche : %d\n", bit4);
    printf("20ème bit de gauche : %d\n", bit20);
    printf("\n");
    
    // Vérification si les deux bits sont à 1
    resultat = (bit4 == 1 && bit20 == 1) ? 1 : 0;
    
    // Affichage du résultat
    printf("Résultat de la vérification : %d\n", resultat);
    
    if (resultat == 1) {
        printf("✓ Les bits 4 et 20 de gauche sont tous les deux à 1\n");
    } else {
        printf("✗ Au moins un des bits (4 ou 20) n'est pas à 1\n");
    }
    
    printf("\n=== TESTS SUPPLÉMENTAIRES ===\n\n");
    
    // Test avec différentes valeurs
    int valeurs_test[] = {
        0x08100000,  // Bits 4 et 20 à 1 → Résultat : 1
        0x00100000,  // Seulement bit 20 à 1 → Résultat : 0
        0x08000000,  // Seulement bit 4 à 1 → Résultat : 0
        0x00000000,  // Aucun bit à 1 → Résultat : 0
        0xFFFFFFFF   // Tous les bits à 1 → Résultat : 1
    };
    
    int nb_tests = sizeof(valeurs_test) / sizeof(valeurs_test[0]);
    
    for (int t = 0; t < nb_tests; t++) {
        int val = valeurs_test[t];
        int b4 = (val >> (nombreBits - 4)) & 1;
        int b20 = (val >> (nombreBits - 20)) & 1;
        int res = (b4 == 1 && b20 == 1) ? 1 : 0;
        
        printf("Valeur 0x%08X : bit4=%d, bit20=%d → Résultat=%d\n", 
               val, b4, b20, res);
    }
    
    printf("\n=== EXPLICATION DES OPÉRATIONS ===\n");
    printf("Pour un int de 32 bits :\n");
    printf("- 4ème bit de gauche = bit à la position 28 (32-4)\n");
    printf("- 20ème bit de gauche = bit à la position 12 (32-20)\n");
    printf("- Opération : (d >> position) & 1\n");
    printf("  * >> décale les bits vers la droite\n");
    printf("  * & 1 extrait le bit le plus à droite\n");
    
    return 0;
}
