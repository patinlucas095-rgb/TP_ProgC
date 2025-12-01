#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

int main() {
    int choix;
    char nom_de_fichier[100];
    char message[256];

    while (1) {
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Lire un fichier\n");
        printf("2. Écrire dans un fichier\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // consommer le retour chariot

        if (choix == 1) {
            printf("Entrez le nom du fichier à lire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0'; // enlever le \n
            lire_fichier(nom_de_fichier);

        } else if (choix == 2) {
            printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';

            printf("Entrez le message à écrire : ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            ecrire_dans_fichier(nom_de_fichier, message);

        } else if (choix == 3) {
            printf("Au revoir !\n");
            break;

        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    }

    return 0;
}
