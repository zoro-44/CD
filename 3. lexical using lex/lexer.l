
%{
#include <stdio.h>
%}

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*
KEYWORD (if|else|while|for|return|int|char|float|double|void)
OPERATOR [+\-*/=<>&|!]+
SEPARATOR [(){};,]

%%
{KEYWORD}       { printf("Keyword: %s\n", yytext); }
{ID}            { printf("Identifier: %s\n", yytext); }
{DIGIT}+        { printf("Number: %s\n", yytext); }
{OPERATOR}      { printf("Operator: %s\n", yytext); }
{SEPARATOR}     { printf("Separator: %s\n", yytext); }
[ \t\n]+        ;
.               { printf("Unknown: %s\n", yytext); }
%%

int main()
{
    printf("Enter code:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
