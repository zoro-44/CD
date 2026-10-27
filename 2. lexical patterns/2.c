
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *word) {
    char keywords[][10] = {
        "int", "char", "float", "double", "void",
        "if", "else", "for", "while", "return",
        "break", "continue", "do", "long", "short"
    };

    int i;
    for (i = 0; i < 15; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char line[1000], buf[1000];
    int i = 0, p = 0;

    printf("Enter a line of code:\n");
    fgets(line, sizeof(line), stdin);

    printf("\n--- Lexical Analysis Output ---\n");

    for (p = 0; line[p] != '\0'; p++) {
        char ch = line[p];

        if (isalpha((unsigned char)ch) || ch == '_') {
            i = 0;
            buf[i++] = ch;

            while (isalnum((unsigned char)line[p + 1]) ||
                   line[p + 1] == '_') {
                buf[i++] = line[++p];
            }

            buf[i] = '\0';

            if (isKeyword(buf))
                printf("[Keyword : %s]\n", buf);
            else
                printf("[Identifier : %s]\n", buf);
        }
        else if (isdigit((unsigned char)ch)) {
            i = 0;
            buf[i++] = ch;

            while (isdigit((unsigned char)line[p + 1]) ||
                   line[p + 1] == '.') {
                buf[i++] = line[++p];
            }

            buf[i] = '\0';
            printf("[Constant : %s]\n", buf);
        }
        else if (ch == '/' && line[p + 1] == '/') {
            printf("[Single-line Comment]\n");
            break;
        }
        else if (strchr("=+-*/<>!", ch) != NULL) {
            if (line[p + 1] == '=')
                printf("[Operator : %c%c]\n", ch, line[++p]);
            else
                printf("[Operator : %c]\n", ch);
        }
        else if (strchr(";,(){}[]", ch) != NULL) {
            printf("[Delimiter : %c]\n", ch);
        }
        else if (isspace((unsigned char)ch)) {
            continue;
        }
        else {
            printf("[Unknown : %c]\n", ch);
        }
    }

    return 0;
}

