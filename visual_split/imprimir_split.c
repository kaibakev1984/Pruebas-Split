#include "../strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // isatty
#define ANSI_COLOR_LGH_RED	   "\x1b[1m\x1b[31m"
#define ANSI_COLOR_LGH_GREEN   "\x1b[1m\x1b[32m"
#define ANSI_COLOR_LGH_WHITE 	""
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_split(char *str, char **strv){
	size_t i = 0;
	printf("Cadena: \"%s\" ---> [", str);
	while(strv[i]){
		printf("\"%s\"", strv[i]);
		i++;
		if(strv[i]) printf(",");
	}
	printf("]\n\n");
}

int main(){
	printf("Inicio de SPLIT\n");

	char *str1 = "abc,,def";
	char *str2 = "abc,def,";
	char *str3 = ",abc,def";
	char *str4 = "";
	char *str5 = ",";
	char *str6 = ",,,,,,,,";
	char *str7 = "1,,,,5";

	char **strv1 = split("abc,,def", ',');
	char **strv2 = split("abc,def,", ',');
	char **strv3 = split(",abc,def", ',');
	char **strv4 = split("", ',');
	char **strv5 = split(",", ',');
	char **strv6 = split(",,,,,,,,", '\0');
	char **strv7 = split("1,,,,5", ',');

	print_split(str1, strv1);
	print_split(str2, strv2);
	print_split(str3, strv3);
	print_split(str4, strv4);
	print_split(str5, strv5);
	printf("OJO. La cadena acá es %s, pero el separador es un VACIO\n", str6);
	print_split(str6, strv6);
	print_split(str7, strv7);

	/* Libero el espacio reservado para los arreglos */
	free_strv(strv1);
	free_strv(strv2);
	free_strv(strv3);
	free_strv(strv4);
	free_strv(strv5);
	free_strv(strv6);
	free_strv(strv7);
	return 0;
}











