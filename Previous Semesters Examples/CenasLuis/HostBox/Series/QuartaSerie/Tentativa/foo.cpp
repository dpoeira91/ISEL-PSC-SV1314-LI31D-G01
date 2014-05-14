#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

#include "foo.h"

Foo::Foo(int32_t a){
   k = a << 1;
}

Foo::~Foo(){
   /* don't really need to do anything here */
   /* k = 0 only for example purposes       */
   k = 0;
}

std::string Foo::toString(){
   std::ostringstream os;
   os << "Foo is currently: " << this->k << std::endl;
   return os.str();
}

void* getFoo(int32_t a){
   Foo *out = new Foo(a);
   return ((void*)out);
}

void destroyFoo(void* foo){
   delete (((Foo*)foo));
}


void printString(void *foo){
   std::string s = ((Foo*)foo)->toString();
   std::cout << s;
}
