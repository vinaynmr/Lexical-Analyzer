#include "lexeme.h"
status classification_print(lex_analysis *lex)
{
    fseek(lex ->fp,0,SEEK_SET);
    while(!feof(lex -> fp))
    {
        operator_check_and_print(lex);
        delimitor_check_and_print(lex);
        keyword_identifier_and_literal(lex);
    }
}

void operator_check_and_print(lex_analysis *lex)
{
    int flag;
    while((lex -> ch = fgetc(lex -> fp)) != EOF)
    {
        flag = 1;
        if(lex -> ch == ' ')
            continue;
        for(int i = 0; i < OPERATOR_ARR_SIZE; i++)
        {
            if(lex -> ch == lex -> operators_arr[i]) 
            {
                flag = 0;
                printf("OPERATOR: %c\n",lex -> ch);
                break;
            }
        }
        if(flag)
        {
            fseek(lex -> fp,-1,SEEK_CUR);
            break;
        }
    }
}

void delimitor_check_and_print(lex_analysis *lex)
{
    int flag;
    while((lex -> ch = fgetc(lex -> fp)) != EOF)
    {
        flag = 1;
        if(lex -> ch == ' ')
            continue;
        for(int i = 0;i < DELIMITOR_ARR_SIZE; i++)
        {
            if(lex -> ch == lex -> delimitors_arr[i])
            {
                flag = 0;
                printf("DELIMITOR: %c\n",lex -> ch);
                break;
            }
        }
        if(flag)
        {
            fseek(lex -> fp,-1,SEEK_CUR);
            break;
        }
    }
}

void keyword_identifier_and_literal(lex_analysis *lex)
{
    int k = 0,count = 0;
    while((lex -> ch = fgetc(lex -> fp)) != EOF)
    {
        if(lex -> ch == 34 || lex -> ch == 39)
        {
            string_or_char_literals(lex);
            goto label;
        }
        if(lex -> ch >= 48 && lex -> ch <= 57)
            lex -> arr[k++] = lex -> ch;
        else if(lex -> ch >= 65 && lex -> ch <= 90)
            lex -> arr[k++] = lex -> ch;
        else if(lex -> ch >= 97 && lex -> ch <= 122)
            lex -> arr[k++] = lex -> ch;
        else if(lex -> ch == '_')
            lex -> arr[k++] = lex -> ch;
        else{
            fseek(lex -> fp,-1,SEEK_CUR);
            break;
        }
    }
    lex -> arr[k] = '\0';
    status ret = keyword_check_and_print(lex);
    if(ret == failure && k > 1)
    {
        if(lex -> ch == '(') {
            printf("IDENTIFIER: %s\n",lex -> arr);
        }
        else {
            printf("LITERAL: %s\n",lex -> arr);
        }
    }
label:
        lex -> ch = lex -> ch;
}

void string_or_char_literals(lex_analysis *lex)
{
    printf("LITERAL: %c",lex -> ch);
    while((lex -> ch = fgetc(lex -> fp)) != '"')
        printf("%c",lex -> ch);
    printf("%c\n",lex -> ch);
}


status keyword_check_and_print(lex_analysis *lex)
{
    for(int i = 0; i < KEYWORD_ARR_SIZE; i++)
    {
        if(!strcmp(lex -> arr,lex -> keywords_arr[i]))
        {
            printf("KEYWORD: %s\n",lex -> arr);
            return success;
        }
    } 
    return failure;
}
