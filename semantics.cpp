#include "ast.hpp"
#include "semantics.hpp"
#include "token.hpp"
#include "declare.hpp"
#include "statements.hpp"

//basic constructor
semantics::semantics(Context& con)
{
    cxt = &con;
}

//return bool type
Type* semantics::bool_type()
{
   return cxt->bool_ty;
}

//return int type
Type* semantics::int_type()
{
    return cxt->int_ty;
}

Expr* semantics::aand(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::aor(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::anot(Expr* e1)
{
    return nullptr;
}

Expr* semantics::axor(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::aequal(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::anotequal(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::aless(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::agreater(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::agreaterorequal(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::alessorequal(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::aadd(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::asub(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::adiv(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::amult(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::amod(Expr* e1, Expr* e2)
{
    return nullptr;
}

Expr* semantics::aneg(Expr* e1)
{
    return nullptr;
}

Expr* semantics::atrue(token*)
{
    return new Bool_expr(cxt->bool_ty,true);
}

Expr* semantics::afalse(token*)
{
    return new Bool_expr(cxt->bool_ty,false);
}

Expr* semantics::aint(token* tok)
{
    int_token* inttok = static_cast<int_token*>(tok);
    return new Int_expr(cxt->int_ty,inttok->val);
}

Expr* semantics::aid(symbol* sym)
{
    return nullptr;
}

symbol* semantics::aidentifier(token* tok)
{

}
