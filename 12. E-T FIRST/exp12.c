
#include <stdio.h>
#include <string.h>

char E[10], Ep[10], T[10], Tp[10], F[10];

void add(char *s, char c)
{
    int i = strlen(s);
    s[i] = c;
    s[i + 1] = '\0';
}

void compute()
{
    E[0] = Ep[0] = T[0] = Tp[0] = F[0] = '\0';

    add(F, '(');
    add(F, 'i');

    strcpy(T, F);

    add(Tp, '*');
    add(Tp, 'e');

    strcpy(E, T);

    add(Ep, '+');
    add(Ep, 'e');
}

void print(char *n, char *s)
{
    int i;

    printf("FIRST(%s) = { ", n);

    for (i = 0; s[i]; i++)
    {
        if (s[i] == 'i')
            printf("id");
        else if (s[i] == 'e')
            printf("epsilon");
        else
            printf("%c", s[i]);

        if (s[i + 1])
            printf(", ");
    }

    printf(" }\n");
}

int main()
{
    compute();

    print("E", E);
    print("Ep", Ep);
    print("T", T);
    print("Tp", Tp);
    print("F", F);

    return 0;
}

