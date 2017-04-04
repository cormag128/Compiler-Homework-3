#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include <iostream>

//enumerate all token types in
enum token_type
{
    add_tok,
    minus_tok,
    mult_tok,
    div_tok,
    mod_tok,
    and_tok,
    or_tok,
    exclamation_tok,
    equality_tok,
    notequal_tok,
    lessthan_tok,
    greaterthan_tok,
    lessorequal_tok,
    greaterorequal_tok,
    question_tok,
    colon_tok,
    lparen_tok,
    rparen_tok,

    eof_tok,

    bool_tok,
    int_tok
};

//build basic framework for tokens
struct token
{
    token(token_type t) : type(t){}
    token_type type;

    const char* getname(token_type);
    const char* getsymbol(token_type);
};

//build basic framework for the integer tokens
struct int_token : token
{
    int val;

    int_token(int n) : token(int_tok)
    {
        val = n;
    }
};

//create framework for boolean tokens
struct bool_token : token
{
    bool val;

    bool_token(bool n) : token(bool_tok)
    {
        val = n;
    }
};
#endif
