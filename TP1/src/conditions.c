#include <stdio.h>

int main() {
    int somme = 0;
    
    // Parcourir les nombres de 1 à 1000
    for (int i = 1; i <= 1000; i++) {
        // Si divisible par 11, passer au nombre suivant
        if (i % 11 == 0) {
            continue;
        }
        
        // Si divisible par 5 ou par 7, ajouter à la somme
        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
            
            // Si la somme dépasse 5000, arrêter la boucle
            if (somme > 5000) {
                printf("La somme a dépassé 5000 au nombre %d\n", i);
                break;
            }
        }
    }
    
    // Afficher la somme finale
    printf("Somme finale : %d\n", somme);
    
    return 0;
}
