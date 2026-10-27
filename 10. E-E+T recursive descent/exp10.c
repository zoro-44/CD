
#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum {
    ID, PLUS, MUL, LPAREN, RPAREN, END, INVALID
};

int token;
char *p;

void next()
{
    while (isspace((unsigned char)*p))
        p++;

    if (isalpha((unsigned char)*p))
    {
        token = ID;
        while (isalnum((unsigned char)*p))
            p++;
    }
    else if (*p == '+')
        token = PLUS, p++;
    else if (*p == '*')
        token = MUL, p++;
    else if (*p == '(')
        token = LPAREN, p++;
    else if (*p == ')')
        token = RPAREN, p++;
    else if (*p == '\0' || *p == '\n')
        token = END;
    else
        token = INVALID, p++;
}

int E();
int T();
int F();

int E()
{
    if (!T())
        return 0;

    while (token == PLUS)
    {
        next();
        if (!T())
            return 0;
    }
    return 1;
}

int T()
{
    if (!F())
        return 0;

    while (token == MUL)
    {
        next();
        if (!F())
            return 0;
    }
    return 1;
}

int F()
{
    if (token == ID)
    {
        next();
        return 1;
    }

    if (token == LPAREN)
    {
        next();
        if (!E() || token != RPAREN)
            return 0;

        next();
        return 1;
    }

    return 0;
}

int main()
{
    char line[256];

    printf("Enter expression: ");
    if (!fgets(line, sizeof(line), stdin))
        return 1;

    p = line;
    next();

    if (E() && token == END)
        printf("Parsing succeeded: valid expression\n");
    else
        printf("Parsing failed: invalid expression\n");

    return 0;
}

