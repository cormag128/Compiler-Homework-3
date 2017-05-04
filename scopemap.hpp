#include "symbolmap.hpp"
#include <unordered_map>

struct context;
struct token;
struct stmt;
struct Expr;
struct Type;
struct decl;

//build enviornment for keeping the scope
struct enviornment
{
    decl* find(symbol*);
    void insert(symbol*, decl*);
    std::unordered_map<symbol*, decl*> scope;
};
