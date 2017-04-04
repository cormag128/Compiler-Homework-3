#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include <vector>

struct lexer
{
    lexer(const char*, const char*);
    lexer(const std::string&);

    bool eof();
    char lookahead();
    char consume();
    token* lex();
    void ignoresp();
    token* addtoken(token_type tok);

    const char* first;
    const char* final;

    std::string buf;
    std::vector<token*> tokenvec;
};

#endif
