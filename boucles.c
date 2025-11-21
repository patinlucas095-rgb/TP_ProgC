#include <stdio.h>

int main() {
    int compteur;

    printf("Entrez une valeur pour compteur (< 10) : ");
    scanf("%d", &compteur);

    if (compteur >= 10) {
        printf("Erreur : compteur doit etre strictement inferieur a 10.\n");
        return 0;
    }

    printf("\n--- Version avec FOR ---\n");
    for (int i = 1; i <= compteur; i++) {       // lignes
        for (int j = 1; j <= i; j++) {          // colonnes
            if (i == compteur) {
                printf("* ");
            } else if (j == 1 || j == i) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    printf("\n--- Version avec WHILE ---\n");
    int i = 1;
    while (i <= compteur) {                     // lignes
        int j = 1;
        while (j <= i) {                        // colonnes
            if (i == compteur) {
                printf("* ");
            } else if (j == 1 || j == i) {
                printf("* ");
            } else {
                printf("# ");
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
