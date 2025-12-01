#include <stdio.h>
#include <string.h>

// Définition de la structure Etudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note_programmation;
    float note_systeme;
};

int main() {
    // Déclaration d'un tableau de 5 étudiants
    struct Etudiant etudiants[5];
    int i;
    
    printf("========================================\n");
    printf("   GESTION DES ÉTUDIANTS (STRUCTURES)\n");
    printf("========================================\n\n");
    
    // Initialisation des données des 5 étudiants avec strcpy
    
    // Étudiant 1
    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20, Boulevard Niels Bohr, Lyon");
    etudiants[0].note_programmation = 16.5;
    etudiants[0].note_systeme = 12.1;
    
    // Étudiant 2
    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "22, Boulevard Niels Bohr, Lyon");
    etudiants[1].note_programmation = 14.0;
    etudiants[1].note_systeme = 14.1;
    
    // Étudiant 3
    strcpy(etudiants[2].nom, "Bernard");
    strcpy(etudiants[2].prenom, "Sophie");
    strcpy(etudiants[2].adresse, "15, Rue Albert Einstein, Paris");
    etudiants[2].note_programmation = 17.5;
    etudiants[2].note_systeme = 15.0;
    
    // Étudiant 4
    strcpy(etudiants[3].nom, "Thomas");
    strcpy(etudiants[3].prenom, "Lucas");
    strcpy(etudiants[3].adresse, "8, Avenue Marie Curie, Marseille");
    etudiants[3].note_programmation = 11.5;
    etudiants[3].note_systeme = 13.0;
    
    // Étudiant 5
    strcpy(etudiants[4].nom, "Robert");
    strcpy(etudiants[4].prenom, "Emma");
    strcpy(etudiants[4].adresse, "30, Place Isaac Newton, Toulouse");
    etudiants[4].note_programmation = 18.0;
    etudiants[4].note_systeme = 16.5;
    
    
    // Affichage des informations de tous les étudiants
    printf("LISTE DES ÉTUDIANT.E.S\n");
    printf("======================\n\n");
    
    for (i = 0; i < 5; i++) {
        printf("Étudiant.e %d :\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note 1 (Programmation en C) : %.1f\n", etudiants[i].note_programmation);
        printf("Note 2 (Système d'exploitation) : %.1f\n", etudiants[i].note_systeme);
        
        // Calcul de la moyenne
        float moyenne = (etudiants[i].note_programmation + etudiants[i].note_systeme) / 2.0;
        printf("Moyenne : %.2f/20\n", moyenne);
        
        printf("\n");
    }
    
    
    // Statistiques supplémentaires
    printf("========================================\n");
    printf("         STATISTIQUES GLOBALES\n");
    printf("========================================\n\n");
    
    // Calcul des moyennes de classe
    float somme_prog = 0.0;
    float somme_sys = 0.0;
    
    for (i = 0; i < 5; i++) {
        somme_prog += etudiants[i].note_programmation;
        somme_sys += etudiants[i].note_systeme;
    }
    
    float moyenne_classe_prog = somme_prog / 5.0;
    float moyenne_classe_sys = somme_sys / 5.0;
    float moyenne_generale_classe = (somme_prog + somme_sys) / 10.0;
    
    printf("Moyenne de classe en Programmation : %.2f/20\n", moyenne_classe_prog);
    printf("Moyenne de classe en Système : %.2f/20\n", moyenne_classe_sys);
    printf("Moyenne générale de la classe : %.2f/20\n\n", moyenne_generale_classe);
    
    
    // Trouver le/la meilleur.e étudiant.e
    float meilleure_moyenne = 0.0;
    int index_meilleur = 0;
    
    for (i = 0; i < 5; i++) {
        float moy = (etudiants[i].note_programmation + etudiants[i].note_systeme) / 2.0;
        if (moy > meilleure_moyenne) {
            meilleure_moyenne = moy;
            index_meilleur = i;
        }
    }
    
    printf("Meilleur.e étudiant.e : %s %s\n", 
           etudiants[index_meilleur].prenom, 
           etudiants[index_meilleur].nom);
    printf("Avec une moyenne de : %.2f/20\n\n", meilleure_moyenne);
    
    
    // Tableau récapitulatif
    printf("========================================\n");
    printf("      TABLEAU RÉCAPITULATIF\n");
    printf("========================================\n\n");
    
    printf("%-15s %-15s %-8s %-8s %-8s\n", 
           "Nom", "Prénom", "Note 1", "Note 2", "Moyenne");
    printf("------------------------------------------------------------\n");
    
    for (i = 0; i < 5; i++) {
        float moy = (etudiants[i].note_programmation + etudiants[i].note_systeme) / 2.0;
        printf("%-15s %-15s %6.1f   %6.1f   %6.2f\n", 
               etudiants[i].nom, 
               etudiants[i].prenom, 
               etudiants[i].note_programmation, 
               etudiants[i].note_systeme, 
               moy);
    }
    
    printf("\n========================================\n");
    printf("  Avantages de l'utilisation de struct :\n");
    printf("  - Regroupement logique des données\n");
    printf("  - Code plus lisible et maintenable\n");
    printf("  - Facilite la manipulation des données\n");
    printf("  - Meilleure organisation du code\n");
    printf("========================================\n");
    
    return 0;
}
