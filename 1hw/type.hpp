#include <iostream>
#include "ast.hpp"
#include "value.hpp"

//Function to check if an expression is valid
Type* check(Context& cxt, Expr* e) {
	struct V : Expr::Visitor {
		Context& cxt;
		Type* r;

		V(Context& c) : cxt(c) { }

		void visit(NeqExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType ||
					check(cxt, e->e1) == &cxt.boolType && check(cxt, e->e2) == &cxt.boolType);
			r = &cxt.boolType;
		}
		void visit(CondExpr *e) {
			// do stuff
			assert(check(cxt, e->e2) == check(cxt, e->e3));
			r = check(cxt, e->e2);
		}
		void visit(NotExpr* e) {
			assert(check(cxt, e->e1) == &cxt.boolType);
			r = &cxt.boolType;
		}
		void visit(XorExpr* e) {
			assert(check(cxt, e->e1) == &cxt.boolType && check(cxt, e->e2) == &cxt.boolType);
			r = &cxt.boolType;
		}
		void visit(AddExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(BoolExpr* e) {
			r = &cxt.boolType;
		}
		void visit(IntExpr* e) {
			r = &cxt.intType;
		}
		void visit(AndExpr* e) {
			assert(check(cxt, e->e1) == &cxt.boolType && check(cxt, e->e2) == &cxt.boolType);
			r = &cxt.boolType;
		}
		void visit(OrExpr* e) {
			assert(check(cxt, e->e1) == &cxt.boolType && check(cxt, e->e2) == &cxt.boolType);
			r = &cxt.boolType;
		}
		void visit(NegExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(LesExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.boolType;
		}
		void visit(GreExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.boolType;
		}
		void visit(LoeExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.boolType;
		}
		void visit(SubExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(MulExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(DivExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(ModExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.intType;
		}
		void visit(GoeExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType);
			r = &cxt.boolType;
		}
		void visit(EqExpr* e) {
			assert(check(cxt, e->e1) == &cxt.intType && check(cxt, e->e2) == &cxt.intType ||
					check(cxt, e->e1) == &cxt.boolType && check(cxt, e->e2) == &cxt.boolType);
			r = &cxt.boolType;
		}
	};
	V visitor(cxt);
	e->accept(visitor);
	return visitor.r;
}
