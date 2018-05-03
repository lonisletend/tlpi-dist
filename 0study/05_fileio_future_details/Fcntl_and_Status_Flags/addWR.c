#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd,flags,accessMode,nflags;
	fd = open("myfile",O_RDONLY);
	if(fd == -1)
		errExit("open");
	flags = fcntl(fd,F_GETFL);
	accessMode = flags & O_ACCMODE;
	if(accessMode == O_WRONLY || accessMode == O_RDWR)
		printf("File is writable!\n");
	else{
		printf("File is not writable\n");
		printf("addWR...\n");
		flags |= O_RDWR;
		if(fcntl(fd,F_SETFL,flags) == -1)    //F_SETFL会忽略对读写模式的修改操作
			errExit("fcntl");
		nflags = fcntl(fd,F_GETFL);
		accessMode = nflags & O_ACCMODE;
		if(accessMode == O_WRONLY || accessMode == O_RDWR)
			printf("File is writable!\n");
		else
			printf("File is not writable!!\n");
	}
//	flags2 = fcntl(fd,F_GETFL);
//	printf("%d\n",flags2 & O_ACCMODE);
	char buffer[100] = "asdfsdf";
	if(write(fd,buffer,5) == -1)
		errExit("write");
	if(close(fd) == -1)
		errExit("close");
	return 0;
}
