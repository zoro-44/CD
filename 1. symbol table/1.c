
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol[20];
    char *address;
    char type[20];
} Symbol;

int main() {
    char exp[100], c;
    Symbol table[20];
    int i = 0, x = 0;

    printf("Enter expression (end with $): ");
    scanf("%99s", exp);

    printf("\nGiven Expression: %s\n", exp);
    printf("\nSymbol\tAddress\t\tType\n");

    for (i = 0; exp[i] != '\0' && exp[i] != '$' && x < 20; i++) {
        c = exp[i];

        if (isalpha((unsigned char)c)) {
            table[x].symbol[0] = c;
            table[x].symbol[1] = '\0';
            table[x].address = &exp[i];
            strcpy(table[x].type, "Identifier");

            printf("%c\t%p\t%s\n",
                   table[x].symbol[0],
                   (void *)table[x].address,
                   table[x].type);
            x++;
        }
        else if (c == '+' || c == '-' || c == '*' ||
                 c == '/' || c == '=') {
            table[x].symbol[0] = c;
            table[x].symbol[1] = '\0';
            table[x].address = &exp[i];
            strcpy(table[x].type, "Operator");

            printf("%c\t%p\t%s\n",
                   table[x].symbol[0],
                   (void *)table[x].address,
                   table[x].type);
            x++;
        }
    }

    return 0;
}

