#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "operator.h"

int main() {
    int choix;

    while (1) {
        printf("\nMenu principal :\n");
        printf("1. Lire un fichier\n");
        printf("2. Écrire dans un fichier\n");
        printf("3. Calculer avec un opérateur\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // consommer le retour chariot

        if (choix == 1) {
            char nom_de_fichier[100];
            printf("Entrez le nom du fichier à lire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';
            lire_fichier(nom_de_fichier);

        } else if (choix == 2) {
            char nom_de_fichier[100];
            char message[256];
            printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
            fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);
            nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';

            printf("Entrez le message à écrire : ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            ecrire_dans_fichier(nom_de_fichier, message);

        } else if (choix == 3) {
            int num1, num2;
            char op;

            printf("Entrez num1 : ");
            scanf("%d", &num1);

            printf("Entrez num2 : ");
            scanf("%d", &num2);

            printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
            scanf(" %c", &op); // espace avant %c pour ignorer les retours à la ligne

            int resultat = 0;

            switch (op) {
                case '+':
                    resultat = somme(num1, num2);
                    break;
                case '-':
                    resultat = difference(num1, num2);
                    break;
                case '*':
                    resultat = produit(num1, num2);
                    break;
                case '/':
                    resultat = quotient(num1, num2);
                    break;
                case '%':
                    resultat = modulo(num1, num2);
                    break;
                case '&':
                    resultat = et(num1, num2);
                    break;
                case '|':
                    resultat = ou(num1, num2);
                    break;
                case '~':
                    resultat = negation(num1, num2);
                    break;
                default:
                    printf("Operateur invalide.\n");
                    continue;
            }

            printf("Résultat : %d\n", resultat);

        } else if (choix == 4) {
            printf("Au revoir !\n");
            break;

        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    }

    return 0;
}
