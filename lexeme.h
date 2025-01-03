#ifndef LEXEME_H
#define LEXEME_H

#include "main.h"
#include "types.h"

//classify the code and print the code ehich is what
status classification_print(lex_analysis *lex);

//check if the character is operator or not
void operator_check_and_print(lex_analysis *lex);


//check for delimitor
void delimitor_check_and_print(lex_analysis *lex);

//check for literal
void keyword_identifier_and_literal(lex_analysis *lex);

//check if the string is keyword or not
status keyword_check_and_print(lex_analysis *lex);

//to print string or char literals
void string_or_char_literals(lex_analysis *lex);

#endif
