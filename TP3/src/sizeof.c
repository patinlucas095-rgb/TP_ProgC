#include <stdio.h>

int main() {
    printf("========================================\n");
    printf("TAILLES DES TYPES DE DONNÉES EN C\n");
    printf("(Système 64 bits)\n");
    printf("========================================\n\n");
    
    // Types de base
    printf("--- TYPES DE BASE ---\n");
    printf("La taille de char est : %zu octet(s)\n", sizeof(char));
    printf("La taille de short est : %zu octet(s)\n", sizeof(short));
    printf("La taille de int est : %zu octet(s)\n", sizeof(int));
    printf("La taille de long est : %zu octet(s)\n", sizeof(long));
    printf("La taille de long long est : %zu octet(s)\n", sizeof(long long));
    printf("La taille de float est : %zu octet(s)\n", sizeof(float));
    printf("La taille de double est : %zu octet(s)\n", sizeof(double));
    printf("La taille de long double est : %zu octet(s)\n\n", sizeof(long double));
    
    // Pointeurs simples
    printf("--- POINTEURS SIMPLES ---\n");
    printf("La taille de int* est : %zu octet(s)\n", sizeof(int*));
    printf("La taille de char* est : %zu octet(s)\n", sizeof(char*));
    printf("La taille de short* est : %zu octet(s)\n", sizeof(short*));
    printf("La taille de long* est : %zu octet(s)\n", sizeof(long*));
    printf("La taille de float* est : %zu octet(s)\n", sizeof(float*));
    printf("La taille de double* est : %zu octet(s)\n\n", sizeof(double*));
    
    // Pointeurs de pointeurs (double pointeurs)
    printf("--- POINTEURS DE POINTEURS ---\n");
    printf("La taille de int** est : %zu octet(s)\n", sizeof(int**));
    printf("La taille de char** est : %zu octet(s)\n", sizeof(char**));
    printf("La taille de float** est : %zu octet(s)\n", sizeof(float**));
    printf("La taille de double** est : %zu octet(s)\n\n", sizeof(double**));
    
    // Pointeurs de pointeurs de pointeurs (triple pointeurs)
    printf("--- POINTEURS DE POINTEURS DE POINTEURS ---\n");
    printf("La taille de int*** est : %zu octet(s)\n", sizeof(int***));
    printf("La taille de char*** est : %zu octet(s)\n", sizeof(char***));
    printf("La taille de float*** est : %zu octet(s)\n", sizeof(float***));
    printf("La taille de double*** est : %zu octet(s)\n\n", sizeof(double***));
    
    // Types spéciaux
    printf("--- TYPES SPÉCIAUX ---\n");
    printf("La taille de void* est : %zu octet(s)\n", sizeof(void*));
    printf("La taille de size_t est : %zu octet(s)\n\n", sizeof(size_t));
    
    // Tableaux
    printf("--- TABLEAUX ---\n");
    int tableau_int[10];
    char tableau_char[20];
    float tableau_float[5];
    printf("La taille de int[10] est : %zu octet(s)\n", sizeof(tableau_int));
    printf("La taille de char[20] est : %zu octet(s)\n", sizeof(tableau_char));
    printf("La taille de float[5] est : %zu octet(s)\n\n", sizeof(tableau_float));
    
    printf("========================================\n");
    printf("OBSERVATIONS IMPORTANTES :\n");
    printf("========================================\n");
    printf("1. Sur un système 64 bits, tous les pointeurs\n");
    printf("   ont la même taille : %zu octets\n", sizeof(void*));
    printf("2. La taille d'un pointeur ne dépend pas du\n");
    printf("   type de données qu'il pointe\n");
    printf("3. Les pointeurs multiples (**, ***) ont\n");
    printf("   aussi la même taille qu'un pointeur simple\n");
    printf("========================================\n");
    
    return 0;
}
