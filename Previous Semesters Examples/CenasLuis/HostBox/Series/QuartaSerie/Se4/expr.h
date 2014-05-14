#ifndef EXPR_H
#define EXPR_H

#include <stdio.h>

//Expressions virtual table
typedef struct ExpressionInfo {
	int  (*evaluate) (void * );
	void (*printTo)  (void * , FILE *);
	void (*free)	 (void * );
} ExpressionInfo;

//Expression
typedef struct Expression {
	const ExpressionInfo * Evtbl;
} Expression;

//Expression base methods
void Expression_free     (Expression * this );

//Value
typedef struct Value {
	Expression ValueSuper;
	int value;
} Value;

//Value methods
void Value_ctor     (Value * this , int value);
int  Value_evaluate (Value * this );

typedef struct BinaryOperationInfo{
	int  (*operation)       ( int leftValue, int rightValue );
	void (*printOperatorTo) ( FILE * out );
} BinaryOperationInfo;

//BinaryOperation
typedef struct BinaryOperation{
	Expression BinarySuper;
	const BinaryOperationInfo * info;
	Expression * left;
	Expression * right;
}BinaryOperation;

//BinaryOperation methods
int  BinaryOperation_evaluate        (BinaryOperation * this );
void BinaryOperation_printTo         (BinaryOperation * this , FILE * out);
void BinaryOperation_ctor            (BinaryOperation * this , Expression * left , Expression * right);

//Variable
typedef struct Variable{
	Value VariableSuper;
	char * name;
} Variable;

//Variable methods
void Variable_ctor    ( char * name , int value );
void Variable_printTo ( FILE * out );
void Variable_assign  ( int newValue );

typedef Expression * PExp;
typedef Variable   * PVar;

#ifdef __cplusplus
extern "C" {
#endif
 
PExp EConstant(int value);
PVar EVariable(const char * name, int initialValue);
PExp ENegation(PExp value);
PExp EAddition(PExp left, PExp right);
 
#ifdef __cplusplus
}
#endif

#endif
