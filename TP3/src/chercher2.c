#include <stdio.h>

/* Fonction de comparaison de deux chaînes sans utiliser strcmp */
int comparerChaines(const char *a, const char *b) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0; // les chaînes sont différentes
        }
        i++;
    }

    // Si les deux chaînes se terminent en même temps -> identiques
    if (a[i] == '\0' && b[i] == '\0')
        return 1;

    return 0; // longueurs différentes
}

int main() {
    // Tableau de 10 phrases
    const char *phrases[10] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[200];
    int trouve = 0;

    printf("Entrez la phrase a rechercher :\n");
    fgets(recherche, 200, stdin);

    // Enlever le \n éventuel de fgets
    int i = 0;
    while (recherche[i] != '\0') {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
        i++;
    }

    // Recherche dans le tableau
    for (int j = 0; j < 10; j++) {
        if (comparerChaines(recherche, phrases[j])) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Phrase trouvee\n");
    else
        printf("Phrase non trouvee\n");

    return 0;
}
