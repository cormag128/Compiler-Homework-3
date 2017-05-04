//building statements
struct Expr;
struct decl;

//statement struct
struct stmt
{
    ~stmt() = default;
};

//Expression statements
struct Expr_stmt : stmt
{
    Expr* expression;
    Expr_stmt(Expr* e) : expression(e) {}
};

//Declaration statements
struct decl_stmt : stmt
{
    decl* entity;
    decl_stmt(decl* d) : entity(d){}
};
