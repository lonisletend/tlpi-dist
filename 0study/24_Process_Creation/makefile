
INCLUDE= -I ../../lib

fork:fork.o 
	gcc $(INCLUDE) fork.o error_functions.o -o fork
fork.o:fork.c error_functions.o
	gcc $(INCLUDE) fork.c error_functions.c -c

clean:
	rm -rf fork