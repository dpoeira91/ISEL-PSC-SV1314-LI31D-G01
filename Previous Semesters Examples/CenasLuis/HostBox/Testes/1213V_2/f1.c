#define MAX 8
float val;
int ref = 21;
static int top = 1;

int main() {
	int end = MAX - 1;
	top = 5;
	return f((int)val, ref, top, end);
}
