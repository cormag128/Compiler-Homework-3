#include "ast.hpp"
#include "semantics.hpp"

//basic constructor
semantics::semantics(Context& con)
{
    cxt = &con;
}

//return bool type
Type* semantics::bool_type()
{

}

//return int type
Type* semantics::int_type()
{

}

Expr* semantics::add(Expr* e1, Expr* e2)
{
    return nullptr;
}
