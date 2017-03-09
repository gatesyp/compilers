#include <iostream>

#include "ast.hpp"
#include "eval.hpp"
#include "print.hpp"
#include "type.hpp"

int main() {
    Context ctx;
    {
        Expr * condExpr = new CondExpr(new BoolExpr(false) , new IntExpr(8), new IntExpr(2));
        check(ctx, condExpr);
        print(condExpr);
        std::cout << " == " << eval(condExpr).data.b << '\n';

        Expr * mulExpr = new MulExpr(new IntExpr(1), new IntExpr(8));
        check(ctx, mulExpr);
        print(mulExpr);
        std::cout << " == " << eval(mulExpr).data.b << '\n';

        Expr * neqExpr = new NeqExpr(new BoolExpr(3), new BoolExpr(3));
        Expr * e = new AndExpr(new NotExpr(new BoolExpr(false)) , new BoolExpr(false));
        check(ctx, e);
        print(e);
        std::cout << " == " << eval(e).data.b << '\n';

        Expr * modepr = new ModExpr(new IntExpr(10), new IntExpr(4));
        check(ctx, modepr);
        print(modepr);
        std::cout << " == " << eval(modepr).data.n << '\n';

        check(ctx, neqExpr);
        print(neqExpr);
        std::cout << " == " << eval(neqExpr).data.b << '\n';

    }

}
