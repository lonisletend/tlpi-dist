
INCLUDE= -I ../../lib

exit_handlers:exit_handlers.o 
	gcc $(INCLUDE) exit_handlers.o error_functions.o -o exit_handlers
exit_handlers.o:exit_handlers.c error_functions.o
	gcc $(INCLUDE) exit_handlers.c error_functions.c -c

fork_whos_on_first:fork_whos_on_first.o 
	gcc $(INCLUDE) fork_whos_on_first.o error_functions.o get_num.o -o fork_whos_on_first
fork_whos_on_first.o:fork_whos_on_first.c error_functions.o
	gcc $(INCLUDE) fork_whos_on_first.c error_functions.c get_num.c -c

t_vfork:t_vfork.o 
	gcc $(INCLUDE) t_vfork.o error_functions.o -o t_vfork
t_vfork.o:t_vfork.c error_functions.o
	gcc $(INCLUDE) t_vfork.c error_functions.c -c

fork_file_shareing:fork_file_shareing.o 
	gcc $(INCLUDE) fork_file_shareing.o error_functions.o -o fork_file_shareing
fork_file_shareing.o:fork_file_shareing.c error_functions.o
	gcc $(INCLUDE) fork_file_shareing.c error_functions.c -c

fork:fork.o 
	gcc $(INCLUDE) fork.o error_functions.o -o fork
	fork.o:fork.c error_functions.o
		gcc $(INCLUDE) fork.c error_functions.c -c

clean:
	rm -rf