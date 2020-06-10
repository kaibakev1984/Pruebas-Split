#include <stdio.h>
#include <stdlib.h>
#include "../testing.h"
#include "../strutil.h"
#include <string.h>
void pruebas_substr(){
	char *str1 = "Hola mundo";
	char *str2 = "Algoritmos";
	char *str3 = "";
	
	char *substr1 = substr(str1, 6);
	char *substr2 = substr(str2, 30);
	char *substr3 = substr(str3, 2);
	
	print_test("Pasa primer prueba", !strcmp(substr1, "Hola m"));
	print_test("Pasa segunda prueba", !strcmp(substr2, "Algoritmos"));
	print_test("Pasa tercer prueba", !strcmp(substr3, ""));
	//print_test("Substr de \"Hola mundo\" con n = 6 es \"Hola m\"", !strcmp(substr1, "Hola m"));
	//print_test("Substr de \"Algoritmos\" con n = 30 es \"Algoritmos\"", !strcmp(substr2, "Algoritmos"));
	//print_test("Substr de \"\" con n = 2 es \"\"", !strcmp(substr3, "");
	
	// Libero la memoria pedida para el substr
	free(substr1);
	free(substr2);
	free(substr3);
	
}

int main(){
	pruebas_substr();	

	return 0;
}
