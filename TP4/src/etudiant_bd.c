#include <stdio.h>
#include <string.h>
#include "etudiant.h"
#include "fichier.h"

int main() {
    Etudiant etudiants[5];
    char buffer[300]; // pour formater la ligne avant écriture

    for (int i = 0; i < 5; i++) {
        printf("\nEntrez les détails de l'étudiant.e %d :\n", i + 1);

        printf("Nom : ");
        scanf("%49s", etudiants[i].nom);

        printf("Prénom : ");
        scanf("%49s", etudiants[i].prenom);

        getchar(); // consommer le retour chariot

        printf("Adresse : ");
        fgets(etudiants[i].adresse, sizeof(etudiants[i].adresse), stdin);
        etudiants[i].adresse[strcspn(etudiants[i].adresse, "\n")] = '\0';

        printf("Note 1 : ");
        scanf("%d", &etudiants[i].note1);

        printf("Note 2 : ");
        scanf("%d", &etudiants[i].note2);

        // Formatage des données pour une ligne du fichier
        snprintf(buffer, sizeof(buffer), "%s %s | %s | %d %d",
                 etudiants[i].nom,
                 etudiants[i].prenom,
                 etudiants[i].adresse,
                 etudiants[i].note1,
                 etudiants[i].note2);

        // Écriture dans le fichier
        ecrire_dans_fichier("etudiant.txt", buffer);
    }

    printf("\nLes détails des étudiants ont été enregistrés dans le fichier etudiant.txt.\n");

    // Lecture finale pour vérifier
    lire_fichier("etudiant.txt");

    return 0;
}
