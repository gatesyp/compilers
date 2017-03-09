#include "ast.hpp"
#include <iostream>

// Simple function to check if a particular expression needs parenthesis
bool needs_parens(Expr* e) {
	struct V : Expr::Visitor {
		bool r;
		void visit(NeqExpr*e) {
			r = true;
		}
		void visit(CondExpr*e) {
			r = true;
		}
		void visit(XorExpr*e) {
			r = true; 
		}
		void visit(IntExpr* e) {
			r = false;
		}
		void visit(AddExpr*e) {
			r = true;
		}   
		void visit(SubExpr*e) {
			r = true;
		}
		void visit(BoolExpr*e) {
			r = false; 
		}
		void visit(AndExpr*e) {
			r = true; 
		}
		void visit(OrExpr*e) {
			r = true; 
		}
		void visit(NotExpr*e) {
			r = true; 
		}
		void visit(LesExpr*e) {
			r = true;
		}
		void visit(GreExpr*e) {
			r = true;
		}
		void visit(LoeExpr*e) {
			r = true;
		}
		void visit(GoeExpr*e) {
			r = true;
		}
		void visit(MulExpr*e) {
			r = true;
		}
		void visit(DivExpr*e) {
			r = true;
		}
		void visit(ModExpr*e) {
			r = true;
		}
		void visit(NegExpr*e) {
			r = true;
		}
		void visit(EqExpr*e) {
			r = true;
		}
	};

	V visitor;
	e->accept(visitor);
	return visitor.r;
}

// More simple functions which pretty prints the expressions
void print(Expr* e) {
	struct V: Expr::Visitor {
		void print_enclosed(Expr* e) {
			if(needs_parens(e)){ std::cout << '('; print(e); std::cout << ')'; }
			else print(e);
		}
		void visit(NeqExpr* e) {
			print_enclosed(e->e1);
			std::cout << "!=";
			print_enclosed(e->e2);
		}
		void visit(CondExpr* e) {
			print_enclosed(e->e1);
			std::cout << " ? ";
			print_enclosed(e->e2);
			std::cout << " : ";
			print_enclosed(e->e3);
		}
		void visit(NotExpr* e) {
			std::cout << '!';
			print_enclosed(e->e1);
		}
		void visit(XorExpr* e) {
			print_enclosed(e->e1);
			std::cout << '^';
			print_enclosed(e->e2);
		}
		void visit(AddExpr* e) {
			print_enclosed(e->e1);
			std::cout << '+';
			print_enclosed(e->e2);
		}
		void visit(SubExpr* e) {
			print_enclosed(e->e1);
			std::cout << '-';
			print_enclosed(e->e2);
		}
		void visit(BoolExpr* e) {
			if(e->val) std::cout << "true";
			else std::cout << "false";
		}
		void visit(IntExpr* e) {
			std::cout << e->val;
		}
		void visit(AndExpr* e) {
			print_enclosed(e->e1);
			std::cout << " & ";
			print_enclosed(e->e2);
		}
		void visit(NegExpr*e ) {
			std::cout << '-';
			print_enclosed(e->e1);
		}
		void visit(LesExpr* e) {
			print_enclosed(e->e1);
			std::cout << '<';
			print_enclosed(e->e2);
		}
		void visit(GreExpr* e) {
			print_enclosed(e->e1);
			std::cout << '>';
			print_enclosed(e->e2);
		}
		void visit(LoeExpr* e) {
			print_enclosed(e->e1);
			std::cout << "<=";
			print_enclosed(e->e2);
		}
		void visit(OrExpr* e) {
			print_enclosed(e->e1);
			std::cout << " | ";
			print_enclosed(e->e2);
		}
		void visit(MulExpr* e) {
			print_enclosed(e->e1);
			std::cout << '*';
			print_enclosed(e->e2);
		}
		void visit(DivExpr* e) {
			print_enclosed(e->e1);
			std::cout << '/';
			print_enclosed(e->e2);
		}
		void visit(ModExpr* e) {
			print_enclosed(e->e1);
			std::cout << '%';
			print_enclosed(e->e2);
		}
		void visit(GoeExpr* e) {
			print_enclosed(e->e1);
			std::cout << ">=";
			print_enclosed(e->e2);
		}
		void visit(EqExpr* e) {
			print_enclosed(e->e1);
			std::cout << "==";
			print_enclosed(e->e2);
		}
	};
	V visitor;
	// start recursive call
	e->accept(visitor); 
}
