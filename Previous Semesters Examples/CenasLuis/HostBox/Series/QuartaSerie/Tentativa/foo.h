#include <stdint.h>

#ifdef __cplusplus

class Foo {
	public:
		Foo(int32_t a = 4);
		~Foo();
	std::string toString();
	private:
		int32_t k;

};

#endif

#ifdef __cplusplus
extern "C" {
#endif
void * getFoo(int32_t a);
void destroyFoo(void* foo);
void printString(void * foo);
#ifdef __cplusplus
}
#endif
