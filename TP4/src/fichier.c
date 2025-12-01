#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

// Fonction pour lire le contenu d'un fichier
void lire_fichier(const char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nom_de_fichier);
        return;
    }

    char c;
    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    printf("\n");

    fclose(f);
}

// Fonction pour écrire un message dans un fichier
void ecrire_dans_fichier(const char *nom_de_fichier, const char *message) {
    FILE *f = fopen(nom_de_fichier, "w");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nom_de_fichier);
        return;
    }

    fprintf(f, "%s", message);
    fclose(f);

    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
}

