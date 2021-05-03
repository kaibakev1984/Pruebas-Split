#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testing.h"
#include "strutil.h"

void pruebas_substr(){
   printf("--------------------------------------------------\n");
   printf("PRUEBAS SUBSTR\n");
   printf("--------------------------------------------------\n");
   char *str_1 = "Hola mundo";
   char *str_2 = "Algoritmos";
   char *str_3 = "";
   char *str_4 = "Ejemplo";

   char *sub_str_1 = substr(str_1, 6);
   char *sub_str_2 = substr(str_2, 30);
   char *sub_str_3 = substr(str_3, 2);
   char *sub_str_4 = substr(str_4, 2);
   char *sub_str_5 = substr(str_4 + 4, 2);

   print_test("substr(\"Hola mundo\", 6) --> \"Hola m\"", !strcmp(sub_str_1, "Hola m"));
   print_test("subtstr(\"Algoritmos\", 30) --> \"Algoritmos\"", !strcmp(sub_str_2, "Algoritmos"));
   print_test("substr(\"\", 2) --> \"\"", !strcmp(sub_str_3, ""));
   print_test("substr(\"Ejemplo\", 2) --> \"Ej\"", !strcmp(sub_str_4, "Ej"));
   print_test("substr(\"Ejemplo\" + 4, 2) --> \"pl\"", !strcmp(sub_str_5, "pl"));

   free(sub_str_1);
   free(sub_str_2);
   free(sub_str_3);
   free(sub_str_4);
   free(sub_str_5);
}

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
  printf("--------------------------------------------------\n");
  printf("PRUEBAS SPLIT\n");
  printf("--------------------------------------------------\n");
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
	char **strv6 = split("1,,,,5", ',');
	char *strv6_copy[] = {"1", "\0", "\0", "\0", "5"};

	print_test("split(\"abc,,def\",\',\') --> [\"abc\",\"\", \"def\"]", strv_son_iguales(strv1, strv1_copy));
	print_test("split(\"abc,def,\", \',\') --> [\"abc\", \"def\", \"\"]", strv_son_iguales(strv2, strv2_copy));
	print_test("split(\",abc,def\", \',\') --> [\"\", \"abc\", \"def\"]", strv_son_iguales(strv3, strv3_copy));
	print_test("split(\"\", \',\') --> [\"\"]", strv_son_iguales(strv4, strv4_copy));
	print_test("split(\",\", \',\') --> [\"\", \"\"]", strv_son_iguales(strv5, strv5_copy));
	print_test("split(\"1,,,,5\", \',\') --> [\"1\", \"\", \"\", \"\", \"5\"]", strv_son_iguales(strv6, strv6_copy));

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

void pruebas_join() {
  printf("--------------------------------------------------\n");
  printf("PRUEBAS JOIN\n");
  printf("--------------------------------------------------\n");

  char *strv_1[] = {"\0", NULL};
  char *strv_2[] = {"abc", NULL};
  char *strv_3[] = {"\0", "\0", NULL};
  char *strv_4[] = {NULL};
  char *strv_5[] = {"abc", "def", NULL}; 
  char *strv_6[] = {"\0", "\0", "\0", "\0", "\0", NULL};

  char *str_1 = join(strv_1, ',');
  char *str_2 = join(strv_2, ',');
  char *str_3 = join(strv_3, ',');
  char *str_4 = join(strv_4, ',');
  char *str_5 = join(strv_5, '\0');
  char *str_6 = join(strv_6, ',');
  
  print_test("join([\"\"], ',') --> \"\"", !strcmp(str_1, "\0"));
  print_test("join([\"abc\"], ',') --> \"\"", !strcmp(str_2, "abc"));
  print_test("join([\"\", \"\"], ',') --> \",\"", !strcmp(str_3, ","));
  print_test("join([], ',') --> \"\"", !strcmp(str_4, "\0"));
  print_test("join([\"abc\", \"def\"], '\\0') --> \"abcdef\"", !strcmp(str_5, "abcdef"));
  print_test("join([\"\", \"\", \"\", \"\", \"\"]) --> \",,,,\"", !strcmp(str_6, ",,,,"));

  free(str_1);
  free(str_2);
  free(str_3);
  free(str_4);
  free(str_5);
  free(str_6);
}

void pruebas_strutil() {
  pruebas_substr();
  pruebas_split();
  pruebas_join();
}
