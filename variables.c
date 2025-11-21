#include <stdio.h>

int main() {
    printf("=== Affectation et affichage des types de base en C ===\n\n");
    
    // i. char
    printf("i. char:\n");
    char c1 = 'A';
    signed char c2 = -65;
    unsigned char c3 = 200;
    printf("   char               : '%c' (valeur: %d)\n", c1, c1);
    printf("   signed char        : %d\n", c2);
    printf("   unsigned char      : %u\n\n", c3);
    
    // ii. short
    printf("ii. short:\n");
    short s1 = 1234;
    signed short s2 = -5678;
    unsigned short s3 = 50000;
    printf("   short              : %hd\n", s1);
    printf("   signed short       : %hd\n", s2);
    printf("   unsigned short     : %hu\n\n", s3);
    
    // iii. int
    printf("iii. int:\n");
    int i1 = 123456;
    signed int i2 = -987654;
    unsigned int i3 = 3000000000;
    printf("   int                : %d\n", i1);
    printf("   signed int         : %d\n", i2);
    printf("   unsigned int       : %u\n\n", i3);
    
    // iv. long int
    printf("iv. long int:\n");
    long int l1 = 1234567890L;
    signed long int l2 = -9876543210L;
    unsigned long int l3 = 4000000000UL;
    printf("   long int           : %ld\n", l1);
    printf("   signed long int    : %ld\n", l2);
    printf("   unsigned long int  : %lu\n\n", l3);
    
    // v. long long int
    printf("v. long long int:\n");
    long long int ll1 = 9876543210123LL;
    signed long long int ll2 = -1234567890123LL;
    unsigned long long int ll3 = 18446744073709551615ULL;
    printf("   long long int      : %lld\n", ll1);
    printf("   signed long long   : %lld\n", ll2);
    printf("   unsigned long long : %llu\n\n", ll3);
    
    // vi. float
    printf("vi. float:\n");
    float f1 = 3.14159f;
    float f2 = -2.71828f;
    float f3 = 1.23456e5f;
    printf("   float (valeur 1)   : %f\n", f1);
    printf("   float (valeur 2)   : %f\n", f2);
    printf("   float (notation scientifique) : %e\n\n", f3);
    
    // vii. double
    printf("vii. double:\n");
    double d1 = 3.141592653589793;
    double d2 = -2.718281828459045;
    double d3 = 1.23456789e10;
    printf("   double (valeur 1)  : %lf\n", d1);
    printf("   double (valeur 2)  : %lf\n", d2);
    printf("   double (notation scientifique) : %e\n\n", d3);
    
    // viii. long double
    printf("viii. long double:\n");
    long double ld1 = 3.14159265358979323846L;
    long double ld2 = -1.41421356237309504880L;
    long double ld3 = 6.02214076e23L;
    printf("   long double (valeur 1) : %Lf\n", ld1);
    printf("   long double (valeur 2) : %Lf\n", ld2);
    printf("   long double (notation scientifique) : %Le\n\n", ld3);
    
    printf("=== Programme terminé avec succès ===\n");
    
    return 0;
}
