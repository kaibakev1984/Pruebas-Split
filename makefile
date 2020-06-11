CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
EXEC = pruebas

#  Con esta receta corremos el substr con pruebas automatizadas

sub: print_test_substr
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_substr/*.c
	./$(EXEC)

valsub: print_test_substr
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_substr/*.c
	valgrind $(VFLAGS) ./$(EXEC)

#  Con esta receta corremos el split con pruebas automatizadas
split: print_test_split
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_split/*.c 
	./$(EXEC)

psplit: split_visual
	gcc $(CFLAGS) -o $(EXEC) *.c *.h split_visual/*.c
	./$(EXEC)

# Con esta receta vemos lo que nos devuelve
# el split y el join. NO HACE PRUEBAS
svisual: strutil_visual
	gcc $(CFLAGS) -o $(EXEC) strutil_visual/*.c *.c *.h
	./$(EXEC)

clear: $(EXEC)
	rm -f $(EXEC)















	

