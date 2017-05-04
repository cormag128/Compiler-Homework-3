//building statements
struct Expr;
struct decl;
struct Expr_stmt;
struct decl_stmt;
struct block_stmt;
struct ifelse_stmt;
struct while_stmt;
struct break_stmt;
struct continue_stmt;
struct return_stmt;
struct assert_stmt;

//statement struct
struct stmt
{
    struct visitor;
    ~stmt() = default;
};

//visitor stuff
struct stmt::visitor
{
    virtual void visit(Expr_stmt*) = 0;
    virtual void visit(decl_stmt*) = 0;
    virtual void visit(block_stmt*) = 0;
    virtual void visit(ifelse_stmt*) = 0;
    virtual void visit(while_stmt*) = 0;
    virtual void visit(break_stmt*) = 0;
    virtual void visit(continue_stmt*) = 0;
    virtual void visit(return_stmt*) = 0;
    virtual void visit(assert_stmt*) = 0;
};

//Expression statements
struct Expr_stmt : stmt
{
    Expr* expression;
    Expr_stmt(Expr* e) : expression(e) {}
    void accept(visitor& v) {return v.visit(this);}
};

//Declaration statements
struct decl_stmt : stmt
{
    decl* entity;
    decl_stmt(decl* d) : entity(d){}
    void accept(visitor& v) {return v.visit(this);}
};

struct block_stmt : stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct ifelse_stmt : stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct while_stmt: stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct break_stmt: stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct continue_stmt: stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct return_stmt: stmt
{
    void accept(visitor& v) {return v.visit(this);}
};

struct assert_stmt: stmt
{
    void accept(visitor& v) {return v.visit(this);}
};
