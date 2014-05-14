//
// ISEL - LEIC - 2013
// Programação em Sistemas Computacionais
//
// (usa subconjunto mínimo de c++)
//

#ifndef EXPR_HPP
#define EXPR_HPP

#include <stdio.h>

// Não existe a palavra-chave abstract em C++.
// Métodos abstractos são assinalados com = 0.
// (O carácter = faz parte da substituição.)
#define abstract = 0

// Classe base da hierarquia. Contém interface pública comum.
class Expression {
public:
    virtual int  evaluate()          abstract;  // avalia a expressão, produzindo o valor resultante
    virtual void printTo(FILE * out) abstract;  // adiciona a out a representação textual da expressão
    virtual void free();                        // liberta a memória ocupada pelo objecto
};

// Outros tipos, ainda abstractos, da hierarquia de Expression

class Value : public Expression {
protected:
    int value;
    Value(int value);
public:
    int evaluate();
};

class BinaryOperation : public Expression {
private:
    Expression * left;
    Expression * right;
protected:
    virtual int  operation(int leftValue, int rightValue) abstract;
    virtual void printOperatorTo(FILE * file)             abstract;
    BinaryOperation(Expression * left, Expression * right);
public:
    int  evaluate();
    void printTo(FILE * out);
};

// A classe Variable acrescenta um método à interface definida por
// Expression, sendo necessário disponibilizar a sua definição.

#define MAX_VAR_NAME_LEN 7

class Variable : public Value {
private:
    char name[MAX_VAR_NAME_LEN + 1];
public:
    Variable(const char * name, int initialValue);
    void assign(int newValue);
    void printTo(FILE * out);
};

// Nomes alternativos, para designar Expression * e Variable *
typedef Expression * PExp;
typedef Variable   * PVar;

// Funções-fábrica para os tipos concretos da hierarquia Expression
// [extern "C"] para que estas funções sigam as regras de ligação do C
// (veja os símbolos gerados com e sem [extern "C"])
extern "C" PExp EConstant(int value);
extern "C" PVar EVariable(const char * name, int initialValue);
extern "C" PExp ENegation(PExp value);
extern "C" PExp EAddition(PExp left, PExp right);

#endif
