#include "ast.hpp"
#include "value.hpp"
#include <cassert>

// Actually evaluate the expression
// Note, this can happen recursively
// Standard format is as follow: 
// 1. Determine the kinda of the expression
// 2. Evaluate the expression
Value eval(Expr* e) {
	struct V: Expr::Visitor {
		Value r;
		void visit(NeqExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n != eval(e->e2).data.n;
		}
		void visit(CondExpr *e) {
			// do dynamic type checking here?
			r.kind = ValueKind::intVal;
			if(eval(e->e1).data.b) r.data.b = eval(e->e2).data.b; 
			else r.data.b = eval(e->e3).data.b;
		}
		void visit(NotExpr* e) {
			r.kind = ValueKind::boolVal;
			r.data.b = !eval(e->e1).data.b; 
		}
		void visit(XorExpr* e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.b ^ eval(e->e2).data.b;
		}
		void visit(AddExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = eval(e->e1).data.n + eval(e->e2).data.n;
		}
		void visit(SubExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = eval(e->e1).data.n - eval(e->e2).data.n;
		}
		void visit(BoolExpr* e) {
			r.kind = ValueKind::boolVal;
			r.data.b = e->val; 
		}
		void visit(IntExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = e->val;
		}
		void visit(AndExpr* e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.b & eval(e->e2).data.b; 
		}
		void visit(OrExpr* e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.b | eval(e->e2).data.b; 
		}
		void visit(LesExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n < eval(e->e2).data.n;
		}
		void visit(GreExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n > eval(e->e2).data.n;
		}
		void visit(LoeExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n <= eval(e->e2).data.n;
		}
		void visit(GoeExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n >= eval(e->e2).data.n;
		}
		void visit(MulExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = eval(e->e1).data.n * eval(e->e2).data.n;
		}
		void visit(DivExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = eval(e->e1).data.n / eval(e->e2).data.n;
		}
		void visit(ModExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = eval(e->e1).data.n % eval(e->e2).data.n;
		}
		void visit(NegExpr* e) {
			r.kind = ValueKind::intVal;
			r.data.n = 0 - eval(e->e1).data.n;
		}
		void visit(EqExpr *e) {
			r.kind = ValueKind::boolVal;
			r.data.b = eval(e->e1).data.n == eval(e->e2).data.n;
		}
	};
	V visitor;
	e->accept(visitor);
	return visitor.r;
}
