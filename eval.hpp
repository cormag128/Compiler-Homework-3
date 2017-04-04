
#include "ast.hpp"

bool

//place all of the functionality for expressions
eval(Expr* e)
{
  struct V : Expr::Visitor {
    bool r;
    void visit(Bool_expr* e) { r = e->val; }
    void visit(And_expr* e) { r = eval(e->e1) & eval(e->e2); }
    void visit(Or_expr* e) { r = eval(e->e1) | eval(e->e2); }
    void visit(Not_expr* e) { r = !eval(e->e1); }
    void visit(xor_expr* e) { r = eval(e->e1) ^ eval(e->e2);}
   // void visit(ifthenelse_expr* e) {}
    void visit(equal_expr* e) { r = eval(e->e1) == eval(e->e2);}
    void visit(notequal_expr* e) { r = eval(e->e1) != eval(e->e2);}
    void visit(lessthan_expr* e) { r = eval(e->e1) < eval(e->e2);}
    void visit(greaterthan_expr* e ) { r = eval(e->e1) > eval(e->e2);}
    void visit(lessorequal_expr* e ) { r = eval(e->e1) <= eval(e->e2);}
    void visit(greaterorequal_expr* e) {r = eval(e->e1) >= eval(e->e2);}
    void visit(add_expr* e) {r = eval(e->e1) + eval(e->e2);}
    void visit(sub_expr* e) {r = eval(e->e1) - eval(e->e2);}
    void visit(mult_expr* e) {r = eval(e->e1) * eval(e->e2);}
    void visit(div_expr* e) {r = eval(e->e1) / eval(e->e2);}
    void visit(rem_expr* e) {r = eval(e->e1) % eval(e->e2);}
    void visit(neg_expr* e) {r = 0 - eval(e->e1);}
  };
  V vis;
  e->accept(vis);
  return vis.r;
}
