prog: prog.o Point.o Point3D.o LabeledPoint.o
	g++ -o prog prog.o Point.o Point3D.o LabeledPoint.o

prog.o: prog.cpp
	g++ -c -Wall -pedantic -g prog.cpp

Point.o: Point++.cpp
	g++ -c -Wall -pedantic -g -o Point.o Point++.cpp

Point3D.o: Point3D.cpp
	g++ -c -Wall -pedantic -g Point3D.cpp

LabeledPoint.o: LabeledPoint.c
	gcc -c -Wall -pedantic -g LabeledPoint.c
