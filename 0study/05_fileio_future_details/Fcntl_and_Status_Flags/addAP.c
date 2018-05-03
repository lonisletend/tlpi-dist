#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd,flags,accessMode,nflags;
//	char buf[100] = "1asdgfasdgdgdfhgfj";
//	char buf2[100] = "2lfgiafhhkjhcfsfl.b;gh;";
	fd = open("myfile2",O_RDWR);
	if(fd == -1)
		errExit("open");
	flags = fcntl(fd,F_GETFL);
	if(flags == -1)
		errExit("fcntl");
	if(write(fd,&argv[1][0],strlen(&argv[1][0])) == -1)
		errExit("write1");
	else
		printf("Write1 successful\n");
	nflags =flags | O_APPEND;
	if(fcntl(fd,F_SETFL,nflags) == -1)
		errExit("fcntl2");
	if(write(fd,&argv[2][0],strlen(&argv[2][0])) == -1)
		errExit("write2");
	else
		printf("Write2 successful\n");
	if(close(fd) == -1)
		errExit("close");


	return 0;
}
