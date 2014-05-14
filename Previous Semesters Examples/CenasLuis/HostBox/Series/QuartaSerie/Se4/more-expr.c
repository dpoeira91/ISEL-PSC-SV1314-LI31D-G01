// ISEL - LEIC - 2013
// Programação em Sistemas Computacionais

#include "expr.h"
#include <stdlib.h>

typedef struct Constant{
	Value ConstantSuper;
} Constant;

typedef struct Negation{
	Expression NegationSuper;
	PExp expr;
} Negation;

typedef struct Addition{
	BinaryOperation AddSuper;
} Addition;

void Expression_free (PExp this){  free((void *) this); } 

void Constant_printTo(Value * this , FILE * out) { fprintf(out, "%d", this->value); }

int  Negation_evaluate(Negation * this ) { return  - this->expr->Evtbl->evaluate(this->expr); }

void Negation_printTo(Negation * this , FILE * out) {
    fputs("(-", out);
    this -> expr -> Evtbl -> printTo( this->expr , out);
    fputc(')',  out);
}

int  Addition_operation(int leftValue, int rightValue) { return leftValue + rightValue; }

void Addition_printOperatorTo(FILE * out) { fputc('+', out); }


int  Value_evaluate( Value * this ) { return this->value; }

int  BinaryOperation_evaluate(BinaryOperation * this ) { 
	return this->info->operation ( (this->left->Evtbl)->evaluate(this->left), (this->right->Evtbl)->evaluate(this->right));
}

void BinaryOperation_printTo(BinaryOperation * this , FILE * out) {
    fputc('(', out); (this->left->Evtbl)->printTo(( (this->left)) , out);
    fputc(' ', out); this->info->printOperatorTo(out);
    fputc(' ', out); (this->right->Evtbl)->printTo(( (this->right)) , out);
    fputc(')', out);
}


static const ExpressionInfo Negation_vtbl = {
	(int  (*)(void *))          Negation_evaluate,
	(void (*)(void * , FILE *)) Negation_printTo,
	(void (*)(void *))          Expression_free,
};

static const BinaryOperationInfo Addition_vtbl = {
	(int  (*)(int leftValue, int rightValue)) Addition_operation,
	(void (*)(FILE *))                        Addition_printOperatorTo,
};

static const ExpressionInfo Constant_vtbl = {
	(int  (*)(void *))          Value_evaluate,
	(void (*)(void * , FILE *)) Constant_printTo,
	(void (*)(void *))          Expression_free,
};

static const ExpressionInfo BinaryOperation_vtbl = {
	(int  (*)(void *))          BinaryOperation_evaluate,
	(void (*)(void * , FILE *)) BinaryOperation_printTo,
	(void (*)(void *))          Expression_free,
};

void BinaryOperation_ctor (BinaryOperation * this , Expression * left , Expression * right ){
	((Expression *)(this)) -> Evtbl = &BinaryOperation_vtbl;
	this -> left = left;
	this -> right = right;
}

void Value_ctor ( Value * this , int value ){ this -> value = value; }

void Constant_ctor ( Constant * this , int value ) {
	Value_ctor( &(this -> ConstantSuper) , value );
	((Expression *)this) -> Evtbl = &Constant_vtbl;
}

void Addition_ctor (Addition * this , PExp left, PExp right ){
	BinaryOperation_ctor( &(this->AddSuper) , left, right );
	((BinaryOperation *) this) -> info = &Addition_vtbl;
}

void Negation_ctor (Negation * this , PExp expr ){
	((Expression *) this) -> Evtbl = &Negation_vtbl;
	this -> expr = expr;
}

PExp EConstant(int value){
	Constant * c1 = (Constant *)malloc(sizeof (Constant));
	Constant_ctor( c1, value );
	return &(c1 -> ConstantSuper . ValueSuper );
}

PExp ENegation(PExp expr){ 
	Negation * n1 = (Negation *)malloc(sizeof (Negation));
	Negation_ctor( n1, expr );
	return &(n1 -> NegationSuper) ;
}

PExp EAddition(PExp left, PExp right) {
	Addition * a1 = (Addition *)malloc(sizeof (Addition));
	Addition_ctor( a1, left , right );
	return &(a1 -> AddSuper . BinarySuper) ;
}
