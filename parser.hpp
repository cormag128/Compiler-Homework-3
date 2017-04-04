#include "token.hpp"
#include "lexer.hpp"
#include "ast.hpp"
#include <vector>
#include <deque>

//parser struct
struct parser
{

    //necessary data types
    std::deque<token*> tdeque;
    lexer lex;

    //constructor
    parser(Context&, const std::string&);

    //basic commands
    bool eof();
    token* currtoken();
    token* currtoken(int);
    token* consume();
    token* require(token_type);
    token* sametok(token_type);
    token_type lookahead();
    token_type lookahead(int);
};
