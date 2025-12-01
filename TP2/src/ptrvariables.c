#include <stdio.h>
#include <string.h>

int main() {
    // Déclaration des variables de différents types
    char c = 'A';
    short s = 1000;
    int i = -1523457281;
    long int li = 123456789L;
    long long int lli = 9876543210LL;
    float f = 2.0f;
    double d = 3.14159;
    long double ld = 2.718281828L;
    
    // Déclaration des pointeurs pour chaque type
    char *ptr_c = &c;
    short *ptr_s = &s;
    int *ptr_i = &i;
    long int *ptr_li = &li;
    long long int *ptr_lli = &lli;
    float *ptr_f = &f;
    double *ptr_d = &d;
    long double *ptr_ld = &ld;
    
    printf("========================================\n");
    printf("AVANT LA MANIPULATION :\n");
    printf("========================================\n\n");
    
    // Affichage des adresses et valeurs AVANT manipulation
    printf("char c :\n");
    printf("  Adresse : %p, Valeur : %02x\n\n", (void*)ptr_c, *(unsigned char*)ptr_c);
    
    printf("short s :\n");
    printf("  Adresse : %p, Valeur : %04x\n\n", (void*)ptr_s, *(unsigned short*)ptr_s);
    
    printf("int i :\n");
    printf("  Adresse : %p, Valeur : %08x\n\n", (void*)ptr_i, *(unsigned int*)ptr_i);
    
    printf("long int li :\n");
    printf("  Adresse : %p, Valeur : %08lx\n\n", (void*)ptr_li, *(unsigned long*)ptr_li);
    
    printf("long long int lli :\n");
    printf("  Adresse : %p, Valeur : %016llx\n\n", (void*)ptr_lli, *(unsigned long long*)ptr_lli);
    
    printf("float f :\n");
    unsigned int f_hex;
    memcpy(&f_hex, ptr_f, sizeof(float));
    printf("  Adresse : %p, Valeur : %08x\n\n", (void*)ptr_f, f_hex);
    
    printf("double d :\n");
    unsigned long long d_hex;
    memcpy(&d_hex, ptr_d, sizeof(double));
    printf("  Adresse : %p, Valeur : %016llx\n\n", (void*)ptr_d, d_hex);
    
    printf("long double ld :\n");
    printf("  Adresse : %p, Valeur : ", (void*)ptr_ld);
    unsigned char *ld_bytes = (unsigned char*)ptr_ld;
    for (int j = sizeof(long double) - 1; j >= 0; j--) {
        printf("%02x", ld_bytes[j]);
    }
    printf("\n\n");
    
    printf("========================================\n");
    printf("MANIPULATION VIA POINTEURS...\n");
    printf("========================================\n\n");
    
    // Manipulation des variables via les pointeurs
    *ptr_c = 'Z';
    *ptr_s = 2000;
    *ptr_i = -1523457282;
    *ptr_li = 987654321L;
    *ptr_lli = 1234567890LL;
    *ptr_f = 1.0f;
    *ptr_d = 2.71828;
    *ptr_ld = 3.141592653589793L;
    
    printf("========================================\n");
    printf("APRÈS LA MANIPULATION :\n");
    printf("========================================\n\n");
    
    // Affichage des adresses et valeurs APRÈS manipulation
    printf("char c :\n");
    printf("  Adresse : %p, Valeur : %02x\n\n", (void*)ptr_c, *(unsigned char*)ptr_c);
    
    printf("short s :\n");
    printf("  Adresse : %p, Valeur : %04x\n\n", (void*)ptr_s, *(unsigned short*)ptr_s);
    
    printf("int i :\n");
    printf("  Adresse : %p, Valeur : %08x\n\n", (void*)ptr_i, *(unsigned int*)ptr_i);
    
    printf("long int li :\n");
    printf("  Adresse : %p, Valeur : %08lx\n\n", (void*)ptr_li, *(unsigned long*)ptr_li);
    
    printf("long long int lli :\n");
    printf("  Adresse : %p, Valeur : %016llx\n\n", (void*)ptr_lli, *(unsigned long long*)ptr_lli);
    
    printf("float f :\n");
    memcpy(&f_hex, ptr_f, sizeof(float));
    printf("  Adresse : %p, Valeur : %08x\n\n", (void*)ptr_f, f_hex);
    
    printf("double d :\n");
    memcpy(&d_hex, ptr_d, sizeof(double));
    printf("  Adresse : %p, Valeur : %016llx\n\n", (void*)ptr_d, d_hex);
    
    printf("long double ld :\n");
    printf("  Adresse : %p, Valeur : ", (void*)ptr_ld);
    ld_bytes = (unsigned char*)ptr_ld;
    for (int j = sizeof(long double) - 1; j >= 0; j--) {
        printf("%02x", ld_bytes[j]);
    }
    printf("\n\n");
    
    return 0;
}
