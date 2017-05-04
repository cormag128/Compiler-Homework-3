#include "scopemap.hpp"
#include "symbolmap.hpp"
#include <vector>
#pragma once

//struct builds
struct token;
struct context;
struct Type;
struct Expr;
struct decl;
struct stmt;

//semantics functions for the compiler.
struct semantics
{
    semantics(Context&);

    //Types
    Type* bool_type();
    Type* int_type();

    //Statements
    stmt* decl_statement(decl*);
    stmt* expr_statement(Expr*);

    //Declarations
    decl* var_declaration(Type*, symbol*);
    decl* var_completion(decl*, Expr*);

    //Expressions
    Expr* aand(Expr*,Expr*);
    Expr* aor(Expr*,Expr*);
    Expr* anot(Expr*);
    Expr* axor(Expr*,Expr*);
    Expr* aequal(Expr*,Expr*);
    Expr* anotequal(Expr*,Expr*);
    Expr* aless(Expr*,Expr*);
    Expr* agreater(Expr*,Expr*);
    Expr* agreaterorequal(Expr*,Expr*);
    Expr* alessorequal(Expr*,Expr*);
    Expr* aadd(Expr*,Expr*);
    Expr* asub(Expr*,Expr*);
    Expr* adiv(Expr*,Expr*);
    Expr* amult(Expr*,Expr*);
    Expr* amod(Expr*,Expr*);
    Expr* aneg(Expr*);
    Expr* atrue(token*);
    Expr* afalse(token*);
    Expr* aint(token *);
    Expr* aid(symbol *);

    //Symbols
    symbol* aidentifier(token*);

    //Context for the semantics
    Context* cxt;

    //Enviornments for the semantics
    enviornment envior;
};
