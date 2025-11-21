#include <stdio.h>

int main() {
    int somme = 0;

    // Boucle for de 1 à 1000
    for (int i = 1; i <= 1000; i++) {
        
        // Si divisible par 11 → on saute ce nombre
        if (i % 11 == 0) {
            continue;
        }

        // Si divisible par 5 ou par 7 → on ajoute à somme
        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
        }

        // Si la somme dépasse 5000 → on arrête immédiatement
        if (somme > 5000) {
            printf("Somme depassee (>%d) a i = %d\n", 5000, i);
            break;
        }
    }

    // Affichage de la somme finale
    printf("Somme finale = %d\n", somme);

    return 0;
}
