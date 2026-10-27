
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int iskeyword(char buffer[])
{
    char keywords[10][10] = {
        "int", "float", "if", "else", "while",
        "for", "return", "char", "double", "void"
    };

    int i;
    for (i = 0; i < 10; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    int ch;
    char buffer[20];
    FILE *fp;
    int i = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch) || ch == '_')
        {
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                if (i < 19)
                    buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            if (iskeyword(buffer))
                printf("%s is keyword\n", buffer);
            else
                printf("%s is Identifier\n", buffer);

            if (ch == EOF)
                break;
        }

        if (isdigit(ch))
        {
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
            {
                if (i < 19)
                    buffer[i++] = ch;
            }

            buffer[i] = '\0';
            i = 0;

            printf("%s is constant\n", buffer);

            if (ch == EOF)
                break;
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            printf("%c is operator\n", ch);
        else if (ch == '=' || ch == ';' || ch == ',' ||
                 ch == '(' || ch == ')')
            printf("%c is special symbol\n", ch);
    }

    fclose(fp);
    return 0;
}

