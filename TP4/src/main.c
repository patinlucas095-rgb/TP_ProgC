#include <stdio.h>
#include <string.h>
#include "fichier.h"

int main() {
    int choix;
    char nom_fichier[100];
    char message[500];

    while (1) {
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Lire un fichier\n");
        printf("2. Écrire dans un fichier\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // supprimer le \n restant

        if (choix == 3) {
            printf("Au revoir !\n");
            break;
        }

        printf("\nEntrez le nom du fichier : ");
        fgets(nom_fichier, sizeof(nom_fichier), stdin);

        // retirer le \n
        nom_fichier[strcspn(nom_fichier, "\n")] = '\0';

        if (choix == 1) {
            lire_fichier(nom_fichier);
        }
        else if (choix == 2) {
            printf("Entrez le message à écrire : ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            ecrire_dans_fichier(nom_fichier, message);
        }
        else {
            printf("Choix invalide.\n");
        }
    }

    return 0;
}

