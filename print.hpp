
#include "ast.hpp"

#include <iostream>

bool

//decide on all expressions whether we need to return something or not
needs_parens(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = false; }
    void visit(And_expr* e) { r = true; }
    void visit(Or_expr* e) { r = true; }
    void visit(Not_expr* e) { r = true; }
    void visit(xor_expr* e) { r = true; }
    //void visit(ifthenelse_expr* e) { r = true; }
    void visit(equal_expr* e) { r = true; }
    void visit(notequal_expr* e) { r = true; }
    void visit(lessthan_expr* e) { r = true; }
    void visit(greaterthan_expr* e) { r = true; }
    void visit(lessorequal_expr* e) { r = true; }
    void visit(greaterorequal_expr* e) { r = true; }
    void visit(add_expr* e) { r = true; }
    void visit(sub_expr* e) { r = true; }
    void visit(mult_expr* e) { r = true; }
    void visit(div_expr* e) { r = true; }
    void visit(rem_expr* e) { r = true; }
    void visit(neg_expr* e) { r = true; }
    void visit(Int_expr* e) {r = false;}
  };
  V vis;
  e->accept(vis);
  return vis.r;
}

//print functions for printing out the expressions
void print(Expr* e)
{
  struct V : Expr::Visitor {
    void print_enclosed(Expr* e) {
      if (needs_parens(e)) {
        std::cout << '(';
        print(e);
        std::cout << ')';
      }
      else {
        print(e);
      }
    }

    //print Boolean values
    void visit(Bool_expr* e) {
      if (e->val)
        std::cout << "true";
      else
        std::cout << "false";
    }

    //print Int values
    void visit(Int_expr* e){
        std::cout << e->val;
    }

    //print And expression
    void visit(And_expr* e) {
      print_enclosed(e->e1);
      std::cout << " & ";
      print_enclosed(e->e2);
    }

    //print Or expression
    void visit(Or_expr* e) {
      print_enclosed(e->e1);
      std::cout << " | ";
      print_enclosed(e->e2);
    }

    //Print not expression
    void visit(Not_expr* e) {
      std::cout << '!';
      print_enclosed(e->e1);
    }

    //print visit expression
    void visit(xor_expr* e) {
        print_enclosed(e->e1);
        std::cout << " ^ ";
        print_enclosed(e->e2);
    }

    //print ifthenelse expression
    //if you could give me a bit of advice on how to do this properly I would appreciate it

    /*void visit(ifthenelse_expr*e){
        std::cout << "if ";
        print_enclosed(e->e1);
        std::cout << " then";
        print_enclosed(e->e2);
        std::cout << " else";
        print_enclosed(e->e3);
    }*/

    //Print equality expression
    void visit(equal_expr* e){
        print_enclosed(e->e1);
        std::cout << " == ";
        print_enclosed(e->e2);
    }

    //Print Non-Equality expression
    void visit(notequal_expr* e){
        print_enclosed(e->e1);
        std::cout << " != ";
        print_enclosed(e->e2);
    }

    //Print Less than expression
    void visit(lessthan_expr* e){
        print_enclosed(e->e1);
        std::cout << " < ";
        print_enclosed(e->e2);
    }

    //Print greater than expression
    void visit(greaterthan_expr* e){
        print_enclosed(e->e1);
        std::cout << " > ";
        print_enclosed(e->e2);
    }

    //Print less than or equal to expression
    void visit(lessorequal_expr* e){
        print_enclosed(e->e1);
        std::cout << " <= ";
        print_enclosed(e->e2);
    }

    //Print greater than or equal to expression
    void visit(greaterorequal_expr* e){
        print_enclosed(e->e1);
        std::cout << " >= ";
        print_enclosed(e->e2);
    }

    //Print add operator
    void visit(add_expr* e){
        print_enclosed(e->e1);
        std::cout << " + ";
        print_enclosed(e->e2);
    }

    //Print subtract operator
    void visit(sub_expr* e){
        print_enclosed(e->e1);
        std::cout << " - ";
        print_enclosed(e->e2);
    }

    //Print multiply operator
    void visit(mult_expr* e){
        print_enclosed(e->e1);
        std::cout << " * ";
        print_enclosed(e->e2);
    }

    //Print division operator
    void visit(div_expr* e){
        print_enclosed(e->e1);
        std::cout << " / ";
        print_enclosed(e->e2);
    }

    //Print mod operator
    void visit(rem_expr* e){
        print_enclosed(e->e1);
        std::cout << " % ";
        print_enclosed(e->e2);
    }

    //Print negative number
    void visit(neg_expr* e){
        std::cout << " >= ";
        print_enclosed(e->e1);
    }

  };
  V vis;
  e->accept(vis);
}
