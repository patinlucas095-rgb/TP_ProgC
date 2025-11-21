
#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    int resultat;
    
    // Demander à l'utilisateur d'entrer les valeurs
    printf("Entrez le premier nombre (num1) : ");
    scanf("%d", &num1);
    
    printf("Entrez le deuxième nombre (num2) : ");
    scanf("%d", &num2);
    
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);
    
    // Utiliser switch pour déterminer l'opération
    switch(op) {
        case '+':
            resultat = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, resultat);
            break;
            
        case '-':
            resultat = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, resultat);
            break;
            
        case '*':
            resultat = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, resultat);
            break;
            
        case '/':
            if (num2 != 0) {
                resultat = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : Division par zéro impossible!\n");
            }
            break;
            
        case '%':
            if (num2 != 0) {
                resultat = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : Modulo par zéro impossible!\n");
            }
            break;
            
        case '&':
            resultat = num1 & num2;
            printf("%d & %d = %d (ET binaire)\n", num1, num2, resultat);
            break;
            
        case '|':
            resultat = num1 | num2;
            printf("%d | %d = %d (OU binaire)\n", num1, num2, resultat);
            break;
            
        case '~':
            resultat = ~num1;
            printf("~%d = %d (NON binaire de num1)\n", num1, resultat);
            printf("Note : L'opérateur ~ est unaire, num2 est ignoré.\n");
            break;
            
        default:
            printf("Erreur : Opérateur '%c' non reconnu!\n", op);
            printf("Opérateurs valides : +, -, *, /, %%, &, |, ~\n");
            break;
    }
    
    return 0;
}


