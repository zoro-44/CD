
%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
expr:
      expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUMBER
    ;
%%

int main()
{
    printf("Enter an arithmetic expression:\n");
    if (yyparse() == 0)
        printf("Valid arithmetic expression\n");
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid arithmetic expression\n");
    return 0;
}
