#include <stdio.h>

int main() {
    // Déclaration des chaînes de caractères
    char chaine1[100] = "Hello";
    char chaine2[100] = " World!";
    char copie[100];
    char concatenation[200];
    
    int longueur1, longueur2, longueur_totale;
    int i, j;
    
    printf("=== OPÉRATIONS SUR LES CHAÎNES DE CARACTÈRES ===\n\n");
    
    // ===== 1. CALCUL DE LA LONGUEUR D'UNE CHAÎNE =====
    printf("1. CALCUL DE LA LONGUEUR\n");
    printf("-------------------------\n");
    
    // Calculer la longueur de chaine1
    longueur1 = 0;
    while (chaine1[longueur1] != '\0') {
        longueur1++;
    }
    
    // Calculer la longueur de chaine2
    longueur2 = 0;
    while (chaine2[longueur2] != '\0') {
        longueur2++;
    }
    
    printf("Chaîne 1 : \"%s\"\n", chaine1);
    printf("Longueur de la chaîne 1 : %d caractères\n\n", longueur1);
    
    printf("Chaîne 2 : \"%s\"\n", chaine2);
    printf("Longueur de la chaîne 2 : %d caractères\n\n", longueur2);
    
    
    // ===== 2. COPIE D'UNE CHAÎNE =====
    printf("2. COPIE D'UNE CHAÎNE\n");
    printf("---------------------\n");
    
    // Copier chaine1 dans copie
    i = 0;
    while (chaine1[i] != '\0') {
        copie[i] = chaine1[i];
        i++;
    }
    copie[i] = '\0';  // Ajouter le caractère de fin de chaîne
    
    printf("Chaîne originale : \"%s\"\n", chaine1);
    printf("Chaîne copiée : \"%s\"\n\n", copie);
    
    
    // ===== 3. CONCATÉNATION DE DEUX CHAÎNES =====
    printf("3. CONCATÉNATION DE DEUX CHAÎNES\n");
    printf("--------------------------------\n");
    
    // Copier d'abord chaine1 dans concatenation
    i = 0;
    while (chaine1[i] != '\0') {
        concatenation[i] = chaine1[i];
        i++;
    }
    
    // Ensuite, ajouter chaine2 à la suite
    j = 0;
    while (chaine2[j] != '\0') {
        concatenation[i] = chaine2[j];
        i++;
        j++;
    }
    concatenation[i] = '\0';  // Ajouter le caractère de fin de chaîne
    
    printf("Chaîne 1 : \"%s\"\n", chaine1);
    printf("Chaîne 2 : \"%s\"\n", chaine2);
    printf("Résultat de la concaténation : \"%s\"\n\n", concatenation);
    
    // Calculer la longueur de la chaîne concaténée
    longueur_totale = 0;
    while (concatenation[longueur_totale] != '\0') {
        longueur_totale++;
    }
    
    printf("Longueur de la chaîne concaténée : %d caractères\n", longueur_totale);
    printf("Vérification : %d + %d = %d ✓\n\n", longueur1, longueur2, longueur_totale);
    
    
    // ===== TESTS SUPPLÉMENTAIRES =====
    printf("=== TESTS SUPPLÉMENTAIRES ===\n\n");
    
    // Test avec d'autres chaînes
    char test1[50] = "Bonjour";
    char test2[50] = " tout le monde";
    char resultat[100];
    int len;
    
    // Concaténation
    i = 0;
    while (test1[i] != '\0') {
        resultat[i] = test1[i];
        i++;
    }
    j = 0;
    while (test2[j] != '\0') {
        resultat[i] = test2[j];
        i++;
        j++;
    }
    resultat[i] = '\0';
    
    // Calcul de longueur
    len = 0;
    while (resultat[len] != '\0') {
        len++;
    }
    
    printf("Test : \"%s\" + \"%s\" = \"%s\"\n", test1, test2, resultat);
    printf("Longueur : %d caractères\n\n", len);
    
    
    // ===== EXPLICATION DES ALGORITHMES =====
    printf("=== EXPLICATION DES ALGORITHMES ===\n\n");
    
    printf("1. Calcul de longueur :\n");
    printf("   - Parcourir la chaîne jusqu'au caractère '\\0'\n");
    printf("   - Incrémenter un compteur à chaque caractère\n\n");
    
    printf("2. Copie de chaîne :\n");
    printf("   - Parcourir la chaîne source caractère par caractère\n");
    printf("   - Copier chaque caractère dans la destination\n");
    printf("   - Ajouter '\\0' à la fin de la destination\n\n");
    
    printf("3. Concaténation :\n");
    printf("   - Copier la première chaîne dans le résultat\n");
    printf("   - Trouver la fin de la première chaîne\n");
    printf("   - Ajouter la deuxième chaîne à partir de cet emplacement\n");
    printf("   - Ajouter '\\0' à la fin\n\n");
    
    printf("=== PROGRAMME TERMINÉ ===\n");
    
    return 0;
}
