/*  在文件特定偏移量处的I/O  */
/*    pread()  &  pwrite()   */
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[]){
	int fd;
	char buf[100];
	char buf2[100] = "testWrite()";
	buf2[11] = '\0';
	fd = open("myfile",O_RDWR | O_CREAT);
	if(fd == -1)
		errExit("open");
	if(lseek(fd,5,SEEK_SET) == -1)
		errExit("lseek1");
	if(pread(fd,buf,10,10) == -1)
		errExit("pread");
	buf[10] = '\0';
	puts(buf);
	if(pwrite(fd,buf2,11,10) == -1)
		errExit("pwrite");
	printf("%d\n",lseek(fd,0,SEEK_CUR));

	


	return 0;
}
	
