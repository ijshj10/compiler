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

int expr_prime(){
    if(match(PLUS)){
        advance();
        term();
        expr_prime();
    }
}

int term(){
    factor();
    term_prime();
}

int term_prime(){
    if(match(TIMES)) {
        advance();
        factor();
        term_prime();
    }
}

int factor(){
    if(match(NUM_OR_ID))
        advance();
    else if(match(LP)){
        advance();
        expression();
        if(match(RP))
            advance();
        else
            fprintf(stderr, "%d: Mismatched parenthsis\n,",  yylineno);
    }
    else
        fprintf(stderr, "%d: Number or identifiler expected\n,",  yylineno);
}