#include <stdio.h>
//Vars
const char * str1 = "A bbicicleta azul",
*key1 = "bicicleta",
*str2 = "aa bb cccca hhh",
*key2 = "cca",
*str3 = "da Caparica",
*key3 = "Costa",
*str4 = "Costaa da Caparica";
//Methods
char *xstrstr(const char * haystack, const char * needle);
char *test_xstrstr(char * str, char * key);
int confirm_result(char *result,char *key);

int main(){
	char *message , *key ,* result;
	message = (char *)str1;
	key = (char *)key1;
	int verify = 0;
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	message = (char *)str2;
	key = (char *)key2;
	result = test_xstrstr((char *)message, (char *)key);
	verify = confirm_result(result, key);
	if (verify == -1)
		return -1;
	message = (char *)str3;
	key = (char *)key3;
	result = test_xstrstr((char *)message, (char *)key);
	if (result != NULL) return -1;
	message = (char *)str4;
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