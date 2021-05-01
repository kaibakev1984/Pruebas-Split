## Manejo de cadenas
{: #strutil}

Se pide implementar las funciones de manejo que cadenas que se describen a continuación. Adjunto en el [sitio de descargas]({{site.skel}}) se puede encontrar un archivo _strutil.h_ con todos sus prototipos.

Para la implementación de estas funciones no se permite el usod uso de TDAs. Sí se permite, no obstante, el uso de las funciones de la biblioteca estándar de C [string.h] (excepto `strtok`). Se recomiendan, en particular:

 - `strlen`
 - `strcpy`/`strncpy`
  - `strdup`/`strndup`
  - `snprintf`

[string.h]: http://pubs.opengroup.org/onlinepubs/7908799/xsh/string.h.html

Se dsescriben a continuación las cuatro funciones a implementar.


### substr()

La función `substr()` permite obtener un prefijo de longitud $$k$$ de una cadena dada.

Por ejemplo, la llamada `substr("Hola mundo", 6)` devolvería la cadena `"Hola m"`. El resultado debe ser una nueva cadena de memoria dinámica con dichos caracteres (y, por supuesto, el carácter de fin de cadena).
Ejemplos de uso:

``` cpp
substr("Hola mundo", 6)         → "Hola m"
substr("Algoritmos", 30)        → "Algoritmos"
substr("", 2)                   → ""

const char* ejemplo = "Ejemplo";
substr(ejemplo, 2)              → "Ej"
substr(ejemplo + 4, 2)          → "pl"
```

Complejidad algorítmica: se espera que la función tenga complejidad $$\mathcal{O}(k)$$.


### split()

La función `split()` divide una cadena en subcadenas, con una división por cada ocurrencia de un caracter de separación determinado. Por ejemplo, separando por comas:

``` cpp
split("abc,def,ghi", ',')  →  ["abc", "def", "ghi"]
```

En C, devolveremos el resultado como un arreglo dinámico de cadenas dinámicas terminado en `NULL`. Esto es:

``` cpp
// Ejemplo de arreglo dinámico de cadenas
char **strv = malloc(sizeof(char*) * 4);
strv[0] = strdup("abc");
strv[1] = strdup("def");
strv[2] = strdup("ghi");
strv[3] = NULL;
```

Considerar los siguientes casos borde:

``` cpp
split("abc,,def", ',')  →  ["abc", "", "def"]
split("abc,def,", ',')  →  ["abc", "def", ""]
split(",abc,def", ',')  →  ["", "abc", "def"]
split("abc", '\0')      →  ["abc"]

split("", ',')  →  [""]
split(",", ',') →  ["", ""]
```

Complejidad algorítmica: se espera que la función tenga complejidad $$\mathcal{O}(n)$$, siendo $$n$$ la longitud de la cadena inicial.


### join()

La función `join()` es la inversa de `split()`. Concatena un arreglo de cadenas terminado en NULL mediante un caracter de separación:

``` cpp
// Ejemplo de uso de join
char **strv = split("abc,def,ghi", ',');
char *resultado = join(strv, ';');  // "abc;def;ghi"

char **palabras = split("Hola mundo", ' ');
char *otro_resultado = join(palabras, ',');  // "Hola,mundo"
```

Casos borde:
``` cpp
join([""], ',')             →  ""
join(["abc"], ',')          →  "abc"
join(["", ""], ',')         →  ","
join([], ',')               →  "" // Join de arreglo vacío, {NULL} en C.
join(["abc", "def"], '\0')  →  "abcdef"
```

Complejidad algorítmica: se espera que la función tenga complejidad $$\mathcal{O}(n)$$, siendo $$n$$ la longitud de la cadena resultante.

Las pruebas del corrector automático proveen una indicación del comportamiento de `join()` (si bien **todas las funciones deben correr en tiempo lineal**, `join()` provee una dificultad de implementación mayor a `split()` o `substr()`).

Este sería un test con comportamiento lineal:

    [ RUN      ] test_join.test_complejidad_10000
    [       OK ] test_join.test_complejidad_10000 (7 ms)
    [ RUN      ] test_join.test_complejidad_20000
    [       OK ] test_join.test_complejidad_20000 (14 ms)
    [ RUN      ] test_join.test_complejidad_30000
    [       OK ] test_join.test_complejidad_30000 (17 ms)
    [ RUN      ] test_join.test_complejidad_40000
    [       OK ] test_join.test_complejidad_40000 (27 ms)
    [ RUN      ] test_join.test_complejidad_50000
    [       OK ] test_join.test_complejidad_50000 (33 ms)
    [ RUN      ] test_join.test_complejidad_60000
    [       OK ] test_join.test_complejidad_60000 (40 ms)

Y este con comportamiento cuadrático:

    [ RUN      ] test_join.test_complejidad_10000
    [       OK ] test_join.test_complejidad_10000 (48 ms)
    [ RUN      ] test_join.test_complejidad_20000
    [       OK ] test_join.test_complejidad_20000 (618 ms)
    [ RUN      ] test_join.test_complejidad_30000
    [       OK ] test_join.test_complejidad_30000 (1354 ms)
    [ RUN      ] test_join.test_complejidad_40000
    [       OK ] test_join.test_complejidad_40000 (2425 ms)
    [ RUN      ] test_join.test_complejidad_50000
    [       OK ] test_join.test_complejidad_50000 (4019 ms)
    [ RUN      ] test_join.test_complejidad_60000
    [       OK ] test_join.test_complejidad_60000 (5722 ms)


### free_strv()

`free_strv()` libera la memoria asociada con un arreglo dinámico de cadenas dinámicas:

Si bien no es obligatorio probar la biblioteca, es muy recomendable hacer pruebas unitarias para comprobar el correcto
funcionamiento, en particular para los casos borde.
