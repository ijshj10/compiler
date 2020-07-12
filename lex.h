#ifndef LEX_H
#define LEX_H

extern char *yytext;
extern int yyleng;
extern int yylineno;


enum{
    EOI,
    SEMI,
    PLUS,
    TIMES,
    LP,
    RP,
    NUM_OR_ID
};

#endif