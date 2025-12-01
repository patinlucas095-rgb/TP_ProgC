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

// Fonction de tri rapide (partition)
int partition(int *tableau, int bas, int haut) {
    int pivot = tableau[haut];
    int i = bas - 1;
    int temp;
    
    for (int j = bas; j < haut; j++) {
        if (tableau[j] < pivot) {
            i++;
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
    }
    
    temp = tableau[i + 1];
    tableau[i + 1] = tableau[haut];
    tableau[haut] = temp;
    
    return i + 1;
}

// Fonction de tri rapide
void tri_rapide(int *tableau, int bas, int haut) {
    if (bas < haut) {
        int pi = partition(tableau, bas, haut);
        tri_rapide(tableau, bas, pi - 1);
        tri_rapide(tableau, pi + 1, haut);
    }
}

// Fonction de recherche dichotomique (itérative)
int recherche_dichotomique(int *tableau, int taille, int valeur, int *iterations) {
    int gauche = 0;
    int droite = taille - 1;
    int milieu;
    *iterations = 0;
    
    while (gauche <= droite) {
        (*iterations)++;
        milieu = gauche + (droite - gauche) / 2;
        
        // Affichage du processus de recherche
        printf("  Itération %d : gauche=%d, droite=%d, milieu=%d, valeur=%d\n", 
               *iterations, gauche, droite, milieu, tableau[milieu]);
        
        // Vérifier si la valeur est au milieu
        if (tableau[milieu] == valeur) {
            return milieu;
        }
        
        // Si la valeur est plus grande, ignorer la moitié gauche
        if (tableau[milieu] < valeur) {
            gauche = milieu + 1;
        }
        // Si la valeur est plus petite, ignorer la moitié droite
        else {
            droite = milieu - 1;
        }
    }
    
    // L'élément n'est pas présent dans le tableau
    return -1;
}

// Fonction de recherche dichotomique récursive (alternative)
int recherche_dichotomique_recursive(int *tableau, int gauche, int droite, int valeur) {
    if (droite >= gauche) {
        int milieu = gauche + (droite - gauche) / 2;
        
        // Si l'élément est présent au milieu
        if (tableau[milieu] == valeur) {
            return milieu;
        }
        
        // Si l'élément est plus petit que le milieu, chercher dans la partie gauche
        if (tableau[milieu] > valeur) {
            return recherche_dichotomique_recursive(tableau, gauche, milieu - 1, valeur);
        }
        
        // Sinon, chercher dans la partie droite
        return recherche_dichotomique_recursive(tableau, milieu + 1, droite, valeur);
    }
    
    // L'élément n'est pas présent
    return -1;
}

int main() {
    int tableau[TAILLE];
    int valeur_recherchee;
    int resultat;
    int iterations;
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    printf("========================================\n");
    printf("RECHERCHE DICHOTOMIQUE\n");
    printf("========================================\n\n");
    
    // Remplissage du tableau avec des valeurs aléatoires
    printf("Génération de %d valeurs aléatoires entre %d et %d...\n", 
           TAILLE, VALEUR_MIN, VALEUR_MAX);
    
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = rand() % (VALEUR_MAX - VALEUR_MIN + 1) + VALEUR_MIN;
    }
    
    // Tri du tableau
    printf("Tri du tableau en ordre croissant...\n\n");
    tri_rapide(tableau, 0, TAILLE - 1);
    
    // Affichage du tableau trié
    printf("========================================\n");
    printf("TABLEAU TRIÉ :\n");
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
    
    // Recherche dichotomique avec affichage du processus
    printf("========================================\n");
    printf("PROCESSUS DE RECHERCHE DICHOTOMIQUE :\n");
    printf("========================================\n");
    resultat = recherche_dichotomique(tableau, TAILLE, valeur_recherchee, &iterations);
    printf("\n");
    
    // Affichage du résultat
    printf("========================================\n");
    printf("RÉSULTAT :\n");
    printf("========================================\n");
    
    if (resultat != -1) {
        printf("Résultat : entier présent\n\n");
        printf("Informations détaillées :\n");
        printf("- Position dans le tableau : %d\n", resultat);
        printf("- Valeur trouvée : %d\n", tableau[resultat]);
        printf("- Nombre d'itérations : %d\n", iterations);
        printf("- Complexité : O(log n) = O(log %d) ≈ %.2f itérations max\n", 
               TAILLE, log2(TAILLE));
    } else {
        printf("Résultat : entier absent\n\n");
        printf("Informations détaillées :\n");
        printf("- Nombre d'itérations : %d\n", iterations);
        printf("- L'entier %d n'existe pas dans le tableau\n", valeur_recherchee);
    }
    
    printf("\n========================================\n");
    printf("AVANTAGES DE LA RECHERCHE DICHOTOMIQUE :\n");
    printf("========================================\n");
    printf("- Recherche linéaire : O(n) = %d itérations max\n", TAILLE);
    printf("- Recherche dichotomique : O(log n) ≈ %.0f itérations max\n", log2(TAILLE));
    printf("- Gain d'efficacité : %.1fx plus rapide !\n", (double)TAILLE / log2(TAILLE));
    printf("- Condition : le tableau DOIT être trié\n");
    printf("========================================\n");
    
    return 0;
}
