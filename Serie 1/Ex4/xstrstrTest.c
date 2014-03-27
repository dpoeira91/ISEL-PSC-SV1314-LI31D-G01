#include <stdio.h>
//Methods
char *xstrstr(const char * haystack, const char * needle);
char *test_xstrstr(char * str, char * key);
int confirm_result(char *result,char *key);

int main(){
	char *message , *key ,* result;
	message = "A bbicicleta azul";
	key = "bicicleta";
	int verify = 0;
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	message = "aa bb cccca hhh";
	key = "cca";
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	message = "da Caparica";
	key = "Costa";
	result = test_xstrstr((char *)message, (char *)key);
	if (result != NULL) return -1;
	message = "Costaa da Caparica";
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	message = "CostaCosta da Caparica";
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	return 0;
}

char * test_xstrstr(char * str,char * key){
	char * result;
	printf("String : %s ; Key : %s\n", str, key);
	result = xstrstr(str, key);
	if (result!= NULL)
		printf("Result : %s \n", result);
	else
		printf("Result is NULL\n");
	return result;
}

int confirm_result(char *result, char *key){
	int i;
	for (i = 0; key[i] != '\0'; i++){
		if (key[i] != result[i])
			return -1;
	}
	return 0;
}