//
// ISEL - LEIC - 2013
// Programação em Sistemas Computacionais
//
// (usa subconjunto mínimo de c++)
//

#include "expr.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////
//
// Funções-fábrica para tipos concretos de Expression
//
///////////////////////////////////////////////////////

PVar EVariable(const char * name, int initialValue) {
    return new Variable(name, initialValue);
}


///////////////////////////////////////////////////////////
//
// Métodos concretos de tipos da hierarquia de Expression
//
///////////////////////////////////////////////////////////

// Expression

// Por omissão, usa o operador C++ de libertação de memória. Deve ser
// redefinido em tipos cujos objectos não sejam alocados com new.
void Expression::free() { delete this; }

// Value

Value::Value(int value) { this->value = value; }

int Value::evaluate() { return value; }

// Variable

Variable::Variable(const char * name, int initialValue)
  : Value(initialValue) {
    strncpy(this->name, name, MAX_VAR_NAME_LEN);
    this->name[MAX_VAR_NAME_LEN] = '\0';
}

void Variable::assign(int newValue) { value = newValue; }

void Variable::printTo(FILE * out) { fprintf(out, "%s", name); }

// BinaryOperation

BinaryOperation::BinaryOperation(PExp left, PExp right) {
    this->left = left;
    this->right = right;
}

int BinaryOperation::evaluate() {
    return operation(left->evaluate(), right->evaluate());
}

void BinaryOperation::printTo(FILE * out) {
    fputc('(', out); left->printTo(out);
    fputc(' ', out); printOperatorTo(out);
    fputc(' ', out); right->printTo(out);
    fputc(')', out);
}
