
%{
#include "exp5.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+    { yylval.num = atoi(yytext); return NUMBER; }
[ \t]     ;
\n        { return '\n'; }
.         { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}
