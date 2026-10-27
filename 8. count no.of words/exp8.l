
%{
#include <stdio.h>

int word_count = 0;
int line_count = 0;
%}

%%
\n                  { line_count++; }
[A-Za-z0-9]+       { word_count++; }
[ \t]+             ;
.                  ;
%%

int main(void)
{
    printf("Enter text (Ctrl+Z to end input on Windows):\n");

    yylex();

    printf("\nTotal lines: %d\n", line_count);
    printf("Total words: %d\n", word_count);

    return 0;
}

int yywrap(void)
{
    return 1;
}
