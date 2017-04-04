#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <vector>

//lex struct
struct lexer
{
    //constructors
    lexer(const char*, const char*);
    lexer(const std::string&);

    //function declarations
    bool eof();
    char lookahead();
    char consume();
    token* lex();
    void ignoresp();
    token* addtoken(token_type tok);

    //necessary char pointers for moving through the strings
    const char* first;
    const char* final;

    //string input and vector for storing the tokens as they come out
    std::string buf;
    std::vector<token*> tokenvec;
};

#endif
