#include "../strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // isatty
#define ANSI_COLOR_LGH_RED	   "\x1b[1m\x1b[31m"
#define ANSI_COLOR_LGH_GREEN   "\x1b[1m\x1b[32m"
#define ANSI_COLOR_LGH_WHITE 	""
#define ANSI_COLOR_RESET   "\x1b[0m"

char *join_crear(char *str, char separador, char nuevo_separador){
	char **strv = split(str, separador);
	char *nuevo_str = join(strv, nuevo_separador);
	free_strv(strv);
	return nuevo_str;
}

void mostrar_str_con_nuevo_separador(char *str, char sep, char nuevo_sep){
	char *str_nuevo = join_crear(str, sep, nuevo_sep);
	printf("\"%s\" ---> \"%s\"\n\n", str, str_nuevo);
	free(str_nuevo);
}

int main(){
	printf("Resultado de hacer JOIN con \"*\"\n");

	mostrar_str_con_nuevo_separador("", ',', '.');
	mostrar_str_con_nuevo_separador(",", ',', '.');
	mostrar_str_con_nuevo_separador("abc", '\0', ',');
	mostrar_str_con_nuevo_separador("", '\0', ',');
	mostrar_str_con_nuevo_separador(",,,,,,", '\0', ',');
//	char **str_null = {NULL};
//	char *str6 = join(str_null, ',');	
	return 0;
}

























