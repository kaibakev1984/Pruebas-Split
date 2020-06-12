CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
EXEC = pruebas

sub: print_test_substr
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_substr/*.c
	./$(EXEC)

valsub: print_test_substr
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_substr/*.c
	valgrind $(VFLAGS) ./$(EXEC)


split: print_test_split
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_split/*.c 
	./$(EXEC)
vsplit: print_test_split
	gcc $(CFLAGS) -o $(EXEC) *.c *.h print_test_split/*.c
	valgrind $(VFLAGS) ./$(EXEC)

psplit: split_visual
	gcc $(CFLAGS) -o $(EXEC) *.c *.h visual_split/*.c
	./$(EXEC)

pjoin: join_visual
	gcc $(CFLAGS) -o $(EXEC) *.c *.h visual_join/*.c
	./$(EXEC)


strutil: strutil_visual
	gcc $(CFLAGS) -o $(EXEC) visual_strutil/*.c *.c *.h
	./$(EXEC)

clear: $(EXEC)
	rm -f $(EXEC)















	

