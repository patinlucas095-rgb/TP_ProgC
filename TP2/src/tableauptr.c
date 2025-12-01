#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 11

void afficher_tableau_int(int *ptr, int taille) {
    int *p = ptr;
    for (int i = 0; i < taille; i++) {
        if (i > 0) printf(", ");
        printf("%d", *p);
        p++;
    }
    printf("\n");
}

void afficher_tableau_float(float *ptr, int taille) {
    float *p = ptr;
    for (int i = 0; i < taille; i++) {
        if (i > 0) printf(", ");
        printf("%.2f", *p);
        p++;
    }
    printf("\n");
}

void remplir_tableau_int(int *ptr, int taille) {
    int *p = ptr;
    for (int i = 0; i < taille; i++) {
        *p = rand() % 150 + 1;  // Valeurs aléatoires entre 1 et 150
        p++;
    }
}

void remplir_tableau_float(float *ptr, int taille) {
    float *p = ptr;
    for (int i = 0; i < taille; i++) {
        *p = (float)(rand() % 1000) / 100.0f;  // Valeurs aléatoires entre 0.00 et 9.99
        p++;
    }
}

void multiplier_indices_pairs_int(int *ptr, int taille) {
    int *p = ptr;
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {
            *p = *p * 3;
        }
        p++;
    }
}

void multiplier_indices_pairs_float(float *ptr, int taille) {
    float *p = ptr;
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {
            *p = *p * 3.0f;
        }
        p++;
    }
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    // Déclaration des tableaux
    int tableau_int[TAILLE];
    float tableau_float[TAILLE];
    
    // Pointeurs vers les tableaux
    int *ptr_int = tableau_int;
    float *ptr_float = tableau_float;
    
    // Remplissage des tableaux avec des valeurs aléatoires
    remplir_tableau_int(ptr_int, TAILLE);
    remplir_tableau_float(ptr_float, TAILLE);
    
    printf("========================================\n");
    printf("TABLEAUX AVANT LA MULTIPLICATION PAR 3\n");
    printf("========================================\n\n");
    
    printf("Tableau d'entiers (avant la multiplication par 3) :\n");
    afficher_tableau_int(ptr_int, TAILLE);
    printf("\n");
    
    printf("Tableau de nombres à virgule flottante (avant la multiplication par 3) :\n");
    afficher_tableau_float(ptr_float, TAILLE);
    printf("\n");
    
    // Multiplication par 3 des valeurs aux indices divisibles par 2
    multiplier_indices_pairs_int(ptr_int, TAILLE);
    multiplier_indices_pairs_float(ptr_float, TAILLE);
    
    printf("========================================\n");
    printf("TABLEAUX APRÈS LA MULTIPLICATION PAR 3\n");
    printf("========================================\n\n");
    
    printf("Tableau d'entiers (après la multiplication par 3) :\n");
    afficher_tableau_int(ptr_int, TAILLE);
    printf("\n");
    
    printf("Tableau de nombres à virgule flottante (après la multiplication par 3) :\n");
    afficher_tableau_float(ptr_float, TAILLE);
    printf("\n");
    
    printf("========================================\n");
    printf("INDICES MODIFIÉS : 0, 2, 4, 6, 8, 10\n");
    printf("========================================\n");
    
    return 0;
}
