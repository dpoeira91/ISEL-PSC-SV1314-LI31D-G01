//
// ISEL - LEIC - 2013
// Programação em Sistemas Computacionais
//
// (usa subconjunto mínimo de c++)
//

#include "expr.hpp"

/////////////////////////////////////////////
//
// Outros tipos da hierarquia de Expression
//
/////////////////////////////////////////////

class Constant : public Value {
public:
    Constant(int value);
    void printTo(FILE * out);
};

class Negation : public Expression {
private:
    PExp expr;
public:
    Negation(PExp expr);
    int  evaluate();
    void printTo(FILE * out);
};

class Addition : public BinaryOperation {
protected:
    int  operation(int leftValue, int rightValue);
    void printOperatorTo(FILE * out);
public:
    Addition(PExp left, PExp right);
};


///////////////////////////////////////////////////////
//
// Funções-fábrica para tipos concretos de Expression
//
///////////////////////////////////////////////////////

PExp EConstant(int value)             { return new Constant(value);       }
PExp ENegation(PExp expr)             { return new Negation(expr);        }
PExp EAddition(PExp left, PExp right) { return new Addition(left, right); }


///////////////////////////////////////////////////////////
//
// Métodos concretos de tipos da hierarquia de Expression
//
///////////////////////////////////////////////////////////

// Constant

Constant::Constant(int value) : Value(value) { }

void Constant::printTo(FILE * out) { fprintf(out, "%d", value); }

// Negation

Negation::Negation(PExp expr) { this->expr = expr; }

int Negation::evaluate() { return -expr->evaluate(); }

void Negation::printTo(FILE * out) {
    fputs("(-", out); expr->printTo(out);
    fputc(')',  out);
}

// Addition

int Addition::operation(int leftValue, int rightValue) {
    return leftValue + rightValue;
}

void Addition::printOperatorTo(FILE * out) { fputc('+', out); }

Addition::Addition(PExp left, PExp right) : BinaryOperation(left, right) { }
