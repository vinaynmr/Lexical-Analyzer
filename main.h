#ifndef MAIN_H
#define MAIN_H

#include "types.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

#define LINE_SIZE 500
#define KEYWORD_ARR_SIZE 33
#define OPERATOR_ARR_SIZE 13
#define DELIMITOR_ARR_SIZE 13
#define WORD_SIZE 30

typedef struct project_use
{
    FILE *fp;
    char ch;
    int n;
    char word[WORD_SIZE];
    char arr[LINE_SIZE];
    char *keywords_arr[KEYWORD_ARR_SIZE];
    char operators_arr[OPERATOR_ARR_SIZE];
    char delimitors_arr[DELIMITOR_ARR_SIZE];
}lex_analysis;

//check given arguments is corect or not
status validation(int argc,char *argv[],lex_analysis *lex);

#endif
