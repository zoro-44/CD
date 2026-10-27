
#include <stdio.h>
#include <ctype.h>

enum {
    TOKEN_A,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_COMMA,
    TOKEN_END,
    TOKEN_INVALID
} token;

const char *p;

void next()
{
    while (isspace((unsigned char)*p))
        p++;

    if (*p == 'a')
        token = TOKEN_A;
    else if (*p == '(')
        token = TOKEN_LPAREN;
    else if (*p == ')')
        token = TOKEN_RPAREN;
    else if (*p == ',')
        token = TOKEN_COMMA;
    else if (*p == '\0' || *p == '\n')
        token = TOKEN_END;
    else
        token = TOKEN_INVALID;

    if (token != TOKEN_END)
        p++;
}

int S(void);
int L(void);

int S(void)
{
    if (token == TOKEN_A)
    {
        next();
        return 1;
    }

    if (token == TOKEN_LPAREN)
    {
        next();

        if (L() && token == TOKEN_RPAREN)
        {
            next();
            return 1;
        }
    }

    return 0;
}

int L(void)
{
    if (!S())
        return 0;

    while (token == TOKEN_COMMA)
    {
        next();

        if (!S())
            return 0;
    }

    return 1;
}

int main(void)
{
    char line[256];

    printf("Enter expression: ");

    if (fgets(line, sizeof(line), stdin) == NULL)
        return 1;

    p = line;
    next();

    if (S() && token == TOKEN_END)
        printf("Parsing succeeded: valid expression\n");
    else
        printf("Parsing failed: invalid expression\n");

    return 0;
}

