//
// ISEL - LEIC - 2013
// Programação em Sistemas Computacionais
//
// (usa subconjunto mínimo de c++)
//

#include "expr.hpp"

void printLineTo(PExp exp, FILE * out) {
    exp->printTo(out);
    fprintf(out, " = %d\n", exp->evaluate());
}

void printAllExpressions(PExp exps[], size_t nexp, FILE * out) {
    for (size_t idx = 0; idx < nexp; ++idx) {
        printLineTo(exps[idx], out);
    }
}

int main() {
        
    PExp five     = EConstant(5);
    PExp mFive    = ENegation(five);
    PVar varX     = EVariable("x", 8);
    PExp xPmFive  = EAddition(varX, mFive);
    PExp mxPmFive = ENegation(xPmFive);

    PExp exps[5] = { five, mFive, varX, xPmFive, mxPmFive };

    printf("\n:: EXPRESSIONS (1) ::\n\n");
    printAllExpressions(exps, 5, stdout);

    varX->assign(mFive->evaluate());

    printf("\n:: EXPRESSIONS (2) ::\n\n");
    printAllExpressions(exps + 2, 3, stdout);

    varX->assign(7);

    printf("\n:: EXPRESSIONS (3) ::\n\n");
    printAllExpressions(exps + 2, 3, stdout);

    putchar('\n');
    
    for (int idx = 4; idx >= 0; --idx) {
        exps[idx]->free();
    }
    
    return 0;
}
