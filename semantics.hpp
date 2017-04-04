#include "token.hpp"

struct semantics
{
    semantics(Context&);

    Type* bool_type();
    Type* int_type();

    Expr* add(Expr*,Expr*);
    Expr* sub(Expr*,Expr*);
    Expr* div(Expr*,Expr*);
    Expr* mult(Expr*,Expr*);
    Expr* mod(Expr*,Expr*);
    Expr* neg(Expr*);

    Expr* on_true(token*);
    Expr* on_false(token*);

    Context* cxt;
};
