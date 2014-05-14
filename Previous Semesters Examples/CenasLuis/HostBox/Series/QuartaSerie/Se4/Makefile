#
# ISEL - LEIC - 2013
# Programação em Sistemas Computacionais
#

#all: use-expr-c++
all: use-expr-c use-expr-c++

use-expr-c++: use-expr.o expr.o more-expr-c++.o
	g++ -o use-expr-c++ use-expr.o expr.o more-expr-c++.o

use-expr-c: use-expr.o expr.o more-expr-c.o
	g++ -o use-expr-c use-expr.o expr.o more-expr-c.o

use-expr.o: use-expr.cpp expr.hpp
	g++ -Wall -pedantic -g -c use-expr.cpp

expr.o: expr.cpp expr.hpp
	g++ -Wall -pedantic -g -c expr.cpp

more-expr-c++.o: more-expr.cpp expr.hpp
	g++ -Wall -pedantic -g -c -o more-expr-c++.o more-expr.cpp

more-expr-c.o: more-expr.c
	gcc -Wall -pedantic -std=c99 -g -c -o more-expr-c.o more-expr.c

clean:
	rm -rf use-expr-c++ use-expr-c *.o
