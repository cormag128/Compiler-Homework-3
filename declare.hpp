#include <vector>
#include "symbolmap.hpp"

struct Type;
struct Expr;
struct stmt;
struct variable_decl;
struct parameter_decl;
struct func_decl;

struct decl
{
    struct visitor;
    ~decl();
};

//visitor stuff
struct decl::visitor
{
    virtual void visit(variable_decl*) = 0;
    virtual void visit(func_decl*) = 0;
    virtual void visit(parameter_decl*) = 0;
};

//declare a variable
struct variable_decl : decl
{
    symbol* sym;
    Expr* exp;
    Type* typ;
    void accept(visitor& v) {return v.visit(this);}
};

//declare a parameter
struct parameter_decl : decl
{
    symbol* sym;
    Expr* exp;
    Type* typ;
    void accept(visitor& v) {return v.visit(this);}
};

//declare a function
struct func_decl : decl
{
    symbol* sym;
    Expr* exp;
    Type* typ;
    void accept(visitor& v) {return v.visit(this);}
};
