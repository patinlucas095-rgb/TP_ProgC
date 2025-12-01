#include <stdio.h>
#include <string.h>

// Fonction pour afficher les octets d'une variable
void afficher_octets(void *ptr, size_t taille, const char *nom_type) {
    unsigned char *p = (unsigned char *)ptr;
    
    printf("Octets de %s :\n ", nom_type);
    
    for (size_t i = 0; i < taille; i++) {
        printf("%02x ", p[i]);
    }
    
    printf("\n");
}

// Fonction pour déterminer l'endianness (boutisme) du système
void detecter_endianness() {
    unsigned int test = 0x12345678;
    unsigned char *p = (unsigned char *)&test;
    
    printf("========================================\n");
    printf("DÉTECTION DE L'ARCHITECTURE\n");
    printf("========================================\n");
    
    if (p[0] == 0x78) {
        printf("Architecture : Little-endian (petit-boutiste)\n");
        printf("Les octets de poids faible sont stockés en premier\n");
    } else if (p[0] == 0x12) {
        printf("Architecture : Big-endian (gros-boutiste)\n");
        printf("Les octets de poids fort sont stockés en premier\n");
    } else {
        printf("Architecture : Mixte ou non standard\n");
    }
    
    printf("Valeur test : 0x12345678\n");
    printf("Octets en mémoire : ");
    for (size_t i = 0; i < sizeof(test); i++) {
        printf("%02x ", p[i]);
    }
    printf("\n\n");
}

// Fonction pour afficher les octets avec annotations
void afficher_octets_detailles(void *ptr, size_t taille, const char *nom_type, const char *valeur_str) {
    unsigned char *p = (unsigned char *)ptr;
    
    printf("%-20s : %s\n", nom_type, valeur_str);
    printf("  Adresse mémoire    : %p\n", ptr);
    printf("  Taille en octets   : %zu octet(s)\n", taille);
    printf("  Représentation hex : ");
    
    for (size_t i = 0; i < taille; i++) {
        printf("%02x ", p[i]);
    }
    
    printf("\n\n");
}

int main() {
    // Déclaration des variables de différents types
    short s = 0x0302;                    // 770 en décimal
    int i = 0x04030201;                  // 67305985 en décimal
    long int li = 0x0807060504030201L;   // Valeur longue
    float f = 2.5f;                      // Nombre flottant
    double d = 1.0;                      // Double précision
    long double ld = 1.0L;               // Long double
    
    // Variables supplémentaires pour démonstration
    char c = 'A';                        // 65 en ASCII
    unsigned int ui = 0xDEADBEEF;       // Valeur hexadécimale classique
    
    printf("========================================\n");
    printf("VISUALISATION DES OCTETS EN MÉMOIRE\n");
    printf("========================================\n\n");
    
    // Détection de l'endianness
    detecter_endianness();
    
    printf("========================================\n");
    printf("REPRÉSENTATION MÉMOIRE DES VARIABLES\n");
    printf("========================================\n\n");
    
    // Affichage simple (format de l'exemple)
    printf("--- FORMAT SIMPLE ---\n\n");
    
    afficher_octets(&s, sizeof(s), "short");
    printf("\n");
    
    afficher_octets(&i, sizeof(i), "int");
    printf("\n");
    
    afficher_octets(&li, sizeof(li), "long int");
    printf("\n");
    
    afficher_octets(&f, sizeof(f), "float");
    printf("\n");
    
    afficher_octets(&d, sizeof(d), "double");
    printf("\n");
    
    afficher_octets(&ld, sizeof(ld), "long double");
    printf("\n");
    
    // Affichage détaillé
    printf("========================================\n");
    printf("--- FORMAT DÉTAILLÉ ---\n");
    printf("========================================\n\n");
    
    char buffer[100];
    
    sprintf(buffer, "%d (0x%04x)", s, (unsigned short)s);
    afficher_octets_detailles(&s, sizeof(s), "short", buffer);
    
    sprintf(buffer, "%d (0x%08x)", i, (unsigned int)i);
    afficher_octets_detailles(&i, sizeof(i), "int", buffer);
    
    sprintf(buffer, "%ld (0x%016lx)", li, (unsigned long)li);
    afficher_octets_detailles(&li, sizeof(li), "long int", buffer);
    
    sprintf(buffer, "'%c' (ASCII: %d)", c, c);
    afficher_octets_detailles(&c, sizeof(c), "char", buffer);
    
    sprintf(buffer, "0x%08x", ui);
    afficher_octets_detailles(&ui, sizeof(ui), "unsigned int", buffer);
    
    sprintf(buffer, "%.6f", f);
    afficher_octets_detailles(&f, sizeof(f), "float", buffer);
    
    sprintf(buffer, "%.15lf", d);
    afficher_octets_detailles(&d, sizeof(d), "double", buffer);
    
    sprintf(buffer, "%.18Lf", ld);
    afficher_octets_detailles(&ld, sizeof(ld), "long double", buffer);
    
    printf("========================================\n");
    printf("ANALYSE DES POINTEURS\n");
    printf("========================================\n\n");
    
    // Démonstration de l'utilisation des pointeurs
    unsigned char *ptr_s = (unsigned char *)&s;
    unsigned char *ptr_i = (unsigned char *)&i;
    
    printf("Accès octet par octet avec pointeurs :\n\n");
    
    printf("short s (via pointeur) :\n");
    printf("  ptr_s[0] = 0x%02x\n", ptr_s[0]);
    printf("  ptr_s[1] = 0x%02x\n", ptr_s[1]);
    printf("\n");
    
    printf("int i (via pointeur) :\n");
    for (int j = 0; j < (int)sizeof(i); j++) {
        printf("  ptr_i[%d] = 0x%02x", j, ptr_i[j]);
        if (j == 0) printf(" (octet de poids faible - LSB)");
        if (j == (int)sizeof(i) - 1) printf(" (octet de poids fort - MSB)");
        printf("\n");
    }
    
    printf("\n========================================\n");
    printf("NOTES IMPORTANTES\n");
    printf("========================================\n");
    printf("1. L'ordre des octets dépend de l'architecture\n");
    printf("2. Little-endian : LSB en premier (x86, x86-64)\n");
    printf("3. Big-endian : MSB en premier (certains ARM, réseau)\n");
    printf("4. Les pointeurs permettent d'accéder aux octets\n");
    printf("5. Cast en (unsigned char *) pour voir chaque octet\n");
    printf("========================================\n");
    
    return 0;
}
