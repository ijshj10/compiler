#ifndef LEX_H
#define LEX_H

extern char *yytext;
extern int yyleng;
extern int yylineno;


enum token_type{
    EOI,
    SEMI,
    PLUS,
    TIMES,
    LP,
    RP,
    NUM_OR_ID
};

int match(enum token_type);
void advance();

#endif