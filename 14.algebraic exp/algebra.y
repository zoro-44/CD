
%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
stmt : expr {
    printf("Evaluated result = %d\n", $1);
}
;

expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr {
         if ($3 == 0) {
             printf("Divide by zero!\n");
             exit(1);
         }
         $$ = $1 / $3;
     }
     | '(' expr ')' { $$ = $2; }
     | NUMBER { $$ = $1; }
;
%%

int main()
{
    printf("Enter algebraic expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *msg)
{
    printf("Syntax error: %s\n", msg);
    return 0;
}
