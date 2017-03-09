#ifndef AST_HPP
#define AST_HPP
#include <cassert>

// Our language defines two types
// Bool and Int
struct BoolType;
struct IntType;

// With support for the 6 standard logical expressions
struct BoolExpr;
struct AndExpr;
struct OrExpr;
struct NotExpr;
struct XorExpr;
struct CondExpr;

// And support for simple arithmetic expressions + equalities
struct IntExpr;
struct AddExpr;
struct SubExpr;
struct MulExpr;
struct DivExpr;
struct ModExpr;
struct NegExpr;
struct LesExpr;
struct GreExpr;
struct LoeExpr;
struct GoeExpr;

// Two general expressions are supported
struct EqExpr;
struct NeqExpr;

enum struct TYPE {
	IntType,
	BoolType,
};

// The base class for all other types
struct Type {
	struct Visitor;
	virtual ~Type() = default;
	virtual void accept(Visitor&) {}
};

// Initializing inheritance 
struct BoolType : Type { };
struct IntType : Type { };

// The base class for all expressions. 
// Note: accept function is virtual to allow the change of function definitions
struct Expr {
	struct Visitor;
	Type *ty = nullptr;
	virtual ~Expr() = default;
	virtual void accept(Visitor&) = 0;
};

// Visitor pattern for expressions
// Defines how to visit each expressions
struct Expr::Visitor {
	virtual void visit(BoolExpr*) = 0;
	virtual void visit(AndExpr*) = 0;
	virtual void visit(OrExpr*) = 0;
	virtual void visit(NotExpr*) = 0;
	virtual void visit(XorExpr*) = 0;
	virtual void visit(IntExpr*) = 0;
	virtual void visit(AddExpr*) = 0;
	virtual void visit(SubExpr*) = 0;
	virtual void visit(MulExpr*) = 0;
	virtual void visit(DivExpr*) = 0;
	virtual void visit(ModExpr*) = 0;
	virtual void visit(NegExpr*) = 0;
	virtual void visit(LesExpr*) = 0;
	virtual void visit(GreExpr*) = 0;
	virtual void visit(LoeExpr*) = 0;
	virtual void visit(GoeExpr*) = 0;
	virtual void visit(EqExpr*) = 0;
	virtual void visit(NeqExpr*) = 0;
	virtual void visit(CondExpr*) = 0;
};

// Define the Bool expressions
// Main difference is the constructor
struct BoolExpr : Expr {
	bool val;
	BoolExpr(bool b) : val(b) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

// Define the Int expressions
// Main difference is the constructor
struct IntExpr : Expr {
	int val;
	IntExpr(int i) : val(i) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

// Below defines each type of expression in our language

struct AndExpr : Expr {
	Expr* e1;
	Expr* e2;
	AndExpr(Expr* e1, Expr* e2)
		: e1(e1), e2(e2) { }
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct OrExpr : Expr {
	Expr* e1;
	Expr* e2;
	OrExpr(Expr* e1, Expr* e2)
		: e1(e1), e2(e2) { }
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct NotExpr : Expr {
	Expr* e1;
	NotExpr(Expr* e1)
		: e1(e1) { }
	void accept(Visitor& v) {
		return v.visit(this);
	}
};
struct XorExpr : Expr {
	Expr* e1;
	Expr* e2;
	XorExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct AddExpr : Expr {
	Expr* e1;
	Expr* e2;
	AddExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};
struct SubExpr : Expr {
	Expr* e1;
	Expr* e2;
	SubExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct MulExpr : Expr {
	Expr* e1;
	Expr* e2;
	MulExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct DivExpr : Expr {
	Expr* e1;
	Expr* e2;
	DivExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct ModExpr : Expr {
	Expr* e1;
	Expr* e2;
	ModExpr(Expr* e1, Expr* e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct NegExpr : Expr {
	Expr* e1;
	NegExpr(Expr* e1)
		:e1(e1) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct LesExpr : Expr {
	Expr* e1;
	Expr* e2;
	LesExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};
struct GreExpr : Expr {
	Expr* e1;
	Expr* e2;
	GreExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};
struct LoeExpr : Expr {
	Expr* e1;
	Expr* e2;
	LoeExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};
struct GoeExpr : Expr {
	Expr* e1;
	Expr* e2;
	GoeExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};

struct EqExpr : Expr {
	Expr* e1;
	Expr* e2;
	EqExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};

struct NeqExpr : Expr {
	Expr* e1;
	Expr* e2;
	NeqExpr(Expr*e1, Expr *e2)
		:e1(e1), e2(e2) {}
	void accept(Visitor& v){
		return v.visit(this);
	}
};
struct CondExpr : Expr {
	Expr* e1;
	Expr* e2;
	Expr* e3;
	CondExpr(Expr* e1, Expr* e2, Expr* e3)
		:e1(e1), e2(e2), e3(e3) {}
	void accept(Visitor& v) {
		return v.visit(this);
	}
};

struct Context {
	BoolType boolType;
	IntType intType;
};

#endif
