#include "parser.hpp"

//basic constructor
parser::parser(Context& cxt, const std::string& str) : lex(str)
{
    if(token* tok = lex.lex())
    {
        tdeque.push_front(tok);
    }
}

//check to see if we are at eof
bool parser::eof()
{
    return tdeque.empty();
}

//check what the current token is
token* parser::currtoken()
{
    if(!tdeque.empty())
        return tdeque.front();
    else
        return nullptr;
}

//check what the token i away is
token* parser::currtoken(int i)
{
    while(i)
    {
        if(i == 0)
        {
            return currtoken();
        }
        else if(token* tok = lex.lex())
        {
            tdeque.push_back(tok);
        }
        else
        {
            return nullptr;
        }
        i--;
    }
    return tdeque.back();
}

//check what the current tokens type is
token_type parser::lookahead()
{
    if(token* tok = currtoken())
    {
        return tok->type;
    }
    else
    {
        return eof_tok;
    }
}

//check what the token i aways type is
token_type parser::lookahead(int i)
{
    if(token* tok = currtoken(i))
    {
        return tok->type;
    }
    else
    {
        return eof_tok;
    }
}

token* parser::consume()
{
    token* tok = tdeque.front();
    tdeque.pop_front();

    return tok;
}

//require the token type t
token* parser::require(token_type t)
{
    if(lookahead() == t)
    {
        return consume();
    }
    else
    {
        return nullptr;
    }
}

token* parser::sametok(token_type t)
{
    if(lookahead() == t)
    {
        return consume();
    }
    else
    {
        std::cout << "invalid token type";
        return nullptr;
    }
}
