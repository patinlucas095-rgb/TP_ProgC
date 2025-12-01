/* chercher2.c
   Comparaison caractère par caractère (sans strcmp) — 
   Assure-toi que ce fichier est enregistré en UTF-8 (sans BOM)
*/

#include <stdio.h>
#include <locale.h>

int comparerChaines(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0') ? 1 : 0;
}

int main(void) {
    /* Phrases EXACTES avec accents */
    const char *phrases[10] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    /* Permettre au système d'utiliser la locale (pour affichage/entrée UTF-8). */
    setlocale(LC_ALL, "");

    char recherche[512];
    int trouve = 0;

    printf("Entrez la phrase a rechercher :\n");
    if (fgets(recherche, sizeof(recherche), stdin) == NULL) {
        /* erreur ou EOF */
        return 1;
    }

    /* Supprimer '\n' et '\r' éventuels */
    int k = 0;
    while (recherche[k] != '\0') {
        if (recherche[k] == '\n' || recherche[k] == '\r') {
            recherche[k] = '\0';
            break;
        }
        k++;
    }

    for (int j = 0; j < 10; j++) {
        if (comparerChaines(recherche, phrases[j])) {
            trouve = 1;
            break;
        }
    }

    if (trouve)
        printf("Phrase trouvée\n");
    else
        printf("Phrase non trouvée\n");

    return 0;
}

