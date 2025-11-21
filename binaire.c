#include <stdio.h>

// Fonction pour afficher un nombre en binaire (méthode avec manipulation de bits)
void afficherBinaire(int nombre) {
    // Pour un int de 32 bits
    int nombreBits = sizeof(int) * 8;
    int premierBit = 0; // Pour éviter d'afficher les zéros de tête
    
    printf("Décimal : %d\n", nombre);
    printf("Binaire : ", nombre);
    
    // Parcourir chaque bit du plus significatif au moins significatif
    for (int i = nombreBits - 1; i >= 0; i--) {
        // Vérifier si le bit à la position i est 1 ou 0
        // En utilisant un masque avec l'opérateur & (ET binaire)
        int bit = (nombre >> i) & 1;
        
        // Afficher le bit (sans les zéros de tête sauf si le nombre est 0)
        if (bit == 1) {
            premierBit = 1;
        }
        
        if (premierBit || i == 0) {
            printf("%d", bit);
            
            // Ajouter des espaces tous les 4 bits pour la lisibilité
            if (i > 0 && i % 4 == 0) {
                printf(" ");
            }
        }
    }
    
    printf("\n");
}

// Fonction alternative pour afficher en binaire (méthode avec division)
void afficherBinaireDiv(int nombre) {
    if (nombre == 0) {
        printf("0");
        return;
    }
    
    // Stocker les bits dans un tableau
    int bits[32];
    int index = 0;
    int temp = nombre;
    
    // Extraire chaque bit en utilisant % et /
    while (temp > 0) {
        bits[index] = temp % 2;
        temp = temp / 2;
        index++;
    }
    
    // Afficher les bits dans l'ordre inverse
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", bits[i]);
        if (i > 0 && i % 4 == 0) {
            printf(" ");
        }
    }
}

int main() {
    // Tableau des nombres à tester
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("=== AFFICHAGE EN BINAIRE (Méthode manipulation de bits) ===\n\n");
    
    for (int i = 0; i < taille; i++) {
        afficherBinaire(nombres[i]);
        printf("\n");
    }
    
    printf("\n=== AFFICHAGE EN BINAIRE (Méthode division/modulo) ===\n\n");
    
    for (int i = 0; i < taille; i++) {
        printf("Décimal : %d\n", nombres[i]);
        printf("Binaire : ");
        afficherBinaireDiv(nombres[i]);
        printf("\n\n");
    }
    
    // Démonstration des opérateurs de bits
    printf("=== DÉMONSTRATION DES OPÉRATEURS DE BITS ===\n\n");
    
    int a = 12;  // 1100 en binaire
    int b = 10;  // 1010 en binaire
    
    printf("a = %d (binaire: ", a);
    afficherBinaireDiv(a);
    printf(")\n");
    
    printf("b = %d (binaire: ", b);
    afficherBinaireDiv(b);
    printf(")\n\n");
    
    printf("a & b = %d (binaire: ", a & b);
    afficherBinaireDiv(a & b);
    printf(") - ET binaire\n");
    
    printf("a | b = %d (binaire: ", a | b);
    afficherBinaireDiv(a | b);
    printf(") - OU binaire\n");
    
    printf("~a = %d (binaire avec complément à deux) - NON binaire\n", ~a);
    
    printf("a << 2 = %d (binaire: ", a << 2);
    afficherBinaireDiv(a << 2);
    printf(") - Décalage gauche\n");
    
    printf("a >> 2 = %d (binaire: ", a >> 2);
    afficherBinaireDiv(a >> 2);
    printf(") - Décalage droite\n");
    
    return 0;
}
