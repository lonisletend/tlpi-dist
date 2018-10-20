
INCLUDE= -I ../../lib


fork_file_shareing:fork_file_shareing.o 
	gcc $(INCLUDE) fork_file_shareing.o error_functions.o -o fork_file_shareing
fork_file_shareing.o:fork_file_shareing.c error_functions.o
	gcc $(INCLUDE) fork_file_shareing.c error_functions.c -c

fork:fork.o 
	gcc $(INCLUDE) fork.o error_functions.o -o fork
	fork.o:fork.c error_functions.o
		gcc $(INCLUDE) fork.c error_functions.c -c

clean:
	rm -rf fork_file_shareing