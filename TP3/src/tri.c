#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100
#define VALEUR_MIN -100
#define VALEUR_MAX 100

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

// Fonction de tri à bulles (Bubble Sort)
void tri_bulles(int *tableau, int taille) {
    int temp;
    int echange;
    
    for (int i = 0; i < taille - 1; i++) {
        echange = 0;
        for (int j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // Échange des éléments
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                echange = 1;
            }
        }
        // Si aucun échange n'a été effectué, le tableau est déjà trié
        if (echange == 0) {
            break;
        }
    }
}

// Fonction de tri par insertion (Insertion Sort)
void tri_insertion(int *tableau, int taille) {
    int i, j, cle;
    
    for (i = 1; i < taille; i++) {
        cle = tableau[i];
        j = i - 1;
        
        // Déplacer les éléments plus grands que la clé
        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }
        tableau[j + 1] = cle;
    }
}

// Fonction auxiliaire pour le tri rapide (partition)
int partition(int *tableau, int bas, int haut) {
    int pivot = tableau[haut];
    int i = bas - 1;
    int temp;
    
    for (int j = bas; j < haut; j++) {
        if (tableau[j] < pivot) {
            i++;
            // Échange
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
    }
    
    // Placer le pivot à sa position finale
    temp = tableau[i + 1];
    tableau[i + 1] = tableau[haut];
    tableau[haut] = temp;
    
    return i + 1;
}

// Fonction de tri rapide (Quick Sort)
void tri_rapide(int *tableau, int bas, int haut) {
    if (bas < haut) {
        int pi = partition(tableau, bas, haut);
        
        // Trier récursivement les sous-tableaux
        tri_rapide(tableau, bas, pi - 1);
        tri_rapide(tableau, pi + 1, haut);
    }
}

int main() {
    int tableau[TAILLE];
    int choix_tri;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("========================================\n");
    printf("PROGRAMME DE TRI DE TABLEAU\n");
    printf("========================================\n\n");
    
    // Remplissage du tableau avec des valeurs aléatoires
    printf("Génération de %d valeurs aléatoires entre %d et %d...\n\n", 
           TAILLE, VALEUR_MIN, VALEUR_MAX);
    
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % (VALEUR_MAX - VALEUR_MIN + 1) + VALEUR_MIN;
    }
    
    // Affichage du tableau non trié
    printf("========================================\n");
    printf("TABLEAU NON TRIÉ :\n");
    printf("========================================\n");
    afficher_tableau(tableau, TAILLE, 10);
    printf("\n");
    
    // Menu de choix de l'algorithme de tri
    printf("Choisissez l'algorithme de tri :\n");
    printf("1. Tri à bulles (Bubble Sort)\n");
    printf("2. Tri par insertion (Insertion Sort)\n");
    printf("3. Tri rapide (Quick Sort)\n");
    printf("Choix (1-3, par défaut 3) : ");
    
    if (scanf("%d", &choix_tri) != 1) {
        choix_tri = 3;  // Par défaut : tri rapide
    }
    printf("\n");
    
    // Application de l'algorithme de tri choisi
    switch (choix_tri) {
        case 1:
            printf("Tri en cours avec l'algorithme à bulles...\n\n");
            tri_bulles(tableau, TAILLE);
            break;
        case 2:
            printf("Tri en cours avec l'algorithme par insertion...\n\n");
            tri_insertion(tableau, TAILLE);
            break;
        case 3:
        default:
            printf("Tri en cours avec l'algorithme rapide (Quick Sort)...\n\n");
            tri_rapide(tableau, 0, TAILLE - 1);
            break;
    }
    
    // Affichage du tableau trié
    printf("========================================\n");
    printf("TABLEAU TRIÉ PAR ORDRE CROISSANT :\n");
    printf("========================================\n");
    afficher_tableau(tableau, TAILLE, 10);
    printf("\n");
    
    // Vérification que le tableau est bien trié
    int est_trie = 1;
    for (int i = 0; i < TAILLE - 1; i++) {
        if (tableau[i] > tableau[i + 1]) {
            est_trie = 0;
            break;
        }
    }
    
    if (est_trie) {
        printf("✓ Vérification : Le tableau est correctement trié !\n");
    } else {
        printf("✗ Erreur : Le tableau n'est pas correctement trié.\n");
    }
    
    printf("========================================\n");
    
    return 0;
}
