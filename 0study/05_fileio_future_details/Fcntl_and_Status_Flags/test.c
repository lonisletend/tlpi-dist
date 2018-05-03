#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	fd = open("myfile",O_RDWR);
	if(fd == -1)
		errExit("open");
	char buf[100] = "asdgfasdgadg";
	if(write(fd,buf,5) == -1)
		errExit("write");
	if(close(fd) == -1)
		errExit("close");

	return 0;
}
