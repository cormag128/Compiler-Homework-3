#include <vector>
#include "symbolmap.hpp"

struct Type;
struct Expr;
struct stmt;

struct decl
{
    ~decl();
};

//declare a variable
struct variable_decl : decl
{
    symbol* sym;
    Expr* exp;
    Type* typ;
};
