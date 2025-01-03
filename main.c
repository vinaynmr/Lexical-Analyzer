#include "main.h"
#include "types.h"
#include "lexeme.h"

int main(int argc,char *argv[])
{
    lex_analysis lex;
    char *keywords[KEYWORD_ARR_SIZE] = {"int","float","double","char","if","else","switch","case","default","break","continue","return","signed","short","unsigned","long","auto","register","static","extern","sizeof","typedef","const","volatile","void","return","struct","union","enum","goto","for","while","do"};
    for(int i = 0; i < KEYWORD_ARR_SIZE; i++)
        lex.keywords_arr[i] = keywords[i];
    char operators[OPERATOR_ARR_SIZE] = {'+','-','*','/','%','=','>','<','&','|','~','^','!'};
    for(int i = 0; i < OPERATOR_ARR_SIZE; i++)
        lex.operators_arr[i] = operators[i];
    char delimitors[DELIMITOR_ARR_SIZE] = {'.','\n',',','{','}','#','(',')','[',']',':',';'};
    for(int i = 0; i < DELIMITOR_ARR_SIZE; i++)
        lex.delimitors_arr[i] = delimitors[i];
    status res = validation(argc,argv,&lex);
    if(res == failure)
    {
        printf("Validation failed\n");
        return 0;
    }
    
    res = classification_print(&lex);
    if(res == failure)
    {
        printf("CLassification failed\n");
        return 0;
    }
}

status validation(int argc,char *argv[],lex_analysis *lex)
{
    if(argc != 2)
    {
        printf("Check input arguments\n");
        return failure;
    }
    if(!strcmp(argv[1],"sample_code.c"))
    {
        lex -> fp =  fopen(argv[1],"r");
        if(lex -> fp == NULL)
        {
            printf("FILE IS NOT AVAILBLE\n");
            return failure;
        }else
            return success;
    }
    return failure;
}
