#include <stdio.h>

int main() {
    // Déclaration des tableaux pour stocker les informations des 5 étudiants
    char noms[5][50] = {
        "Dupont",
        "Martin",
        "Bernard",
        "Thomas",
        "Robert"
    };
    
    char prenoms[5][50] = {
        "Marie",
        "Pierre",
        "Sophie",
        "Lucas",
        "Emma"
    };
    
    char adresses[5][100] = {
        "12 Rue de la Paix, 75002 Paris",
        "25 Avenue des Champs, 69001 Lyon",
        "8 Boulevard Victor Hugo, 31000 Toulouse",
        "33 Rue de la République, 13001 Marseille",
        "17 Place de la Mairie, 59000 Lille"
    };
    
    // Tableaux pour les notes dans les deux modules
    float notes_programmation[5] = {15.5, 14.0, 16.5, 12.0, 17.5};
    float notes_systeme[5] = {13.0, 15.5, 14.5, 11.0, 16.0};
    
    // Variable pour la boucle
    int i;
    
    // Affichage de l'en-tête
    printf("========================================\n");
    printf("   GESTION DES INFORMATIONS ÉTUDIANTES\n");
    printf("========================================\n\n");
    
    // Parcourir les tableaux et afficher les détails de chaque étudiant
    for (i = 0; i < 5; i++) {
        printf("ÉTUDIANT.E N°%d\n", i + 1);
        printf("---------------\n");
        printf("Nom : %s\n", noms[i]);
        printf("Prénom : %s\n", prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note en Programmation en C : %.2f/20\n", notes_programmation[i]);
        printf("Note en Système d'exploitation : %.2f/20\n", notes_systeme[i]);
        
        // Calcul de la moyenne
        float moyenne = (notes_programmation[i] + notes_systeme[i]) / 2.0;
        printf("Moyenne générale : %.2f/20\n", moyenne);
        
        // Appréciation
        printf("Appréciation : ");
        if (moyenne >= 16.0) {
            printf("Très bien\n");
        } else if (moyenne >= 14.0) {
            printf("Bien\n");
        } else if (moyenne >= 12.0) {
            printf("Assez bien\n");
        } else if (moyenne >= 10.0) {
            printf("Passable\n");
        } else {
            printf("Insuffisant\n");
        }
        
        printf("\n");
    }
    
    // Statistiques globales
    printf("========================================\n");
    printf("         STATISTIQUES GLOBALES\n");
    printf("========================================\n\n");
    
    // Calcul des moyennes de classe pour chaque module
    float somme_prog = 0.0;
    float somme_sys = 0.0;
    float moyenne_generale_classe = 0.0;
    
    for (i = 0; i < 5; i++) {
        somme_prog += notes_programmation[i];
        somme_sys += notes_systeme[i];
    }
    
    float moyenne_classe_prog = somme_prog / 5.0;
    float moyenne_classe_sys = somme_sys / 5.0;
    moyenne_generale_classe = (somme_prog + somme_sys) / 10.0;
    
    printf("Moyenne de classe en Programmation en C : %.2f/20\n", moyenne_classe_prog);
    printf("Moyenne de classe en Système d'exploitation : %.2f/20\n", moyenne_classe_sys);
    printf("Moyenne générale de la classe : %.2f/20\n\n", moyenne_generale_classe);
    
    // Trouver le/la meilleur.e étudiant.e
    float meilleure_moyenne = 0.0;
    int index_meilleur = 0;
    
    for (i = 0; i < 5; i++) {
        float moy = (notes_programmation[i] + notes_systeme[i]) / 2.0;
        if (moy > meilleure_moyenne) {
            meilleure_moyenne = moy;
            index_meilleur = i;
        }
    }
    
    printf("Meilleur.e étudiant.e : %s %s\n", prenoms[index_meilleur], noms[index_meilleur]);
    printf("Avec une moyenne de : %.2f/20\n\n", meilleure_moyenne);
    
    // Affichage en format tableau
    printf("========================================\n");
    printf("      TABLEAU RÉCAPITULATIF\n");
    printf("========================================\n\n");
    
    printf("%-15s %-15s %-8s %-8s %-8s\n", "Nom", "Prénom", "Prog C", "Sys Exp", "Moyenne");
    printf("------------------------------------------------------------\n");
    
    for (i = 0; i < 5; i++) {
        float moy = (notes_programmation[i] + notes_systeme[i]) / 2.0;
        printf("%-15s %-15s %6.2f   %6.2f   %6.2f\n", 
               noms[i], prenoms[i], notes_programmation[i], 
               notes_systeme[i], moy);
    }
    
    printf("\n========================================\n");
    printf("         FIN DU PROGRAMME\n");
    printf("========================================\n");
    
    return 0;
}
