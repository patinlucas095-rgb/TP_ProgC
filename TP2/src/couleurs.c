#include <stdio.h>

// Définition de la structure Couleur au format RGBA
struct Couleur {
    unsigned char rouge;   // Composant rouge (0-255)
    unsigned char vert;    // Composant vert (0-255)
    unsigned char bleu;    // Composant bleu (0-255)
    unsigned char alpha;   // Composant alpha (0-255)
};

int main() {
    // Déclaration d'un tableau de 10 couleurs
    struct Couleur palette[10];
    int i;
    
    printf("========================================\n");
    printf("     PALETTE DE COULEURS RGBA\n");
    printf("========================================\n\n");
    
    // Initialisation des 10 couleurs en notation hexadécimale
    
    // Couleur 1 - Orange vif
    palette[0].rouge = 0xef;
    palette[0].vert = 0x78;
    palette[0].bleu = 0x12;
    palette[0].alpha = 0xff;
    
    // Couleur 2 - Vert émeraude
    palette[1].rouge = 0x2c;
    palette[1].vert = 0xc8;
    palette[1].bleu = 0x64;
    palette[1].alpha = 0xff;
    
    // Couleur 3 - Bleu azur
    palette[2].rouge = 0x1e;
    palette[2].vert = 0x90;
    palette[2].bleu = 0xff;
    palette[2].alpha = 0xff;
    
    // Couleur 4 - Rose fuchsia
    palette[3].rouge = 0xff;
    palette[3].vert = 0x00;
    palette[3].bleu = 0xff;
    palette[3].alpha = 0xff;
    
    // Couleur 5 - Jaune doré
    palette[4].rouge = 0xff;
    palette[4].vert = 0xd7;
    palette[4].bleu = 0x00;
    palette[4].alpha = 0xff;
    
    // Couleur 6 - Rouge pourpre (semi-transparent)
    palette[5].rouge = 0xdc;
    palette[5].vert = 0x14;
    palette[5].bleu = 0x3c;
    palette[5].alpha = 0x80;
    
    // Couleur 7 - Cyan
    palette[6].rouge = 0x00;
    palette[6].vert = 0xff;
    palette[6].bleu = 0xff;
    palette[6].alpha = 0xff;
    
    // Couleur 8 - Violet
    palette[7].rouge = 0x8a;
    palette[7].vert = 0x2b;
    palette[7].bleu = 0xe2;
    palette[7].alpha = 0xff;
    
    // Couleur 9 - Vert lime (transparent à 50%)
    palette[8].rouge = 0x32;
    palette[8].vert = 0xcd;
    palette[8].bleu = 0x32;
    palette[8].alpha = 0x7f;
    
    // Couleur 10 - Gris ardoise
    palette[9].rouge = 0x70;
    palette[9].vert = 0x80;
    palette[9].bleu = 0x90;
    palette[9].alpha = 0xff;
    
    
    // Affichage des couleurs (Format détaillé)
    printf("AFFICHAGE DÉTAILLÉ DES COULEURS\n");
    printf("================================\n\n");
    
    for (i = 0; i < 10; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %u\n", palette[i].rouge);
        printf("Vert : %u\n", palette[i].vert);
        printf("Bleu : %u\n", palette[i].bleu);
        printf("Alpha : %u\n", palette[i].alpha);
        printf("\n");
    }
    
    
    // Affichage en format hexadécimal
    printf("========================================\n");
    printf("   AFFICHAGE EN NOTATION HEXADÉCIMALE\n");
    printf("========================================\n\n");
    
    printf("Couleur     R     G     B     A      Code Hex\n");
    printf("--------------------------------------------------\n");
    
    for (i = 0; i < 10; i++) {
        printf("%-10d  0x%02x  0x%02x  0x%02x  0x%02x   #%02X%02X%02X%02X\n", 
               i + 1,
               palette[i].rouge,
               palette[i].vert,
               palette[i].bleu,
               palette[i].alpha,
               palette[i].rouge,
               palette[i].vert,
               palette[i].bleu,
               palette[i].alpha);
    }
    
    
    // Affichage en format RGB (sans alpha)
    printf("\n========================================\n");
    printf("     AFFICHAGE EN FORMAT RGB\n");
    printf("========================================\n\n");
    
    for (i = 0; i < 10; i++) {
        printf("Couleur %d : RGB(%u, %u, %u)\n", 
               i + 1,
               palette[i].rouge,
               palette[i].vert,
               palette[i].bleu);
        
        // Indication de transparence
        if (palette[i].alpha < 0xff) {
            float transparence = (palette[i].alpha / 255.0) * 100.0;
            printf("           Transparence : %.1f%%\n", transparence);
        }
    }
    
    
    // Statistiques sur la palette
    printf("\n========================================\n");
    printf("         STATISTIQUES\n");
    printf("========================================\n\n");
    
    int couleurs_opaques = 0;
    int couleurs_transparentes = 0;
    
    for (i = 0; i < 10; i++) {
        if (palette[i].alpha == 0xff) {
            couleurs_opaques++;
        } else {
            couleurs_transparentes++;
        }
    }
    
    printf("Nombre de couleurs opaques : %d\n", couleurs_opaques);
    printf("Nombre de couleurs transparentes : %d\n", couleurs_transparentes);
    
    // Trouver la couleur la plus claire (somme R+G+B la plus élevée)
    int max_luminosite = 0;
    int index_plus_claire = 0;
    
    for (i = 0; i < 10; i++) {
        int luminosite = palette[i].rouge + palette[i].vert + palette[i].bleu;
        if (luminosite > max_luminosite) {
            max_luminosite = luminosite;
            index_plus_claire = i;
        }
    }
    
    printf("\nCouleur la plus claire : Couleur %d\n", index_plus_claire + 1);
    printf("RGB(%u, %u, %u)\n", 
           palette[index_plus_claire].rouge,
           palette[index_plus_claire].vert,
           palette[index_plus_claire].bleu);
    
    
    printf("\n========================================\n");
    printf("  Informations sur le format RGBA :\n");
    printf("  - R (Rouge) : 0-255 (0x00-0xFF)\n");
    printf("  - G (Vert)  : 0-255 (0x00-0xFF)\n");
    printf("  - B (Bleu)  : 0-255 (0x00-0xFF)\n");
    printf("  - A (Alpha) : 0-255 (0x00-0xFF)\n");
    printf("    * 0xFF = Opaque (100%%)\n");
    printf("    * 0x80 = Semi-transparent (50%%)\n");
    printf("    * 0x00 = Transparent (0%%)\n");
    printf("========================================\n");
    
    return 0;
}
