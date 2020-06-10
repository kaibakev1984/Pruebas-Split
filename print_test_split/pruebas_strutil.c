#include "../testing.h"
#include "../strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*	Sirve para comparar 2 strv, comparando posición a posición
	con un strcmp	*/
bool strv_son_iguales(char **strv1, char **strv2){
	size_t i = 0;
	bool ok = true;
	while(strv1[i]){
		ok &= !strcmp(strv1[i], strv2[i]);
		i++;
	} 
	return ok;
}

void pruebas_split(){	
	printf("INICIO DE PRUEBAS SPLIT\n");

	/*	Defino mis casos de prueba, y los resultados esperados	*/
	char **strv1 = split("abc,,def", ',');
	char *strv1_copy[] = {"abc","\0", "def"};
	char **strv2 = split("abc,def,", ',');
	char *strv2_copy[] = {"abc", "def", "\0"};
	char **strv3 = split(",abc,def", ',');
	char *strv3_copy[] = {"\0", "abc", "def"};
	char **strv4 = split("", ',');
	char *strv4_copy[] = {"\0"};
	char **strv5 = split(",", ',');
	char *strv5_copy[] = {"\0", "\0"};
//	char **strv6 = split(",,,,,,,,", '\0');
//	char *strv6_copy[] = {
	char **strv6 = split("1,,,,5", ',');
	char *strv6_copy[] = {"1", "\0", "\0", "\0", "5"};

	print_test("Split de \"abc,,def\" con separador \',\' es: {\"abc\",\"\", \"def\"}", strv_son_iguales(strv1, strv1_copy));
	print_test("Split de \"abc,def,\" con separador \',\' es: {\"abc\", \"def\", \"\"}", strv_son_iguales(strv2, strv2_copy));
	print_test("Split de \",abc,def\" con separador \',\'es: {\"\", \"abc\", \"def\"}", strv_son_iguales(strv3, strv3_copy));
	print_test("Split de \"\" con separador \',\' es: {\"\"}", strv_son_iguales(strv4, strv4_copy));
	print_test("Split de \",\" con separador \',\'es: {\"\", \"\"}", strv_son_iguales(strv5, strv5_copy));
	print_test("Split de \"1,,,,5\" con separador \',\' es: {\"1\", \"\", \"\", \"\", \"5\"}", strv_son_iguales(strv6, strv6_copy));

	/* Libero el espacio reservado para los strv */
	free_strv(strv1);
	free_strv(strv2);
	free_strv(strv3);
	free_strv(strv4);
	free_strv(strv5);
	free_strv(strv6);

}

char *join_crear(char *str, char sep, char sep_new){
	char **strv = split(str, sep);
	char *str_new = join(strv, sep_new);
	free_strv(strv);
	return str_new;
}

/*	
	INICIO DE PRUEBAS JOIN	*/

void pruebas_join(){
	

	/* Declaro las variables a utilizar */
	char *str1 = join_crear("", ',', '.');
	char *str2 = join_crear(",", ',', '.');
	char *str3 = join_crear("abc", '\0', ',');
	char *str4 = join_crear("", '\0', ',');
	char *str5 = join_crear(",,,,,,", '\0', ',');

	/* Pruebo que join funciona correctamente */
	char **str_null = {NULL};
	char *str6 = join(str_null, ',');

	/* Libero las cadenas */
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
}

char *str_crear_10000(char sep, size_t n){
	char *str = calloc(n + 1, sizeof(char));
	if(!str) return NULL;
	for(size_t i = 0; i < n; i++){
		str[i] = sep;
	}
	return str;
}

void pruebas_join_10000(){
	size_t n = 10000;
	char *str = str_crear_10000(',', n);
	char **strv = split(str, ',');
	char *str_new = join(strv, '.');
	free_strv(strv);
	free(str);
	free(str_new);
}

// Acá se van a ejecutar las pruebas
int main(){
	pruebas_split();
	return 0;
}
