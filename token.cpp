#include "token.hpp"

const char* token::getname(token_type type)
{
    switch(type)
    {
        case add_tok: return "add_tok";
        case minus_tok: return "minus_tok";
        case mult_tok: return "mult_tok";
        case div_tok: return "div_tok";
        case mod_tok: return "mod_tok";
        case and_tok: return "and_tok";
        case or_tok: return "or_tok";
        case exclamation_tok: return "exclamation_tok";
        case equality_tok: return "equality_tok";
        case notequal_tok: return "notequal_tok";
        case lessthan_tok: return "lessthan_tok";
        case greaterthan_tok: return "greaterthan_tok";
        case lessorequal_tok: return "lessorequal_tok";
        case greaterorequal_tok: return "greaterorequal_tok";
        case question_tok: return "question_tok";
        case colon_tok: return "colon_tok";
        case lparen_tok: return "lparen_tok";
        case rparen_tok: return "rparen_tok";

        case bool_tok: return "bool_tok";
        case int_tok: return "int_tok";

        default:
            return "unknown token";
    }
}

const char* token::getsymbol(token_type type)
{
    switch(type)
    {
        case add_tok: return "+";
        case minus_tok: return "-";
        case mult_tok: return "*";
        case div_tok: return "/";
        case mod_tok: return "%";
        case and_tok: return "&&";
        case or_tok: return "||";
        case exclamation_tok: return "!";
        case equality_tok: return "==";
        case notequal_tok: return "!=";
        case lessthan_tok: return "<";
        case greaterthan_tok: return ">";
        case lessorequal_tok: return "<=";
        case greaterorequal_tok: return ">=";
        case question_tok: return "?";
        case colon_tok: return ":";
        case lparen_tok: return "(";
        case rparen_tok: return ")";

        case bool_tok: return "boolean";
        case int_tok: return "integer";

        default:
            return "unknown symbol";
    }
}
