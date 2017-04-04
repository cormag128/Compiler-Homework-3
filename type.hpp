
#include "ast.hpp"

#include <iostream>

//set up our type checking to make sure we take the correct typings
Type* check(Context& cxt, Expr* e)
{
  struct V : Expr::Visitor {
    Context& cxt;
    Type* r;
    V(Context& c) : cxt(c) { }
    void visit(Bool_expr* e) {
      r = &cxt.bool_type;
    }
    void visit(And_expr* e) {
      // check that e->e1 is bool
      // check that e->e2 is bool
        if(check(cxt,e->e1) == &cxt.bool_type && check(cxt,e->e2) == &cxt.bool_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }
    void visit(Or_expr* e) {
      // check that e->e1 is bool
      // check that e->e2 is bool
      if(check(cxt,e->e1) == &cxt.bool_type && check(cxt,e->e2) == &cxt.bool_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(Not_expr* e) {
      // check that e->e1 is bool
      if(check(cxt,e->e1) == &cxt.bool_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(xor_expr* e) {
        // check that e->e1 is bool
        // check that e->e2 is bool
        if(check(cxt,e->e1) == &cxt.bool_type && check(cxt,e->e2) == &cxt.bool_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(ifthenelse_expr* e) {
        // check that e->e1 is bool
        // check that e->e2 is bool
        // check that e->e3 is bool
        if(check(cxt,e->e1) == &cxt.bool_type && check(cxt,e->e2) == &cxt.bool_type && check(cxt,e->e2) == &cxt.bool_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(equal_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(notequal_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(lessthan_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(greaterthan_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(lessorequal_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(greaterorequal_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.bool_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(add_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(sub_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(mult_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(div_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(rem_expr* e) {
        // check that e->e1 is int
        // check that e->e2 is int
        if(check(cxt,e->e1) == &cxt.int_type && check(cxt,e->e2) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

    void visit(neg_expr* e) {
        // check that e->e1 is int
        if(check(cxt,e->e1) == &cxt.int_type){
            r = &cxt.int_type;
        }
        else{
            std::cout << "Invalid Data Types\n";
        }
    }

  };
  V vis(cxt);
  e->accept(vis);
  return vis.r;
}
