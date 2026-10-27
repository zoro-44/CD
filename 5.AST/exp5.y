
%{
#include <stdio.h>
#include <stdlib.h>

typedef struct ast {
    char nodetype;
    struct ast *left;
    struct ast *right;
    int value;
} AST;

AST *new_node(char nodetype, AST *left,
              AST *right, int value);
void print_ast(AST *node);
int yylex(void);
void yyerror(const char *msg);
%}

%union {
    int num;
    AST *node;
}

%token <num> NUMBER
%type <node> expr term factor
%left '+' '-'
%left '*' '/'

%%
input:
    expr '\n' {
        printf("Parsed AST: ");
        print_ast($1);
        printf("\n");
    }
    ;

expr:
      expr '+' term {
          $$ = new_node('+', $1, $3, 0);
      }
    | expr '-' term {
          $$ = new_node('-', $1, $3, 0);
      }
    | term {
          $$ = $1;
      }
    ;

term:
      term '*' factor {
          $$ = new_node('*', $1, $3, 0);
      }
    | term '/' factor {
          $$ = new_node('/', $1, $3, 0);
      }
    | factor {
          $$ = $1;
      }
    ;

factor:
      '(' expr ')' {
          $$ = $2;
      }
    | NUMBER {
          $$ = new_node('N', NULL, NULL, $1);
      }
    ;
%%

AST *new_node(char nodetype, AST *left,
              AST *right, int value)
{
    AST *node = malloc(sizeof(AST));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->nodetype = nodetype;
    node->left = left;
    node->right = right;
    node->value = value;

    return node;
}

void print_ast(AST *node)
{
    if (node == NULL)
        return;

    if (node->nodetype == 'N') {
        printf("%d", node->value);
    } else {
        printf("(");
        print_ast(node->left);
        printf(" %c ", node->nodetype);
        print_ast(node->right);
        printf(")");
    }
}

void yyerror(const char *msg)
{
    printf("Syntax error: %s\n", msg);
}

int main()
{
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
