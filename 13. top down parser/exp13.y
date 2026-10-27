
%{
#include <stdio.h>
%}

%token A B

%%
S : A X { printf("Parser S -> aA\n"); }
  ;

X : B { printf("Parser A -> b\n"); }
  |   { printf("Parser A -> epsilon\n"); }
  ;
%%

int main()
{
    printf("Enter input (a or ab): ");
    yyparse();
    return 0;
}

int yyerror(char *msg)
{
    printf("Syntax error: %s\n", msg);
    return 0;
}

int yylex()
{
    int c = getchar();

    if (c == 'a')
        return A;
    if (c == 'b')
        return B;
    if (c == '\n' || c == EOF)
        return 0;

    return c;
}
