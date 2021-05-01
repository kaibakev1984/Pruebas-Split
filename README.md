## Manejo de cadenas

Este proyecto pretende ser una guía para implementar los métodos definidos en el `strutil.h`. Si bien, se adjuntó la solución del mismo, la idea es que cada uno pueda implementar su propia versión.
**NOTA**: No se tiene en cuenta las pruebas de tiempo.

Para correr el proyecto:
  1. Implementar los métodos definidos en las firmas de `strutil.h`
  2. Tener instalado `gdb`, `build-essential` y `valgrind`

### Recetas definidas en el archivo makefile

``` cpp
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
GFLAGS = -tui
EXEC = pruebas 
OBJFILES = main.o strutil.o testing.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXEC)

all: $(EXEC)

run: all 
	./$(EXEC)

valgrind: all
	valgrind $(VFLAGS) ./pruebas

clear: $(OBJFILES)
	rm -f pruebas *.o

gdb: all 
	gdb -tui ./pruebas

```

### Pruebas definidas para substr()

``` cpp
substr("Hola mundo", 6)         → "Hola m"
substr("Algoritmos", 30)        → "Algoritmos"
substr("", 2)                   → ""

const char* ejemplo = "Ejemplo";
substr(ejemplo, 2)              → "Ej"
substr(ejemplo + 4, 2)          → "pl"
```

Complejidad algorítmica: se espera que la función tenga complejidad **O(k)**.


### Pruebas definidas para split()

``` cpp
split("abc,,def", ',')  →  ["abc", "", "def"]
split("abc,def,", ',')  →  ["abc", "def", ""]
split(",abc,def", ',')  →  ["", "abc", "def"]
split("abc", '\0')      →  ["abc"]

split("", ',')  →  [""]
split(",", ',') →  ["", ""]
```

Complejidad algorítmica: se espera que la función tenga complejidad **O(n)**, siendo **n** la longitud de la cadena inicial.


### Pruebas definidas para join()

Casos borde:
``` cpp
join([""], ',')             →  ""
join(["abc"], ',')          →  "abc"
join(["", ""], ',')         →  ","
join([], ',')               →  "" // Join de arreglo vacío, {NULL} en C.
join(["abc", "def"], '\0')  →  "abcdef"
```

Complejidad algorítmica: se espera que la función tenga complejidad **O(n)**, siendo **n** la longitud de la cadena resultante.

### free_strv()

`free_strv()` libera la memoria asociada con un arreglo dinámico de cadenas dinámicas
