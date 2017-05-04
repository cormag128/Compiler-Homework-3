#ifndef AST_HPP
#define AST_HPP

#include <cassert>

//struct for types
struct Bool_type;
struct Int_type;
struct decl;

//declarations for expressions
struct Bool_expr;           //Complete
struct Int_expr;            //Framework
struct And_expr;            //Complete
struct Or_expr;             //Complete
struct Not_expr;            //Complete
struct xor_expr;            //Framework
struct ifthenelse_expr;     //Framework
struct equal_expr;          //Framework
struct notequal_expr;       //Framework
struct lessthan_expr;       //Framework
struct greaterthan_expr;    //Framework
struct lessorequal_expr;    //Framework
struct greaterorequal_expr; //Framework
struct add_expr;            //Framework
struct sub_expr;            //Framework
struct mult_expr;           //Framework
struct div_expr;            //Framework
struct rem_expr;            //Framework
struct neg_expr;            //Framework
struct ref_expr;            //Framework

//included struct for type
struct Type {
  struct Visitor;
  virtual ~Type() = default;
  virtual void accept(Visitor&) { }
};

//included structs for types
struct Bool_type : Type { };
struct Int_type : Type { };

struct ref_type : Type
{
    Type* obj;
    ref_type(Type* t) : obj(t){}
};

//Expression building
struct Expr {

    struct Visitor;
    virtual ~Expr() = default;
    virtual void accept(Visitor&) = 0;

    Expr(Type* t) : ty(t){}
    Type* ty;
};

//Expr::Visitor struct
struct Expr::Visitor
{
  virtual void visit(Bool_expr*) = 0;
  virtual void visit(And_expr*) = 0;
  virtual void visit(Or_expr*) = 0;
  virtual void visit(Not_expr*) = 0;
  virtual void visit(xor_expr*) = 0;
  //virtual void visit(ifthenelse_expr*) = 0;
  virtual void visit(equal_expr*) = 0;
  virtual void visit(notequal_expr*) = 0;
  virtual void visit(lessthan_expr*) = 0;
  virtual void visit(greaterthan_expr*) = 0;
  virtual void visit(lessorequal_expr*) = 0;
  virtual void visit(greaterorequal_expr*) = 0;
  virtual void visit(add_expr*) = 0;
  virtual void visit(sub_expr*) = 0;
  virtual void visit(mult_expr*) = 0;
  virtual void visit(div_expr*) = 0;
  virtual void visit(rem_expr*) = 0;
  virtual void visit(neg_expr*) = 0;
  virtual void visit(Int_expr*) = 0;
};

//Boolean expression that sets true or false
struct Bool_expr : Expr {
  bool val;
  Bool_expr(Type* t,bool b) : Expr(t), val(b) { }
  void accept(Visitor& v) { return v.visit(this); }
};

//int expression that returns an int
struct Int_expr : Expr
{
    int val;
    Int_expr(Type* t, int n) : Expr(t), val(n){}
    void accept(Visitor& v) {return v.visit(this);}
};

struct ref_expr : Expr
{
    decl* ref;
    ref_expr(Type* t, decl* d) : Expr(t), ref(d){}
};

//And Expression
struct And_expr : Expr {
  Expr* e1;
  Expr* e2;
  And_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

//Or Expression
struct Or_expr : Expr {
  Expr* e1;
  Expr* e2;
  Or_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2) { }
  void accept(Visitor& v) { return v.visit(this); }
};

//Not Expression
struct Not_expr : Expr {
  Expr* e1;
  Not_expr(Type* t, Expr* e1) : Expr(t), e1(e1) { }
  void accept(Visitor& v) { return v.visit(this); }
};

//Xor Expression
struct xor_expr : Expr {
    Expr* e1;
    Expr* e2;
    xor_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//If, Then, Else, Expression
struct ifthenelse_expr : Expr {
    Expr* e1;
    Expr* e2;
    Expr* e3;
    ifthenelse_expr(Type* t, Expr* e1, Expr* e2, Expr* e3) : Expr(t), e1(e1), e2(e2), e3(e3){}
};

//Equality expression
struct equal_expr : Expr {
    Expr* e1;
    Expr* e2;
    equal_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Non Equality expression
struct notequal_expr : Expr {
    Expr* e1;
    Expr* e2;
    notequal_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Less than expression
struct lessthan_expr : Expr {
    Expr* e1;
    Expr* e2;
    lessthan_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Greater than expression
struct greaterthan_expr : Expr {
    Expr* e1;
    Expr* e2;
    greaterthan_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Less than or equal to expression
struct lessorequal_expr : Expr {
    Expr* e1;
    Expr* e2;
    lessorequal_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Greater than or equal to expression
struct greaterorequal_expr : Expr {
    Expr* e1;
    Expr* e2;
    greaterorequal_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Addition operator
struct add_expr : Expr {
    Expr* e1;
    Expr* e2;
    add_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Subtraction operator
struct sub_expr : Expr {
    Expr* e1;
    Expr* e2;
    sub_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Multiplication operator
struct mult_expr : Expr {
    Expr* e1;
    Expr* e2;
    mult_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Division operator
struct div_expr : Expr {
    Expr* e1;
    Expr* e2;
    div_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Remainder operator, behaves as mod
struct rem_expr : Expr {
    Expr* e1;
    Expr* e2;
    rem_expr(Type* t, Expr* e1, Expr* e2) : Expr(t), e1(e1), e2(e2){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Negative operator, sets a number to negative version
struct neg_expr : Expr {
    Expr* e1;
    neg_expr(Type* t, Expr* e1) : Expr(t), e1(e1){}
    void accept(Visitor& v) { return v.visit(this); }
};

//Context struct for type building
struct Context
{
  Bool_type bool_type;
  Int_type int_type;
  Type* bool_ty;
  Type* int_ty;
};


#endif
