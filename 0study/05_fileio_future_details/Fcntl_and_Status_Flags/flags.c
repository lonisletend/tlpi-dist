#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char* argv[]){
	int fd,flags,accessMode;
	fd = open("myfile",O_RDWR);
	if(fd == -1)
		errExit("open");
	flags = fcntl(fd, F_GETFL);
	if(flags == -1)
		errExit("flcntl");
	printf("flags = %x\n",flags);
	accessMode = flags & O_ACCMODE;
	printf("accessMode = %x\n",accessMode);
	printf("sizeof(O_ACCMODE) = %x\n",sizeof(O_ACCMODE));		
	printf("sizeof(flags) = %x\n",sizeof(flags));		
	return 0;
}
