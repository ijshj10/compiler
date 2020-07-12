#include "lex.h"
#include <stdio.h>

int statements();
int expression();
int term();
int expr_prime();
int term_prime();

int statements(){
    expression();

    if(match(SEMI))
        advance();
    else
        fprintf(stderr, "%d: Inserting missing semicolon\n", yylineno);
    
    if(!match(EOI))
        statements();
}

int expression(){
    term();
    expr_prime();
}