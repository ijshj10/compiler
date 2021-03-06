#include "lex.h"
#include <stdio.h>
#include <ctype.h>

char *yytext = "";
int yyleng = 0;
int yylineno = 0;


int lex(){
    static char input_buffer[128];
    char *current;

    current = yytext + yyleng;
    while(1) {
        while(!(*current)) {
            current = input_buffer;
            if(!gets(input_buffer)) {
                *current = '\0';
                return EOI;
            }
            ++yylineno;
            while(isspace(*current))
                ++current;
        }

        for(;*current;++current) {
            yytext = current;
            yyleng = 1;
            switch(*current) {
            case ';': return SEMI;
            case '+': return PLUS;
            case '*': return TIMES;
            case '(': return LP;
            case ')': return RP;

            case ' ':
            case '\t':
            case '\n': break;

            default:
                if(!isalnum(*current)){
                    fprintf(stderr, "Ignoring illegal input <%c>\n", *current);
                }
                else {
                    while(isalnum(*current))
                        current++;
                    yyleng = current - yytext;
                    return NUM_OR_ID;
                }
                break;
            }
        }
    }
}

static int lookahead = -1;

int match(token_type token){
    if(lookahead == -1)
        lookahead = lex();
    return lookahead == token;
}

void advance(){
    lookahead = lex();
}