#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[]){
	int fd;

	fd = open(argv[1],O_WRONLY);
	if(fd != -1){
		printf("[PID %ld] File \"%s\" already exists.\n",(long)getpid(),argv[1]);
		close(fd);
	}else {
//			printf("errno = %d\n",errno);
		if(errno != ENOENT){
			errExit("open");
		}else {
			sleep(20);
			fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
			if(fd == -1)
				  errExit("open");
			printf("[PID %ld] Created file \"%s\" exclusively.\n",(long)getpid(),argv[1]);	
		}
	}

	return 0;
}
