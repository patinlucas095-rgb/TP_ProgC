#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_TABLEAU 100

// Structure pour représenter une couleur RGBA
typedef struct {
    unsigned char R;  // Rouge (0-255)
    unsigned char G;  // Vert (0-255)
    unsigned char B;  // Bleu (0-255)
    unsigned char A;  // Alpha/Transparence (0-255)
} Couleur;

// Structure pour stocker une couleur distincte et son nombre d'occurrences
typedef struct {
    Couleur couleur;
    int occurrences;
} CouleurCompteur;

// Fonction pour comparer deux couleurs
int couleurs_identiques(Couleur c1, Couleur c2) {
    return (c1.R == c2.R && c1.G == c2.G && c1.B == c2.B && c1.A == c2.A);
}

// Fonction pour afficher une couleur
void afficher_couleur(Couleur c) {
    printf("0x%02x 0x%02x 0x%02x 0x%02x", c.R, c.G, c.B, c.A);
}

// Fonction pour générer une couleur aléatoire
Couleur generer_couleur_aleatoire() {
    Couleur c;
    c.R = rand() % 256;
    c.G = rand() % 256;
    c.B = rand() % 256;
    c.A = rand() % 256;
    return c;
}

// Fonction pour générer des couleurs avec certaines répétitions
void remplir_tableau_couleurs(Couleur *tableau, int taille) {
    // Créer quelques couleurs de base qui se répéteront
    Couleur couleurs_base[10];
    
    for (int i = 0; i < 10; i++) {
        couleurs_base[i] = generer_couleur_aleatoire();
    }
    
    // Remplir le tableau avec un mélange de couleurs de base et aléatoires
    for (int i = 0; i < taille; i++) {
        if (rand() % 100 < 60) {  // 60% de chance d'utiliser une couleur de base
            tableau[i] = couleurs_base[rand() % 10];
        } else {  // 40% de chance d'utiliser une couleur aléatoire
            tableau[i] = generer_couleur_aleatoire();
        }
    }
}

// Fonction pour compter les couleurs distinctes et leurs occurrences
int compter_couleurs_distinctes(Couleur *tableau, int taille, CouleurCompteur *resultats) {
    int nb_distinctes = 0;
    
    for (int i = 0; i < taille; i++) {
        int trouve = 0;
        
        // Vérifier si la couleur existe déjà dans les résultats
        for (int j = 0; j < nb_distinctes; j++) {
            if (couleurs_identiques(tableau[i], resultats[j].couleur)) {
                resultats[j].occurrences++;
                trouve = 1;
                break;
            }
        }
        
        // Si la couleur n'existe pas encore, l'ajouter
        if (!trouve) {
            resultats[nb_distinctes].couleur = tableau[i];
            resultats[nb_distinctes].occurrences = 1;
            nb_distinctes++;
        }
    }
    
    return nb_distinctes;
}

// Fonction pour trier les couleurs par nombre d'occurrences (ordre décroissant)
void trier_par_occurrences(CouleurCompteur *resultats, int taille) {
    CouleurCompteur temp;
    
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (resultats[j].occurrences < resultats[j + 1].occurrences) {
                temp = resultats[j];
                resultats[j] = resultats[j + 1];
                resultats[j + 1] = temp;
            }
        }
    }
}

// Fonction pour afficher les statistiques
void afficher_statistiques(CouleurCompteur *resultats, int nb_distinctes, int total) {
    printf("\n========================================\n");
    printf("STATISTIQUES\n");
    printf("========================================\n");
    printf("Nombre total de couleurs : %d\n", total);
    printf("Nombre de couleurs distinctes : %d\n", nb_distinctes);
    printf("Taux de répétition : %.2f%%\n", 
           (1.0 - (double)nb_distinctes / total) * 100);
    printf("\n");
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    // Allocation des tableaux
    Couleur tableau_couleurs[TAILLE_TABLEAU];
    CouleurCompteur couleurs_distinctes[TAILLE_TABLEAU];
    
    printf("========================================\n");
    printf("COMPTEUR DE COULEURS RGBA\n");
    printf("========================================\n\n");
    
    // Remplir le tableau avec des couleurs
    printf("Génération de %d couleurs...\n", TAILLE_TABLEAU);
    remplir_tableau_couleurs(tableau_couleurs, TAILLE_TABLEAU);
    
    // Afficher un échantillon du tableau
    printf("\nÉchantillon des 10 premières couleurs :\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d. ", i + 1);
        afficher_couleur(tableau_couleurs[i]);
        printf("\n");
    }
    printf("...\n");
    
    // Compter les couleurs distinctes
    int nb_distinctes = compter_couleurs_distinctes(tableau_couleurs, 
                                                     TAILLE_TABLEAU, 
                                                     couleurs_distinctes);
    
    // Trier par nombre d'occurrences
    trier_par_occurrences(couleurs_distinctes, nb_distinctes);
    
    // Afficher les statistiques
    afficher_statistiques(couleurs_distinctes, nb_distinctes, TAILLE_TABLEAU);
    
    // Afficher les couleurs distinctes avec leurs occurrences
    printf("========================================\n");
    printf("COULEURS DISTINCTES ET OCCURRENCES\n");
    printf("========================================\n");
    printf("(Format : R G B A : nombre d'occurrences)\n\n");
    
    for (int i = 0; i < nb_distinctes; i++) {
        afficher_couleur(couleurs_distinctes[i].couleur);
        printf(" : %d", couleurs_distinctes[i].occurrences);
        
        // Afficher une barre visuelle pour les occurrences
        printf(" [");
        int barres = couleurs_distinctes[i].occurrences / 2;
        if (barres > 40) barres = 40;  // Limiter la longueur
        for (int j = 0; j < barres; j++) {
            printf("█");
        }
        printf("]\n");
    }
    
    printf("\n========================================\n");
    printf("ANALYSE DES OCCURRENCES\n");
    printf("========================================\n");
    
    // Trouver la couleur la plus fréquente
    if (nb_distinctes > 0) {
        printf("Couleur la plus fréquente : ");
        afficher_couleur(couleurs_distinctes[0].couleur);
        printf(" (%d occurrences)\n", couleurs_distinctes[0].occurrences);
        
        // Trouver la couleur la moins fréquente
        printf("Couleur la moins fréquente : ");
        afficher_couleur(couleurs_distinctes[nb_distinctes - 1].couleur);
        printf(" (%d occurrence(s))\n", couleurs_distinctes[nb_distinctes - 1].occurrences);
        
        // Compter les couleurs uniques
        int uniques = 0;
        for (int i = 0; i < nb_distinctes; i++) {
            if (couleurs_distinctes[i].occurrences == 1) {
                uniques++;
            }
        }
        printf("Couleurs uniques (1 occurrence) : %d\n", uniques);
    }
    
    printf("========================================\n");
    
    return 0;
}
